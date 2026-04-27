#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyHeaderView.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}



MainWindow::~MainWindow()
{
    delete ui;
}
