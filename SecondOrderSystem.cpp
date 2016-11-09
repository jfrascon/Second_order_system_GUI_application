#include "SecondOrderSystem.h"
#include <algorithm>
#include <cfloat>

// Obtener el tipo de sistema en función de zeta.
void SecondOrderSystem::set_second_order_type()
{
  negative_unitary_damping_ration_and_unstable = false;

  if (damping_ratio > 0.0f)
  {
    if (damping_ratio > 1.0f)
    {
      type = OVERDAMPED;
    }
    else if (damping_ratio > 0.0f && damping_ratio < 1.0f)
    {
      type = UNDERDAMPED;
    }
    else
    {
      type = CRITICALLY_DAMPED;
    }
  }
  else if (damping_ratio < 0.0f)
  {
      // OJito. Comparar números reales es peligroso por el error
      // de representación del equipo. Por eso se usa epsilón. Una constante
      // muy pequeña que se usa para hacer un intervalo pequeño alrededor
      // de -1,0f y así evitar que el error de precisión nos afecte.
    type = UNSTABLE;
    if ((damping_ratio > (-1.0f - FLT_EPSILON)) &&
        (damping_ratio < (-1.0f + FLT_EPSILON)))
    {
        // flag que sólo sirve para reconocer que tenermos zeta = -1 y sistema
        // inestable y en función de esto poder asignar el signo adecuado a la frencuencia
        // natural --> mirar tabla de transformada de laplaca inversa.
      negative_unitary_damping_ration_and_unstable = true;
    }
  }
  else
  {
    type = UNDAMPED;
  }
}

// Fija los polos de la función y calcula la frec.nat y la zeta.
bool SecondOrderSystem::set_poles(const complex<double> &s1_pole,
                                  const complex<double> &s2_pole)
{
  bool flag_correct_type = false;
  double imag_s1 = imag(s1_pole);
  double imag_s2 = imag(s2_pole);
  double real_s1 = real(s1_pole);
  double real_s2 = real(s2_pole);

  double imag_a = 0.0f;
  double imag_b = 0.0f;
  double real_a = 0.0f;
  double real_b = 0.0f;

  // cout << "s1: (" << real_s1 << ", " << imag_s1 << "i )" << endl;
  // cout << "s2: (" << real_s2 << ", " << imag_s2 << "i )" << endl;

  // Los polos deben tener un parte imaginaria de igual magnitud y signo
  // distinto.
  // Esto aplica aún cuando la magnitud sea nula. Es decir, no puede existir
  // un polo con parte real nula y otro con parte real no nula.
  if (imag_s1 != -imag_s2)
    return flag_correct_type;

  // Si ambos polos tiene una parte imaginaria con la misma magnitud y distinto
  // signo y una de ellas es distinta de 0, entonces la otra es distinta de 0
  // necesariamente.
  if (imag_s1 != 0.0f)
  {
    // La parte real de aquellos polos que tienen parte imaginaria deben ser
    // igual en magnitud y signo, es decir, idénticas.
    if (real_s1 != real_s2)
      return flag_correct_type;

    real_a = real_b = real_s1;
    imag_a = max(imag_s1, imag_s2);
    imag_b = min(imag_s1, imag_s2);
  }
  else  // Ambas partes imaginarias son nulas.
  {
    // La parte real de aquellos polos que no tienen parte imaginaria deben
    // tener igual signo, es decir, ambos positivos o ambos negativos.
    // La magnitud puede ser igual o diferente.
    // Si la magnitud de alpha y beta es dinstinta debe cumplir una relacion u
    // otra dependiendo de si estas son positivas o negativas.
    double temp_max = max(real_s1, real_s2);
    double temp_min = min(real_s1, real_s2);

    if (temp_max > 0.0f && temp_min < 0.0f)
      return flag_correct_type;

    // Solo cuando se ha comprobado que los valores de todas las partes reales e
    // imaginarias son correctos se asignan estos valores a las variables que se
    // usarán para crear los polos.
    real_a = temp_max;
    real_b = temp_min;
    imag_a = imag_b = 0.0f;
  }

  alpha_pole = complex<double>(real_a, imag_a);
  beta_pole = complex<double>(real_b, imag_b);

  // cout << "alpha pole: (" << real_a << ", " << imag_a << "i )" << endl;
  // cout << "beta  pole: (" << real_b << ", " << imag_b << "i )" << endl;

  set_natural_frecuency();
  set_damping_ration();
  set_second_order_type();

  return true;
}

// Dependiendo de la zeta que se tenga se aplica una fórmula u otra.
// Todas las fórmulas derivan de la misma. La fórmula general está muy bien
// pero presenta una indeterminacion en zeta = (+-1)^2 -> por eso se usa la
// fórmula derivada para este caso.
// Y para el caso undamped, usar la formula que tiene sólo un coseno
// permite hacer menos cálculos.
std::vector<double> SecondOrderSystem::get_step_response(
    const vector<double> &vector_time)
{

  if (type == SecondOrderSystem::CRITICALLY_DAMPED)
  {
    // cout << "CRIT.DAMPED +1" << endl;
    return get_critically_damped_step_response(vector_time, +1.0f);
  }
  else if (negative_unitary_damping_ration_and_unstable)
  {
    // cout << "CRIT.DAMPED -1" << endl;
    return get_critically_damped_step_response(vector_time, -1.0f);
  }
  else if (type == SecondOrderSystem::UNDAMPED)
  {
    // cout << "UNDAMPED" << endl;
    return get_undamped_step_response(vector_time);
  }
  else
  {
    // cout << "OVERDAMPED AND UNDERDAMPED" << endl;
    return get_overdamped_underdamped_step_response(vector_time);
  }
}

