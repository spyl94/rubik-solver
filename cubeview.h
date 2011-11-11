#ifndef CUBEVIEW_H
#define CUBEVIEW_H
#include <QApplication>
#include <QtGui>

class CubeView : public QGraphicsView {
    Q_OBJECT
public:
    CubeView(QWidget *parent=0, unsigned int* tab = 0);

    void build();

protected:
   // CubeView2DItem* firstItem;
    QGraphicsScene scene;
};

#endif // CUBEVIEW_H
