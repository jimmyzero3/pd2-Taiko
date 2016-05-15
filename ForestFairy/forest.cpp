#include "forest.h"
#include "ui_forest.h"
#include <QSound>
#include <QMovie>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QSoundEffect>
#include <QUrl>
#include <QMessageBox>
#include <QKeyEvent>
#include <QProcess>
#include <thread>
#include <QTimer>
#include <stdlib.h>
#include <QDebug>


Forest::Forest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Forest)
{
    ui->setupUi(this);
    this->setFixedSize(1024,683);
    count=0;

    ui->lcdNumber->setVisible(false);
    ui->MoveAbe->setVisible(false);
    ui->LCDScore->setVisible(false);
    ui->Your->setVisible(false);
    ui->Score->setVisible(false);
    ui->EndHint->setVisible(false);
    ui->malesymbol->setVisible(false);
    ui->LCDScore->display(score);


    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->AbeIntro->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");

    a->setDuration(5000);
    a->setStartValue(1);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);

    QPixmap BlackCurtain("image/Black.png");
    ui->label_2->setPixmap(BlackCurtain);
    ui->label_3->setPixmap(BlackCurtain);

    QPixmap Intro("image/Abe.png");
    ui->AbeIntro->setPixmap(Intro);

    QPixmap JAbe("image/Abe Chair.png");
    ui->MoveAbe->setPixmap(JAbe);

    QPixmap bkgnd("image/PhotoFunia-1462258166.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QMovie *movie = new QMovie("image/output_BjZjfi.gif");
        ui->label->setMovie(movie);
        movie->start();






}

Forest::~Forest()
{
    delete ui;
}



