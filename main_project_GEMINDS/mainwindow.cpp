#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("E:/QT Projects/trial_GEMINDS/data_base");
    if(DB_Connection.open()){
        qInfo()<<"database connected";
    }
    else
    {
        qInfo()<<"database not connected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    forTestCheck_1 = false;
    DB_Connection.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryCheckData(DB_Connection);
    QString  CasesSend ;
    bool checkValue;
    QueryCheckData.prepare("SELECT * FROM Table_1");
    if(QueryCheckData.exec())
        {
        while(QueryCheckData.next())
        {
            QueryCheckData.bindValue("cases",ui->lineEdit->text());
            CasesSend = QueryCheckData.value("cases").toString();
            if(CasesSend.toStdString() != ui->lineEdit->text().toStdString())
            {
                checkValue = true;
            }
            else
              {
                checkValue = false;
              }

    if(checkValue)
     {
    //add new case
    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO Table_1(cases,ID,value,result) VALUES(:cases,:ID,:value,:result)");
    QueryInsertData.bindValue(":cases",ui->lineEdit->text());
    QueryInsertData.bindValue(":ID",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":value",ui->lineEdit_3->text());
    QueryInsertData.bindValue(":result",ui->lineEdit_4->text());
    QueryInsertData.exec();
    QSqlDatabase::database().commit();
    DB_Connection.close();
    QMessageBox::information(this,tr("massege"),tr(" inserted  "));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
      }
    else{
        DB_Connection.close();
        QMessageBox::information(this,tr("check"),tr(" not valid "));
        ui->lineEdit->clear();
    }
}
    }
    forTestCheck_1 = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    forTestCheck_2 = false;
    QString user = ui->lineEdit_5->text();
    QString pass = ui->lineEdit_6->text();

    if (user == "ahmed" && pass == "123")
    {
        QMessageBox::information(this,tr("correction check"),tr(" Athourized "));
        DB_Connection.open();
        QSqlDatabase::database().transaction();
        QSqlQuery QueryLoadData(DB_Connection);
        QueryLoadData.prepare("SELECT * FROM Table_1");
        int NumberOfRowsToDisplay = 100;
        if(QueryLoadData.exec()){
            ui->tableWidget->setRowCount(NumberOfRowsToDisplay);
            int RowNumber = 0;
            while(QueryLoadData.next())
            {
                ui->tableWidget->setItem(RowNumber,0,new QTableWidgetItem(QString(QueryLoadData.value("cases").toString())));
                ui->tableWidget->setItem(RowNumber,1,new QTableWidgetItem(QString(QueryLoadData.value("value").toString())));
                ui->tableWidget->setItem(RowNumber,2,new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
                ui->tableWidget->setItem(RowNumber,3,new QTableWidgetItem(QString(QueryLoadData.value("result").toString())));
                RowNumber = RowNumber +1 ;
            }
        }
        QSqlDatabase::database().commit();
        DB_Connection.close();
    }
    else
    {
        QMessageBox::information(this,tr("correction check"),tr(" Not Athourized "));
        qInfo()<<"not athourized";
        ui->tableWidget->clear();
    }
    forTestCheck_2 = true;
}




void MainWindow::on_pushButton_3_clicked()
{
    forTestCheck_3 = false;
    DB_Connection.open();
    QSqlDatabase::database().transaction();
    //add new case
    QSqlQuery QueryUpdateData(DB_Connection);
    QueryUpdateData.prepare("UPDATE Table_1 SET ID=:ID,value=:value,result=:result WHERE cases=:cases");

    QueryUpdateData.bindValue(":ID",ui->lineEdit_2->text());
    QueryUpdateData.bindValue(":value",ui->lineEdit_3->text());
    QueryUpdateData.bindValue(":result",ui->lineEdit_4->text());
    QueryUpdateData.bindValue(":cases",ui->lineEdit->text());
    QueryUpdateData.exec();
    QSqlDatabase::database().commit();
    DB_Connection.close();
    QMessageBox::information(this,tr("massege"),tr(" Upadted  "));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    forTestCheck_3 = true;
}


void MainWindow::on_pushButton_4_clicked()
{
    forTestCheck_4 = false;
    QString user = ui->lineEdit_8->text();
    QString pass = ui->lineEdit_9->text();

    if (user == "ahmed" && pass == "123")
    {
        QMessageBox::information(this,tr(" check"),tr(" Athourized "));
        DB_Connection.open();
        QSqlDatabase::database().transaction();
        QSqlQuery QueryLoadData(DB_Connection);
        QueryLoadData.prepare("SELECT * FROM Table_1");
        int NumberOfRowsToDisplay = 1;
        if(QueryLoadData.exec()){
            ui->tableWidget->setRowCount(NumberOfRowsToDisplay);
            int RowNumber = 0;


            while(QueryLoadData.next())
            {
                QString ID = QString(QueryLoadData.value("ID").toString());
                if (ID.toStdString() == ui->lineEdit_7->text().toStdString()){
                    int RowNumber = 0;
                    /*first line on table*/
                    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString(QueryLoadData.value("cases").toString())));
                    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString(QueryLoadData.value("value").toString())));
                    ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
                    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString(QueryLoadData.value("result").toString())));
                    // wanted cases
                ui->tableWidget->setItem(RowNumber,0,new QTableWidgetItem(QString(QueryLoadData.value("cases").toString())));
                ui->tableWidget->setItem(RowNumber,1,new QTableWidgetItem(QString(QueryLoadData.value("value").toString())));
                ui->tableWidget->setItem(RowNumber,2,new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
                ui->tableWidget->setItem(RowNumber,3,new QTableWidgetItem(QString(QueryLoadData.value("result").toString())));

                 }
                 else {
                      RowNumber = RowNumber +1 ;
                 }
           }
        }
        QSqlDatabase::database().commit();
        DB_Connection.close();
    }
    else
    {
        QMessageBox::information(this,tr("correction check"),tr(" Not Athourized "));
        qInfo()<<"not athourized";
        ui->tableWidget->clear();
    }
    forTestCheck_4 = true;
}


