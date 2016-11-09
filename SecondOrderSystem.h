#ifndef _SECOND_ORDER_SYSTEM_
#define _SECOND_ORDER_SYSTEM_

#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

class SecondOrderSystem
{
public:
    enum second_order_type
    {
        OVERDAMPED = 0,
        CRITICALLY_DAMPED = 1,
        UNDERDAMPED = 2,
        UNDAMPED = 3,
        UNSTABLE = 5
    };

    bool set_poles(const complex<double> &s1_pole, const complex<double> &s2_pole);
    void set_gain(const double &gain) { this->gain = gain; }
    vector<double> get_step_response(const vector<double> &vector_time);
    enum second_order_type get_second_order_type() { return type; }

private:
    double gain;
    double natural_frecuency;
    double damping_ratio;
    complex<double> alpha_pole;
    complex<double> beta_pole;
    enum second_order_type type;
    bool negative_unitary_damping_ration_and_unstable;

    void set_natural_frecuency()
    {
        natural_frecuency = sqrt(real(alpha_pole * beta_pole));
        //cout << "Wn: " << natural_frecuency << " rad/seg" << endl;
    }

    void set_damping_ration()
    {
        damping_ratio = 0.0f;

        // Si la frec.natural es cero => división por cero!!. Se evita.
        if(natural_frecuency != 0.0f)
        {
            damping_ratio = -real(alpha_pole + beta_pole) / (2 * natural_frecuency);
        }

        //cout << "Zeta: " << damping_ratio << endl;
    }

    void set_second_order_type();
    std::vector<double> get_overdamped_underdamped_step_response(
            const vector<double> &vector_time);
    std::vector<double> get_critically_damped_step_response(
            const vector<double> &vector_time, double sign);
    std::vector<double> get_undamped_step_response(
            const vector<double> &vector_time);
};
#endif
