#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QColor>
#include <QRect>
#include <QFontMetrics>
#include <cmath>
#include <vector>

using namespace std;

ArboreAVL arbore;
vector<int> v;
int t=-1;
std::vector<int> inserare;
std::vector<int> stergere;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number_of_points=30;
    generate_points(30);
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::generate_points(int number_of_points)
{
    for(int i=0;i<number_of_points;i++)//f(x)=x^{2}+x+5->f(i)
    {
        point p;
        p.x=i;
        p.y=i*i+i+5;
        points[i]=p;
    }
}



void MainWindow::afis(){
    QPainter paint(this);
    QFont font("Arial", 12, QFont::Bold);
    QColor color(255,0,0);
    QColor text(255,255,255);
    QPen pen;
    pen.setColor(color);
    paint.setPen(pen);
    paint.setFont(font);
    paint.setBrush(Qt::red);

    if(inserare.size()==0)
        return;
    ArboreAVL arbore;
    for(int i=0;i<inserare.size();i++)
        arbore.inserare(inserare[i]);
    if(t!=-1)
    {
     arbore.stergere(t);
        for(int j=0;j<inserare.size();j++)
     {
         if(inserare[j]==t)
                inserare.erase(inserare.begin()+j);
     }
        t=-1;
    }



    vector<ArboreAVL::NodAfis> a = arbore.afisareVect();

    for(auto i=0;i<a.size();i++)
    {
        QString b = QString::number(a[i].valoare);

        paint.drawEllipse(width()/pow(2,a[i].nivel)*(a[i].ordine*2-1)-20,a[i].nivel*100-20,40,40);

        //linie afis

        if(i!=0)
        {

            int x = width()/pow(2,a[i].nivel)*(a[i].ordine*2-1);
            int y = a[i].nivel*100;
            int x1 = width()/pow(2,a[i].t_n)*(a[i].t_o*2-1);
            int y1 = a[i].t_n*100;
            int r = 20;

            int dx = x1 - x;
            int dy = y1 - y;

            // norma
            double norm = sqrt(dx * dx + dy * dy);

            // scalare
            dx = int(dx * r / norm);
            dy = int(dy * r / norm);

            //paint.drawLine(width()/pow(2,a[i].nivel)*(a[i].ordine*2-1),a[i].nivel*100,width()/pow(2,a[i].t_n)*(a[i].t_o*2-1),a[i].t_n*100);
            paint.drawLine(x+dx,y+dy,x1 - dx,y1 - dy);

            pen.setColor(text);
            paint.setPen(pen);
        }

        //text afis
        pen.setColor(text);
        paint.setPen(pen);

        QFontMetrics metrics(font);
        QRect textRect = metrics.boundingRect(b);

        int textX = width()/pow(2,a[i].nivel)*(a[i].ordine*2-1) - textRect.width() / 2;
        int textY = a[i].nivel*100 + textRect.height() / 3;

        paint.drawText(textX, textY, b);
        pen.setColor(color);
        paint.setPen(pen);
    }
}



void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QColor color(0,255,0);
    QPen pen;
    pen.setColor(color);
    paint.setPen(pen);



    v.push_back(10);

    afis();

    paint.end();
}


void MainWindow::on_button_clicked()
{
    QPainter paint(this);
    QColor color(0,255,0);
    QPen pen;
    pen.setColor(color);
    paint.setPen(pen);
    QString text=ui->nrs->text();
    int z =text.toInt();

    t=z;
    repaint();
    afis();
    t=-1;

}


void MainWindow::on_pushButton_clicked()
{
    QPainter paint(this);
    QColor color(0,255,0);
    QPen pen;
    pen.setColor(color);
    paint.setPen(pen);
    QString text=ui->nr->text();
    int n =text.toInt();

    inserare.push_back(n);
    repaint();
    afis();

}