void Forest::keyPressEvent(QKeyEvent *event)
{

    static QPixmap MaleSymbolBright("image/Male_Symbol_bright.png");

    if (event->key()==Qt::Key_Return && count==0)
    {
        count++;
        ui->label->clear();
        ui->AbeIntro->clear();
        QMovie *movie2 = new QMovie("image/output_Fast.gif");
            ui->label->setMovie(movie2);
            movie2->start();
        QSound::play("image/nc17278.wav");


        QPixmap NationalDefenceCloth("image/Instruction.png");
        ui->AbeIntro->setPixmap(NationalDefenceCloth);

        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->AbeIntro->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");

        a->setDuration(3500);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);

        QTimer::singleShot(3500, this, SLOT(Game()));


    }

    if(event->key()==Qt::Key_F2 && count>0 && IfStarted==true && IfResulted==true)
    {
        IfStarted=false;
        ui->MoveAbe->setVisible(false);


        if(IfResulted==false)
        {
        timer2->~QTimer();
        //timer3->~QTimer();
        timer4->~QTimer();
        }

        if(IfResulted==true)
        {IfResulted=false;}

        QPixmap NationalDefenceCloth("image/Instruction.png");
        ui->AbeIntro->setPixmap(NationalDefenceCloth);

        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->AbeIntro->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");

        a->setDuration(1000);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);

        QTimer::singleShot(1000, this, SLOT(Reset()));
        QTimer::singleShot(1000, this, SLOT(Game()));



    }


    if(event->key()==Qt::Key_J && count>0 && IfResulted==false)
    {

        if(J1out==true)
        {
            if(  AbeJ1->x() >= ui->malesymbol->x()-50 && AbeJ1->x() <= ui->malesymbol->x()+100)
            {
                AbeJ1->~QLabel();
                AbeJ1T->~QTimer();
                J1out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }


        if(J2out==true)
        {
            if(  AbeJ2->x() >= ui->malesymbol->x()-50 && AbeJ2->x() <= ui->malesymbol->x()+100)
            {
                AbeJ2->~QLabel();
                AbeJ2T->~QTimer();
                J2out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }


        if(J3out==true)
        {
            if(  AbeJ3->x() >= ui->malesymbol->x()-50 && AbeJ3->x() <= ui->malesymbol->x()+100)
            {
                AbeJ3->~QLabel();
                AbeJ3T->~QTimer();
                J3out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }


        if(J4out==true)
        {
            if(  AbeJ4->x() >= ui->malesymbol->x()-50 && AbeJ4->x() <= ui->malesymbol->x()+100)
            {
                AbeJ4->~QLabel();
                AbeJ4T->~QTimer();
                J4out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }

        if(J5out==true)
        {
            if(  AbeJ5->x() >= ui->malesymbol->x()-50 && AbeJ5->x() <= ui->malesymbol->x()+100)
            {
                AbeJ5->~QLabel();
                AbeJ5T->~QTimer();
                J5out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }
    }

    if(event->key()==Qt::Key_K && count>0 && IfResulted==false)
    {
        if(K1out==true)
        {
            if(  AbeK1->x() >= ui->malesymbol->x()-50 && AbeK1->x() <= ui->malesymbol->x()+100)
            {
                AbeK1->~QLabel();
                AbeK1T->~QTimer();
                K1out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }

        if(K2out==true)
        {
            if(  AbeK2->x() >= ui->malesymbol->x()-50 && AbeK2->x() <= ui->malesymbol->x()+100)
            {
                AbeK2->~QLabel();
                AbeK2T->~QTimer();
                K2out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }
        }

        if(K3out==true)
        {
            if(  AbeK3->x() >= ui->malesymbol->x()-50 && AbeK3->x() <= ui->malesymbol->x()+100)
            {
                AbeK3->~QLabel();
                AbeK3T->~QTimer();
                K3out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }

         }

        if(K4out==true)
        {
            if(  AbeK4->x() >= ui->malesymbol->x()-50 && AbeK4->x() <= ui->malesymbol->x()+100)
            {
                AbeK4->~QLabel();
                AbeK4T->~QTimer();
                K4out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }

         }

        if(K5out==true)
        {
            if(  AbeK5->x() >= ui->malesymbol->x()-50 && AbeK5->x() <= ui->malesymbol->x()+100)
            {
                AbeK5->~QLabel();
                AbeK5T->~QTimer();
                K5out=false;

                ui->malesymbol->setPixmap(MaleSymbolBright);
                QTimer::singleShot(300, this, SLOT(MaleSymbolDark()));

                score+=10;
                ui->LCDScore->display(score);
            }

         }
     }

    if(event->key()==Qt::Key_Escape && count>0)
    {
       // int x=0;
        //x=ui->malesymbol->x();
        if(IfResulted==true )
        {
            qApp->quit();
        }


    }


}

void Forest::Game()
{
    ui->malesymbol->setPixmap(QPixmap("image/Male_Symbol.png"));
    ui->malesymbol->setVisible(true);
    ui->lcdNumber->setVisible(true);
    ui->LCDScore->setVisible(true);

    QGraphicsOpacityEffect *eff2 = new QGraphicsOpacityEffect(this);
    ui->AbeIntro->setGraphicsEffect(eff2);
    QPropertyAnimation *b = new QPropertyAnimation(eff2,"opacity");
    b->setDuration(1000);
    b->setStartValue(1);
    b->setEndValue(0);
    b->setEasingCurve(QEasingCurve::InBack);
    b->start(QPropertyAnimation::DeleteWhenStopped);


    ui->label->clear();
    ui->lcdNumber->display(30);

    QTimer::singleShot(5000, this, SLOT(StartAndTimerCountdown()));

    //timer1 = new QTimer(this);
    //connect(timer1, SIGNAL(timeout()), this, SLOT(StartAndTimerCountdown()));
    //timer1->start(5000);



}

void Forest::StartAndTimerCountdown()
{
    IfStarted=true;


    //timer1->~QTimer();

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(LCDupdate()));
    timer2->start(1000);


    timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()), this, SLOT(Result()));
    timer4->start(31000);

    Generate();


}



void Forest::Generate()
{
   if(IfResulted==false)
   {
    // timer3->~QTimer();
   // IfGenerated=false;
    //qDebug()<<"IfGenerated=false";

    randNum2 = rand()%10;


    if(randNum2==0 && J1out==false)
    {
        AbeJ1 = new QLabel(this);
        AbeJ1->setGeometry(1100,210,300,300);
        AbeJ1->setPixmap(QPixmap ("image/Abe Chair.png"));
        AbeJ1->setVisible(true);
        AbeJ1T = new QTimer(this);
        J1out = true;
        qDebug()<<"J1out";
        connect(AbeJ1T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeJ1,AbeJ1T,J1out); });
        AbeJ1T->start(10);
    }

    if(randNum2==1 && J2out==false)
    {
        AbeJ2 = new QLabel(this);
        AbeJ2->setGeometry(1100,210,300,300);
        AbeJ2->setPixmap(QPixmap ("image/Abe Chair.png"));
        AbeJ2->setVisible(true);
        AbeJ2T = new QTimer(this);
        J2out = true;
        qDebug()<<"J2out";
        connect(AbeJ2T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeJ2,AbeJ2T,J2out); });
        AbeJ2T->start(10);
    }

    if(randNum2==2 && J3out==false)
    {
        AbeJ3 = new QLabel(this);
        AbeJ3->setGeometry(1100,210,300,300);
        AbeJ3->setPixmap(QPixmap ("image/Abe Chair.png"));
        AbeJ3->setVisible(true);
        AbeJ3T = new QTimer(this);
        J3out = true;
        qDebug()<<"J3out";
        connect(AbeJ3T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeJ3,AbeJ3T,J3out); });
        AbeJ3T->start(10);
    }

    if(randNum2==3 && J4out==false)
    {
        AbeJ4 = new QLabel(this);
        AbeJ4->setGeometry(1100,210,300,300);
        AbeJ4->setPixmap(QPixmap ("image/Abe Chair.png"));
        AbeJ4->setVisible(true);
        AbeJ4T = new QTimer(this);
        J4out = true;
        qDebug()<<"J4out";
        connect(AbeJ4T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeJ4,AbeJ4T,J4out); });
        AbeJ4T->start(10);
    }

    if(randNum2==4 && J5out==false)
    {
        AbeJ5 = new QLabel(this);
        AbeJ5->setGeometry(1100,210,300,300);
        AbeJ5->setPixmap(QPixmap ("image/Abe Chair.png"));
        AbeJ5->setVisible(true);
        AbeJ5T = new QTimer(this);
        J5out = true;
        qDebug()<<"J5out";
        connect(AbeJ5T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeJ5,AbeJ5T,J5out); });
        AbeJ5T->start(10);
    }

    if(randNum2==5 && K1out==false)
    {
        AbeK1 = new QLabel(this);
        AbeK1->setGeometry(1100,210,300,300);
        AbeK1->setPixmap(QPixmap ("image/AbeK.png"));
        AbeK1->setScaledContents(true);
        AbeK1->setVisible(true);
        AbeK1T = new QTimer(this);
        K1out = true;
        qDebug()<<"K1out";
        connect(AbeK1T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeK1,AbeK1T,K1out); });
        AbeK1T->start(10);
    }


    if(randNum2==6 && K2out==false)
    {
        AbeK2 = new QLabel(this);
        AbeK2->setGeometry(1100,210,300,300);
        AbeK2->setPixmap(QPixmap ("image/AbeK.png"));
        AbeK2->setScaledContents(true);
        AbeK2->setVisible(true);
        AbeK2T = new QTimer(this);
        K2out = true;
        qDebug()<<"K2out";
        connect(AbeK2T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeK2,AbeK2T,K2out); });
        AbeK2T->start(10);
    }

    if(randNum2==7 && K3out==false)
    {
        AbeK3 = new QLabel(this);
        AbeK3->setGeometry(1100,210,300,300);
        AbeK3->setPixmap(QPixmap ("image/AbeK.png"));
        AbeK3->setScaledContents(true);
        AbeK3->setVisible(true);
        AbeK3T = new QTimer(this);
        K3out = true;
        qDebug()<<"K3out";
        connect(AbeK3T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeK3,AbeK3T,K3out); });
        AbeK3T->start(10);
    }

    if(randNum2==8 && K4out==false)
    {
        AbeK4 = new QLabel(this);
        AbeK4->setGeometry(1100,210,300,300);
        AbeK4->setPixmap(QPixmap ("image/AbeK.png"));
        AbeK4->setScaledContents(true);
        AbeK4->setVisible(true);
        AbeK4T = new QTimer(this);
        K4out = true;
        qDebug()<<"K4out";
        connect(AbeK4T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeK4,AbeK4T,K4out); });
        AbeK4T->start(10);
    }

    if(randNum2==9 && K5out==false)
    {
        AbeK5 = new QLabel(this);
        AbeK5->setGeometry(1100,210,300,300);
        AbeK5->setPixmap(QPixmap ("image/AbeK.png"));
        AbeK5->setScaledContents(true);
        AbeK5->setVisible(true);
        AbeK5T = new QTimer(this);
        K5out = true;
        qDebug()<<"K5out";
        connect(AbeK5T,  &QTimer::timeout, this, [this]{ MoveAbe(AbeK5,AbeK5T,K5out); });
        AbeK5T->start(10);
    }



    randNum1 = rand()%100 + 500;
   // IfGenerated=true;
    //qDebug()<<"IfGenerated=true";
    QTimer::singleShot(randNum1, this, SLOT(Generate()));
    qDebug()<<"Qtimer runned";
   }
}




