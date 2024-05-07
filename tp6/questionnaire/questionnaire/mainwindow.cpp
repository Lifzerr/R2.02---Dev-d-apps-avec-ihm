#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connexions
    QObject::connect(ui->startBtn, SIGNAL(clicked()), this, SLOT(demandeDemarrage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demandeDemarrage()
{
    _dlg = new Dialog();
    _dlg->show();
}
