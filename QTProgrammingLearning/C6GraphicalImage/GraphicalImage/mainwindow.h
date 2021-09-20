#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QMovie>
#include <QImage>
#include <QPushButton>
#include <QMatrix>
#include <QGraphicsBlurEffect>
#include <QGraphicsColorizeEffect>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsOpacityEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
//    void paintEvent(QPaintEvent *);

private:
    QGraphicsScene *scence;
    QGraphicsView *view;
    QLabel *label;
    QMovie *movie;
    QImage *img;
    QPushButton *button;
    QPushButton *hBt;
    QPushButton *vBt;
    QPushButton *angleBt;
    QPushButton *bigBt;
    QPushButton *smallBt;

private slots:
//    void moveImg();
    void hShow();
    void vShow();
    void angleShow();
    void bShow();
    void sShow();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