void MainWindow::on_pushButton_5_clicked()
{
    forTestCheck_5 = false;
    QString user = ui->lineEdit_8->text();
    QString pass = ui->lineEdit_9->text();

    if (user == "ahmed" && pass == "123")
    {
    QMessageBox::information(this,tr(" check"),tr(" Athourized "));
    DB_Connection.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryDeletData(DB_Connection);
    QueryDeletData.prepare("DELETE FROM Table_1  WHERE ID=:ID");
    QueryDeletData.bindValue(":ID",ui->lineEdit_7->text());
    QueryDeletData.exec();
    QSqlDatabase::database().commit();
    DB_Connection.close();
    }
    else
    {
QMessageBox::information(this,tr(" check"),tr("Not Athourized "));
        ui->tableWidget->clear();
           DB_Connection.close();
    }
    forTestCheck_5 = true;
}


void MainWindow::on_pushButton_6_clicked()
{
    forTestCheck_6 = false;
    QString user = ui->lineEdit_8->text();
    QString pass = ui->lineEdit_9->text();

    if (user == "ahmed" && pass == "123")
    {
        QMessageBox::information(this,tr(" check"),tr(" Athourized "));
        DB_Connection.open();
        QSqlDatabase::database().transaction();
        QSqlQuery QueryLoadData(DB_Connection);
        QueryLoadData.prepare("SELECT * FROM Table_1");
        int NumberOfRowsToDisplay = 100;
        if(QueryLoadData.exec()){
            ui->tableWidget->setRowCount(NumberOfRowsToDisplay);
            int RowNumber = 0;
            while(QueryLoadData.next())
            {
                ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString(QueryLoadData.value("cases").toString())));
                ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString(QueryLoadData.value("result").toString())));
                // wanted cases
                ui->tableWidget->setItem(RowNumber,0,new QTableWidgetItem(QString(QueryLoadData.value("cases").toString())));
                ui->tableWidget->setItem(RowNumber,3,new QTableWidgetItem(QString(QueryLoadData.value("result").toString())));
                RowNumber = RowNumber +1 ;
            }
        }
        QSqlDatabase::database().commit();
        DB_Connection.close();
    }
    else
    {
        QMessageBox::information(this,tr("correction check"),tr(" Not Athourized "));
        qInfo()<<"not athourized";
        ui->tableWidget->clear();
    }
    forTestCheck_6 = true;
}

