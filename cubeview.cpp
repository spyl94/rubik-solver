#include "cubeview.h"

CubeView::CubeView(QWidget *parent, unsigned int* tab):QGraphicsView(parent){

}

void CubeView::build(){
   scene.addText("cc");
   this->setScene(&scene);
   this->show();

}
