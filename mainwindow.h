#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <iostream>
#include <time.h>
#include <cube.h>
#include "cubeview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public: //méthodes
    MainWindow();
    ~MainWindow();
    void displayCube();
    void cubeMixture();
    void saveCube();
    QString mixture;

private:
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

    QTableWidget *tableWidget;

private slots:
    void loadCubeMixture();

private:
    Cube c;
};


#endif // MAINWINDOW_H
