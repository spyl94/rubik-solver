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
#include "cubeview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void displayCube();
    void cubeMixture();
    void saveCube(QChar r);
    void initOutput();
    QColor color(int i);

private:
    /* GUI */
    void creerActions();
    void creerMenus();
    void creerBarresOutils();
    void creerBarreEtat();
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

    QTableWidget *tableWidget;

    /* DATA */
    Cube c; // notre objet cube.
    QString mixture; // contient les opérations de mélange.
    QTime time; //permet de calculer le temps d'éxécution.

private slots:
    void loadCubeMixture();
    void start();
    void rotationA();
    void rotationB();
    void rotationC();
    void rotationD();
    void rotationE();
    void rotationF();
};


#endif // MAINWINDOW_H
