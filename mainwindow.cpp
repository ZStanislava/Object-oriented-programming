#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include <iostream>
#include <sstream>
using namespace std;
static TMatrix<int> first, second;
static int Scalar;
static TVector<int> v1, v2;
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


void MainWindow::ReadMatrix1()
{
    int tmp  = ui->lineEdit->text().toInt();
    cout  << " m size is " << tmp << endl;
    TMatrix<int> m(tmp);
    stringstream ss(ui->textEdit->toPlainText().toStdString());
    ss >> m;
    cout << m;
    first = m;
}

void MainWindow::ReadMatrix2()
{
    int tmp  = ui->lineEdit_2->text().toInt();
    cout  << " m size is " << tmp << endl;
    TMatrix<int> m(tmp);
    stringstream ss(ui->textEdit_2->toPlainText().toStdString());
    ss >> m;
    cout << m;
    second = m;
}

void MainWindow::ReadVector1()
{
    int tmp  = ui->lineEdit_6->text().toInt();
    cout  << " v1 size is " << tmp << endl;
    TVector<int> v(tmp);
    stringstream ss(ui->lineEdit_4->text().toStdString());
    ss >> v;
    cout << v;
    v1 = v;
}

void MainWindow::ReadVector2()
{
    int tmp  = ui->lineEdit_7->text().toInt();
    cout  << " v2 size is " << tmp << endl;
    TVector<int> v(tmp);
    stringstream ss(ui->lineEdit_5->text().toStdString());
    ss >> v;
    cout << v;
    v2 = v;
}



void MainWindow::on_pushButton_3_clicked()
{
    ReadMatrix1();
    ReadMatrix2();
    stringstream ss;
    ss << first + second;
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_4_clicked()
{
    ReadMatrix1();
    ReadMatrix2();
    stringstream ss;
    ss << first - second;
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_5_clicked()
{
    ReadMatrix1();
    ReadMatrix2();
    stringstream ss;
    ss << first * second;
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_6_clicked()
{
    ReadMatrix1();
    Scalar = ui->lineEdit_3->text().toInt();
    stringstream ss;
    ss << first * Scalar;
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_7_clicked()
{
    ReadMatrix1();
    Scalar = ui->lineEdit_3->text().toInt();
    stringstream ss;
    ss << first + Scalar;
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_8_clicked()
{
    ReadMatrix1();
    Scalar = ui->lineEdit_3->text().toInt();
    stringstream ss;
    ss << first - Scalar;
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_10_clicked()
{
    ReadVector1();
    ReadVector2();
    stringstream ss;
    TVector<int> tmp = v1 + v2;
    cout <<"v1 + v2 = " << endl;
    cout << tmp.GetSize() << endl;
    cout << tmp << endl;
    ss << tmp;
    cout << ss.str();
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_12_clicked()
{
    ReadVector1();
    ReadVector2();
    stringstream ss;
    ss << v1 - v2;
    cout << ss.str();
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_13_clicked()
{
    ReadVector1();
    ReadVector2();
    stringstream ss;
    ss << v1 * v2;
    cout << ss.str();
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_14_clicked()
{
    ReadVector1();
    ReadVector2();
    stringstream ss;
    ss << vecMult(v1, v2);
    cout << ss.str();
    ui->textEdit_3->setText(ss.str().c_str());
}

void MainWindow::on_pushButton_11_clicked()
{
    ReadVector1();
    Scalar = ui->lineEdit_3->text().toInt();
    stringstream ss;
    ss << v1 * Scalar;
    cout << ss.str();
    ui->textEdit_3->setText(ss.str().c_str());
}
