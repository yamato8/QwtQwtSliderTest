#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qwt_counter.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_grid.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    xSpan = 1;

    plot = new QwtPlot;

    ui->verticalLayout_3->addWidget(plot);

    QwtPlotCurve *sinCurve = new QwtPlotCurve();
    sinCurve->setTitle( "sin curve" );
    sinCurve->setPen( Qt::blue, 1 ),sinCurve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QVector<double> sinX;//空のベクタ宣言
    QVector<double> sinY;//空のベクタ宣言

    for( int i = 0 ; i <= 5000 ; ++i ){
        double x = i/(1000-1.0);
        sinX.append( x );
        sinY.append( sin(2*M_PI*x) );
    }

    sinCurve->setSamples(sinX.data(), sinY.data(), sinX.count());
    sinCurve->attach( plot );

    // グリッドの設定
    QwtPlotGrid *grid = new QwtPlotGrid();
    //grid->enableXMin(true);//中間縦線の表示
    grid->attach( plot );


    plot->setAxisScale( QwtPlot::xBottom, 0.0, 1.0 );//目盛

    plot->setFixedHeight(250);

    //以下スライダー関係
    slider = new QwtSlider();
    connect(slider, SIGNAL(valueChanged(double)), this, SLOT(setValue(double)));

    slider->setOrientation(Qt::Horizontal);//横位置のスライダー
    ui->verticalLayout_3->addWidget(slider);

    slider->setScale(1,5);//ok

    //slider->setValue(3);

    plot->setFixedHeight(250);
    plot->setFixedWidth(400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setValue(double value)
{
    qDebug() << xSpan << value;
    plot->setAxisScale( QwtPlot::xBottom, value-xSpan, value );//目盛

    plot->replot();
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    qDebug() << "spin::"<< arg1 << slider->value();
    xSpan = arg1;

    plot->setAxisScale( QwtPlot::xBottom, 0, arg1 );//目盛
    plot->replot();

    //スライダーの位置を変更


    setValue(slider->value());
}
