#include "moveabek.h"
#include <QDebug>

MoveAbeK::MoveAbeK()
{
    setGeometry(800,240,221,241);
    setPixmap(QPixmap("image/AbeK.png"));
    setScaledContents(true);

    qDebug()<<"MBK created";
    show();
    move();

    QTimer *timerAbeK = new QTimer;
    connect(timerAbeK, SIGNAL(timeout()), this, SLOT(move()));
    timerAbeK->start(10);
}

MoveAbeK::MoveAbeK(QWidget * parent) //: QLabel(parent)
{
    setParent(parent);
    setGeometry(1100,240,241,241);
    setPixmap(QPixmap("image/AbeK.png"));
    setScaledContents(true);

    qDebug()<<"MBK created";
    show();
    move();

    QTimer *timerAbeK = new QTimer;
    connect(timerAbeK, SIGNAL(timeout()), this, SLOT(move()));
    timerAbeK->start(10);
}

void MoveAbeK::move()
{
    //static int xvalue=0;
    //xvalue=xvalue+5;
    setGeometry(x()-3,240,241,241);
    if(x()<-220)
    {
        //timerAbeK->~QTimer();
    }

}

MoveAbeK::~MoveAbeK()
{


}
