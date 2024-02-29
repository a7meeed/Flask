#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include<QSqlDriver>
#include<QPluginLoader>
#include <QtTest>
#include <QtQuickTest>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
public:
    bool  forTestCheck_1;
    bool  forTestCheck_2;
    bool  forTestCheck_3;
    bool  forTestCheck_4;
    bool  forTestCheck_5;
    bool  forTestCheck_6;
private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;

};
#endif // MAINWINDOW_H
