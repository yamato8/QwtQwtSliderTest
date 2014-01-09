#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwt_plot.h>
#include <qwt_slider.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setValue(double value);
    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    QwtPlot *plot;
    QwtSlider *slider;
    int xSpan;
};

#endif // MAINWINDOW_H