// FÓRMULAS DEL PDF
std::vector<double> SecondOrderSystem::get_overdamped_underdamped_step_response(
    const vector<double> &vector_time)
{
  vector<double> step_response;

  if (vector_time.empty())
    return step_response;

  int size = vector_time.size();
  step_response.reserve(size);

//  double minu_real = 0.0f;
//  double minu_imag = 0.0f;
//  double sust_real = 0.0f;
//  double sust_imag = 0.0f;

  double factor = natural_frecuency / 2.0f;
  complex<double> cfactor;

  for (int i = 0; i < size; i++)
  {
    // cout << "t: " << vector_time[i] << endl;
    // complex<double> minu = (exp(alpha_pole * vector_time[i]) / alpha_pole);
    // complex<double> sust = (exp(beta_pole * vector_time[i]) / beta_pole);
    // cout << "minu_real:" << real(minu) << endl;
    // cout << "minu_imag: " << imag(minu) << endl;
    // cout << "sust_real: " << real(sust) << endl;
    // cout << "sust_imag: " << imag(sust) << endl;

    if (type == SecondOrderSystem::OVERDAMPED || damping_ratio < -1.0f)
    {
      cfactor = complex<double>(factor / sqrt(pow(damping_ratio, 2) - 1), 0);
    }
    else  // UNDERDAMPED and UNSTABLE with damping_ratio > -1.0f and
          // damping_ratio < 0.0f
    {
        // Ojo con esto --> wn/2 = 1/2/wn
      cfactor =
          pow(complex<double>(0.0f, sqrt(1 - pow(damping_ratio, 2)) / factor),
              -1.0f);
    }

    // cout << "cfacto_real: " << real(cfactor) << endl;
    // cout << "cfactor_imag: " << imag(cfactor) << endl;

    step_response.push_back(
        gain *
        (1 + real(cfactor * ((exp(alpha_pole * vector_time[i]) / alpha_pole) -
                             (exp(beta_pole * vector_time[i]) / beta_pole)))));
    // cout << "step response value: " << step_response[i] << endl;
    // cout << endl;
  }

  return step_response;
}

// FÓRMULAS
std::vector<double> SecondOrderSystem::get_critically_damped_step_response(const vector<double> &vector_time, double sign)
{
  vector<double> step_response;

  if (vector_time.empty())
    return step_response;

  int size = vector_time.size();
  step_response.reserve(size);

  sign = (sign >= 0 ? 1 : -1);

  double phase = 0.0f;
  double frec = sign * natural_frecuency;

  // cout << "frec with sign: " << frec << endl;

  for (int i = 0; i < size; i++)
  {
    // cout << "t: " << vector_time[i] << endl;
    phase = frec * vector_time[i];
    // cout << "phase: " << phase << endl;
    step_response.push_back(gain * (1 - (exp(-phase) * (1 + phase))));
    // cout << "step response value: " << step_response[i] << endl;
    // cout << endl;
  }

  return step_response;
}

// FÓRMULAS
std::vector<double> SecondOrderSystem::get_undamped_step_response(
    const vector<double> &vector_time)
{
  vector<double> step_response;

  if (vector_time.empty())
    return step_response;

  int size = vector_time.size();
  step_response.reserve(size);

  for (int i = 0; i < size; i++)
  {
    // cout << "t: " << vector_time[i] << endl;
    step_response.push_back(gain *
                            (1 - cos(natural_frecuency * vector_time[i])));
    // cout << "step response value: " << step_response[i] << endl;
    // cout << endl;
  }

  return step_response;
}


// Descomentar y compilar para hacer pruebas:
// Línea para compilar: g++ -o 2otf --std=c++11 -W SecondOrderSystem.cpp

// Descomentar caso a caso!
// int main()
// {
//   SecondOrderSystem tf;
//   tf.set_gain(1.0f);
//   // TEST: Discomment one at a time
//   // if (!tf.set_poles(complex<double>(-5, 0), complex<double>(-1, 0)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(-5, 0), complex<double>(-5, 0)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(-5, 7), complex<double>(-5, -7)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(0, -9), complex<double>(0, 9)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(7, -3), complex<double>(7, 3)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(3, 0), complex<double>(3, 0)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(5, 0), complex<double>(1, 0)))
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(-1, 0), complex<double>(5, 0)))  //*
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(0, -4), complex<double>(0, 5)))  //*
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(3, -5), complex<double>(-3, 5)))  //*
//   //   cout << "MAL" << endl;
//   // if (!tf.set_poles(complex<double>(3, 5), complex<double>(-3, -5)))  //*
//   //   cout << "MAL" << endl;
//
//   int num_val = 201;
//   double initial_time = 0.0f;
//   double final_time = 10.0f;
//   double increment = (final_time - initial_time) / (num_val - 1);
//   vector<double> vtime;
//
//   vtime.reserve(num_val);
//   vtime.push_back(0.0f);
//
//   for (int i = 1; i < num_val; i++)
//   {
//     vtime.push_back(vtime[i - 1] + increment);
//   }
//
//   // cout << "time vector's size: " << vtime.size() << endl;
//   // cout << "time vector's capacity: " << vtime.capacity() << endl;
//
//   vector<double> step_response = tf.get_step_response(vtime);
// }
