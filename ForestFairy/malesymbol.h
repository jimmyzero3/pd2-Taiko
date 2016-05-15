#ifndef MALESYMBOL_H
#define MALESYMBOL_H
#include <QLabel>
#include <moveabej.h>
#include <moveabek.h>

class malesymbol : public QLabel
{
public:
    malesymbol();
    malesymbol(QWidget *parent);
    friend class MoveAbeJ;
    friend class MoveAbeK;
    void keyPressEvent(QKeyEvent *event);
};

#endif // MALESYMBOL_H
