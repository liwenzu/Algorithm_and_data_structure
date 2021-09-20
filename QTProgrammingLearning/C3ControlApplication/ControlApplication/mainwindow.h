#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QFontComboBox>
#include <QSpinBox>
#include <QTimeEdit>
#include <QDateEdit>
#include <QScrollBar>
#include <QRadioButton>
#include <QCheckBox>
#include <QListView>
#include <QStringListModel>
#include <QTreeView>
#include <QStandardItemModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QSystemTrayIcon>



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
    QPushButton *button;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPlainTextEdit *planTextEdit;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QSpinBox *spinBox;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QScrollBar *scrollBar;
    QRadioButton *radioM;
    QRadioButton *radioW;
    QCheckBox *checkBox01;
    QCheckBox *checkBox02;
    QCheckBox *checkBox03;
    QString str;
    QListView *listView;
    QStringListModel *model;
    QTreeView *treeView;
    QStandardItemModel *itemModel;
    QTableView *tableView;
    QHBoxLayout *hboxLayout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QGroupBox *box;
    QVBoxLayout *vbox;
    QTabWidget *tabWidget;
    QMenu *fileMenu, *editMenu, *helpMenu;
    QToolBar *fileToolBar, *editToolBar;
    QAction *newAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutQtAct;
    QSystemTrayIcon *myTrayIcon;
    QMenu *myMenu;
    QAction *restoreWinAction;
    QAction *quitAction;



private:
    void createMenu();


private slots:
    void txtButton();
    void radioChange();
    void checkChange();
    void newFile();
    void showNormal();

private:
    Ui::MainWindow *ui;
};

class tabA:public QWidget
{
    Q_OBJECT
public:
    tabA(QWidget *parent = 0);
};


class tabB:public QWidget
{
    Q_OBJECT
public:
    tabB(QWidget *parent = 0);
};



#endif // MAINWINDOW_H
