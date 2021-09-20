#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//1.1 绘制文字
//    QGraphicsScene *scence = new QGraphicsScene;
//    scence->setForegroundBrush(QColor(0,255,255,127));
//    QFont font("宋体",100);
//    scence->addSimpleText("图形图像", font);
//    QGraphicsView *view = new QGraphicsView(scence);
//    this->setCentralWidget(view);

//1.2 绘制线条
//    scence = new QGraphicsScene;

//    QPen pen;
//    pen.setStyle(Qt::DashDotLine);
//    pen.setWidth(12);
//    pen.setBrush(Qt::red);
//    pen.setCapStyle(Qt::RoundCap);
//    pen.setJoinStyle(Qt::RoundJoin);

//    scence->addLine(30, 30, 400, 30, pen);

//    view = new QGraphicsView(scence);

//    this->setCentralWidget(view);


//1.3 绘制椭圆
//    scence = new QGraphicsScene;

//    scence->addEllipse(50,50,100,220);

//    view = new QGraphicsView(scence);
//    this->setCentralWidget(view);

//1.4 显示静态图片

//1.5 显示动态图像
//    label = new QLabel(this);
//    label->setGeometry(QRect(150, 150, 188, 151));

//    movie = new QMovie(":/new/prefix1/ima");
//    QTimer::singleShot(5*1000, label, SLOT(close()));
//    label->setMovie(movie);
//    movie->start();

//1.6 图片水平移动
//    label = new QLabel(this);
//    label->setGeometry(QRect(50, 50, 75, 77));

//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));

//    button = new QPushButton(this);
//    button->setGeometry(QRect(50, 150, 80, 25));
//    button->setText("移动");
//    connect(button, SIGNAL(clicked()), this, SLOT(moveImg()));

//1.7 图片翻转
//    label = new QLabel(this);
//    label->setGeometry(QRect(160, 50, 175, 177));

//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));

//    hBt = new QPushButton(this);
//    hBt->setGeometry(QRect(50, 200, 80, 25));
//    hBt->setText("水平翻转");
//    connect(hBt, SIGNAL(clicked()), this, SLOT(hShow()));


//    vBt = new QPushButton(this);
//    vBt->setGeometry(QRect(160, 200, 80, 25));
//    vBt->setText("垂直操作");
//    connect(vBt, SIGNAL(clicked()), this, SLOT(vShow()));


//    angleBt = new QPushButton(this);
//    angleBt->setGeometry(QRect(270, 200, 80, 25));
//    angleBt->setText("角度操作");
//    connect(angleBt, SIGNAL(clicked()), this, SLOT(angleShow()));

//1.8 图片缩放
//    label = new QLabel(this);
//    label->setGeometry(QRect(160, 50, 250, 120));

//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));

//    bigBt = new QPushButton(this);
//    bigBt->setGeometry(QRect(50, 200, 80, 25));
//    bigBt->setText("放大");
//    connect(bigBt, SIGNAL(clicked()), this, SLOT(bShow()));

//    smallBt = new QPushButton(this);
//    smallBt->setGeometry(QRect(460, 200, 80, 25));
//    smallBt->setText("缩小");
//    connect(smallBt, SIGNAL(clicked()), this, SLOT(sShow()));

//1.9 图片中加文字
//    label = new QLabel(this);
//    label->setGeometry(QRect(50, 50, 300, 25));
//    label->setText("图片已经生成，保存在项目文件中【text.jpg】。");

//    QImage image = QPixmap(":/new/prefix1/ima").toImage();
//    QPainter painter(&image);
//    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

//    QPen pen = painter.pen();
//    pen.setColor(Qt::red);
//    QFont font = painter.font();
//    font.setBold(true);//加粗
//    font.setPixelSize(50);//改变字体大小
//    painter.setPen(pen);
//    painter.setFont(font);
//    //将文字绘制在图片中心位置
//    painter.drawText(image.rect(),Qt::AlignCenter,"你好，朋友。");
//    int n = 100;
//    //保存图片
//    image.save("text.jpg","JPG",n);

//1.10 图像扭曲


//1.11 模糊效果
//    label = new QLabel(this);
//    label->setGeometry(QRect(50,50,718,480));
//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));

//    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
//    effect->setBlurRadius(5);
//    label->setGraphicsEffect(effect);


//1.12 着色效果
//    label = new QLabel(this);
//    label->setGeometry(QRect(50,50,718,480));
//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));

//    QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(this);
//    effect->setColor(QColor(0, 0, 192));
//    label->setGraphicsEffect(effect);

//1.13 阴影效果
//    label = new QLabel(this);
//    label->setGeometry(QRect(50,50,718,480));
//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));
//    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
//    //设定阴影
//    effect->setOffset(8,8);
//    label->setGraphicsEffect(effect);

//1.14 透明效果
//    label = new QLabel(this);
//    label->setGeometry(QRect(50,50,718,480));
//    img = new QImage;
//    img->load(":/new/prefix1/ima");
//    label->setPixmap(QPixmap::fromImage(*img));

//    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
//    //设定透明值
//    effect->setOpacity(0.5);
//    label->setGraphicsEffect(effect);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::paintEvent(QPaintEvent *)
//{
//    QPixmap image(":/new/prefix1/ima");
//    QPainter painter(this);
//    painter.drawPixmap(20,20,200,257,image);
//}

////图像扭曲
//void MainWindow::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    QPixmap pix;

//    pix.load(":/new/prefix1/ima");
//    painter.drawPixmap(10,50,250,160,pix);
//    painter.shear(0.5, 0);
//    painter.drawPixmap(200,150,183,160,pix);
//}

//int i = 50;

//void MainWindow::moveImg()
//{
//    label->move(i, 90);
//    i+=30;
//}


void MainWindow::hShow()
{
    *img = img->mirrored(true, false);
    label->setPixmap(QPixmap::fromImage(*img));
}


void MainWindow::vShow()
{
    //垂直翻转
    *img = img->mirrored(false,true);
    //显示图片
    label->setPixmap(QPixmap::fromImage(*img));
}


void MainWindow::angleShow()
{
    QMatrix matrix;
    //88度角
    matrix.rotate(88);
    *img = img->transformed(matrix);
    label->setPixmap(QPixmap::fromImage(*img));
}


void MainWindow::bShow()
{
    *img = img->scaled(200,275,Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(*img));

}

void MainWindow::sShow()
{
    *img = img->scaled(60,60,Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(*img));
}


















