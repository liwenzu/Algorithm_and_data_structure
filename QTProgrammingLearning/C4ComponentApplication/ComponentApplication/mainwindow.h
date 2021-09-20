#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QWidget>
#include <QProgressBar>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showTime();
    void setData();
    virtual void accept();
    void showFiles();
    void editText();
    void startBar();
    void timerTime();

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCalendarWidget *calendarWidget;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *usrLabel;
    QLabel *pwdLabel;
    QGridLayout *gridlayout;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QVBoxLayout *vboxLayout;
    QLineEdit *filename;
    QPushButton *button;
    QProgressBar *bar;
    QTimer *timer;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
