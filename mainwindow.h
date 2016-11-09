#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SecondOrderSystem.h"
#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SecondOrderSystem second_order_system;
    int value_quantity;
    float initial_time;
    float final_time;
    float time_increment;
    QVector<double> time_vector;
    QVector<double> step;
    float amplitude_coef;


private slots:
    void on_slider_step_amp_valueChanged();
    void on_b_execute_clicked();
};

#endif // MAINWINDOW_H
