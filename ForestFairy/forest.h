#ifndef FOREST_H
#define FOREST_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>



namespace Ui {
class Forest;
}

class Forest : public QMainWindow
{
    Q_OBJECT

    //QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timerAbeJ;
    QTimer *timerAbeK;
    bool IfResulted=false;
    bool IfStarted=false;
    bool IfGenerated=false;
    int count=0;
    int score=0;
    int randNum1=0;
    int randNum2=0;

public:
    explicit Forest(QWidget *parent = 0);
    ~Forest();

    void keyPressEvent(QKeyEvent *event);
    friend class MoveAbeJ;
    friend class MoveAbeK;
    void setAbes();



private slots:
    void on_actionRestart_triggered();
    void Game();
    void StartAndTimerCountdown();
    void LCDupdate();
    //void MovingAbe();
    void Result();
    void Reset();
    void MaleSymbolDark();
    void Generate();
    void MoveAbe(QLabel *Abe, QTimer *timer, bool &out);

private:
    Ui::Forest *ui;

    QLabel *AbeJ1;
    QTimer *AbeJ1T;
    bool J1out=false;

    QLabel *AbeJ2;
    QTimer *AbeJ2T;
    bool J2out=false;

    QLabel *AbeJ3;
    QTimer *AbeJ3T;
    bool J3out=false;

    QLabel *AbeJ4;
    QTimer *AbeJ4T;
    bool J4out=false;

    QLabel *AbeJ5;
    QTimer *AbeJ5T;
    bool J5out=false;

    QLabel *AbeK1;
    QTimer *AbeK1T;
    bool K1out=false;

    QLabel *AbeK2;
    QTimer *AbeK2T;
    bool K2out=false;

    QLabel *AbeK3;
    QTimer *AbeK3T;
    bool K3out=false;

    QLabel *AbeK4;
    QTimer *AbeK4T;
    bool K4out=false;

    QLabel *AbeK5;
    QTimer *AbeK5T;
    bool K5out=false;
};




#endif // FOREST_H
