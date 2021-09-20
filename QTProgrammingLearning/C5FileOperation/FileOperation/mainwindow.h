#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QSettings>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
//    QLineEdit *edit;
//    QPushButton *button;
//    QLineEdit *content;

//    QPushButton *browseBt;
//    QPushButton *saveBt;
//    QTextEdit *edit;
//    QTextEdit *content;
//    QLineEdit *filePath;
//    QPushButton *browseBt;
 //   QPushButton *deleteBt;
//    QLineEdit *newName;
//    QGridLayout *gLayout;
//    QWidget *widget;
//    QLabel *filePathL;
//    QLineEdit *filePath;
//    QLabel *nodeL;
//    QLineEdit *nodeEdit;
//    QLabel *keyL;
//    QLineEdit *keyEdit;
//    QLabel *valL;
//    QLineEdit *valEdit;
//    QPushButton *writeBt;
//    QSettings *writeIni;

//    QGridLayout *gLayout;
//    QWidget *widget;
//    QLabel *filePathL;
//    QLineEdit *filePath;
//    QLabel *nodeL;
//    QLineEdit *nodeEdit;
//    QLabel *keyL;
//    QLineEdit *keyEdit;
//    QLabel *valL;
//    QLineEdit *valEdit;
//    QPushButton *readBt;
//    QSettings *readIni;
    QLabel *explainL;
    QPushButton *createBt;
    QLabel *resultL;
    QPushButton *readBt;





private slots:
//    void createFolder();
//    void createFile();

//    void saveFile();
//    void browseFile();
//    void browseFile();
//    void deleteFile();
//    void saveFile();
//    void writeFile();
//    void readFile();
    void createFile();
    void readNode();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
