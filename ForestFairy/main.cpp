#include "forest.h"
#include <QApplication>
#include <QSound>
#include <QLabel>
#include <QtGui>
#include <QSound>
#include <QSoundEffect>
int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
        Forest w;
        w.show();

        QSoundEffect Abe;
        Abe.setSource(QUrl::fromLocalFile("image/02.wav"));
        Abe.setLoopCount(QSoundEffect::Infinite);
        Abe.setVolume(1.0f);
        Abe.play();


       return a.exec();
}