void Forest::LCDupdate()
{
    static int count;
    count=ui->lcdNumber->value();
    if(count>0)
    {
    count--;
    ui->lcdNumber->display(count);
    }

}

void Forest::Result()
{
    IfResulted=true;

    QMovie *shine = new QMovie("image/Male_Symbol_Flash.gif");
    ui->malesymbol->setMovie(shine);
    shine->start();

    timer2->~QTimer();
    //timer3->~QTimer();
    timer4->~QTimer();

    QString finalScore = QString::number(score);

    QString labelText = "<P><b><i><FONT COLOR='#ff0000' FONT SIZE = 24>";
    labelText .append(finalScore);
    labelText .append("</i></b></P></br>");
    ui->Score->setText(labelText);

    ui->MoveAbe->setVisible(false);
    ui->Your->setVisible(true);
    ui->Score->setVisible(true);
    ui->EndHint->setVisible(true);

}

void Forest::Reset()
{
    score=0;
    ui->Your->setVisible(false);
    ui->Score->setVisible(false);
    ui->EndHint->setVisible(false);
    ui->LCDScore->display(score);
    ui->MoveAbe->setGeometry(1100,210,221,241);

}

void Forest::MaleSymbolDark()
{
    QPixmap MaleSymbol("image/Male_Symbol.png");
    ui->malesymbol->setPixmap(MaleSymbol);

}

void Forest::MoveAbe(QLabel *Abe,QTimer *timer,bool &out)
{
    Abe->setGeometry(Abe->x()-5,Abe->y(),221,241);

    if(Abe->x() <= -220)
    {
        out = false;
        timer->~QTimer();
        Abe->~QLabel();
    }

}


void Forest::on_actionRestart_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
