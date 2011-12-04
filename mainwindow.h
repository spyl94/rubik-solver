#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QInputDialog>
#include <QIODevice>
#include <QString>
#include <iostream>
#include <time.h>
#include <cube.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /* DATA */
private:
    Cube c; // notre objet cube.
    QString mixture; // contient les opérations de mélange.
    QTime time; //permet de calculer le temps d'éxécution.

private slots:
    void loadCubeMixture();
    void start();

public:
    MainWindow();
    void displayCube();
    void cubeMixture();
    void saveCube(QChar r);
    void initOutput();
    QColor color(int i);
    bool solver(bool (Cube::*pt2Member)(QString*), int j);

     /* GUI */
private:
    void creerActions();
    void creerMenus();
    void creerBarresOutils();
    void creerBarreEtat();
    bool helper;
    QLabel *messageStatus;
    QProgressBar *progression;
    QStatusBar *barreEtat;
    QAction *actionQuitter;
    QAction *actionOuvrirFichier;
    QAction *actionPropos;
    QAction *actionOptions;
    QAction *actionLancer;
    QAction *actionA;
    QAction *actionB;
    QAction *actionC;
    QAction *actionD;
    QAction *actionE;
    QAction *actionF;
    QAction *actionG;
    QAction *actionH;
    QAction *actionI;
    QAction *actionJ;
    QAction *actionK;
    QAction *actionL;
    QAction *actionM;
    QAction *actionN;
    QAction *actionO;
    QAction *actionP;
    QAction *actionQ;
    QAction *actionR;
    QAction *actionS;
    QAction *actionT;
    QAction *actionU;
    QAction *actionV;
    QAction *actionW;
    QAction *actionX;
    QAction *actionY;
    QAction *actionZ;
    QAction *actionAr;
    QTableWidget *tableWidget;

private slots:
    void rotationA();
    void rotationB();
    void rotationC();
    void rotationD();
    void rotationE();
    void rotationF();
    void rotationG();
    void rotationH();
    void rotationI();
    void rotationJ();
    void rotationK();
    void rotationL();
    void rotationM();
    void rotationN();
    void rotationO();
    void rotationP();
    void rotationQ();
    void rotationR();
    void rotationS();
    void rotationT();
    void rotationU();
    void rotationV();
    void rotationW();
    void rotationX();
    void rotationY();
    void rotationZ();
    void rotationAr();
};


#endif // MAINWINDOW_H
