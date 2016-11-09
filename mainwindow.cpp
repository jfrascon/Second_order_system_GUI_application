#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), value_quantity(201), initial_time(0.0f), final_time(10.0f), amplitude_coef(1.0f)
{
    ui->setupUi(this);
    ui->le_step_amp->setText(QString("5.0"));

    // Objeto que sólo permite que en la cajita de la parte real de los polos solo se puedan
    // escribir números, no letras. Estos números van entre -1000 y 1000 (por que sí)
    QDoubleValidator* validator = new QDoubleValidator(-1000.0, 1000.0, 3, ui->le_p1_r);
    validator->setNotation(QDoubleValidator::StandardNotation);

    ui->le_p1_r->setValidator(validator);
    ui->le_p1_i->setValidator(validator);
    ui->le_p2_r->setValidator(validator);
    ui->le_p2_i->setValidator(validator);

    // Valores iniciales.
    ui->le_p1_r->setText(QString("0.0"));
    ui->le_p1_i->setText(QString("0.0"));
    ui->le_p2_r->setText(QString("0.0"));
    ui->le_p2_i->setText(QString("0.0"));

    // Incremento entre un valor de tiempo y el siguiente.
    time_increment = (final_time - initial_time) / (value_quantity - 1);

    // Hueco para los vectores.
    time_vector.reserve(value_quantity);
    step.reserve(value_quantity);

    time_vector.push_back(0.0f);
    step.push_back(1.0f);

    // Rellenar el escalón y el vector de tiempo.
    for (int i = 1; i < value_quantity; i++)
    {
        time_vector.push_back(time_vector[i - 1] + time_increment);
        step.push_back(1.0f);

    }

    // COnfigurar como serán los gráficos. 2 gráficos. el escalón en azul, la respuesta en rojo.
    ui->qcplot->addGraph();
    ui->qcplot->addGraph();
    ui->qcplot->graph(1)->setPen(QPen(QColor(255, 0, 0)));
    ui->qcplot->setBackground(QBrush(QColor(239, 239, 239, 255)));
    ui->qcplot->xAxis->setLabel("t");
    ui->qcplot->yAxis->setLabel("y(t)");
    ui->qcplot->xAxis->setRange(0, time_vector.back());
    ui->qcplot->yAxis->setRange(0, ui->slider_step_amp->maximum()/10.0f);


}

// Gestiona el cambio de valor en el slider. Es una función slot.
void MainWindow::on_slider_step_amp_valueChanged()
{
    //qDebug() << ui->slider_step_amp->value();
    ui->le_step_amp->setText(QString::number(ui->slider_step_amp->value()/10.0f));
}

// Al pulsar ejecutar empiza la fiesta.
void MainWindow::on_b_execute_clicked()
{

    // Asignar polos a la función de transferencia de orden 2.
    if (!second_order_system.set_poles(complex<float>( ui->le_p1_r->text().toDouble(), ui->le_p1_i->text().toDouble()), complex<float>(ui->le_p2_r->text().toDouble(), ui->le_p2_i->text().toDouble())))
    {
        QMessageBox::critical(this, tr("ERROR"), tr("Incorrect pair of poles"));
    }
    else
    {
        // Coeificiente por el que hay que multiplicar el escalón para pintarlo de la altura deseada.
        amplitude_coef = (ui->slider_step_amp->value()/10.0f) / step[0];
        //qDebug() << "s: " << step[1];
        //qDebug() << "a: " << amplitude_coef;
        //qDebug() << "s: " << step[1] * amplitude_coef;
        //qDebug() << "";

        // POner el escalón con la altura adecuada.
        for(double &value : step) {  value *= amplitude_coef; }

        ui->qcplot->graph(0)->setData(time_vector, step);

        // Fijar ganancia K y cálculo de la respuesta en frecuencia.
        second_order_system.set_gain(ui->le_step_amp->text().toDouble());
        QVector<double> step_response = QVector<double>::fromStdVector(second_order_system.get_step_response(time_vector.toStdVector()));

        ui->qcplot->graph(1)->setData(time_vector, step_response);

        // Obtener el tipo de sistema y mostrarlo.
        switch(second_order_system.get_second_order_type())
        {
        case SecondOrderSystem::CRITICALLY_DAMPED:
        {
            ui->le_type->setText("Crit.damped");
            break;
        }
        case SecondOrderSystem::OVERDAMPED:
        {
            ui->le_type->setText("Overdamped");
            break;
        }
        case SecondOrderSystem::UNDERDAMPED:
        {
            ui->le_type->setText("Underdamped");
            break;
        }
        case SecondOrderSystem::UNDAMPED:
        {
            ui->le_type->setText("Undamped");
            break;
        }
        default:
        {
            ui->le_type->setText("Unstable");
        }
        }

        // Escalar ejes y repintar.
        ui->qcplot->graph(1)->rescaleAxes();
        ui->qcplot->replot();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
