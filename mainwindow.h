#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <iostream>
#include <time.h>

class MainWindow : public QMainWindow
{
    //Q_OBJECT

public: //méthodes
    MainWindow();
    ~MainWindow();
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
};


#endif // MAINWINDOW_H
