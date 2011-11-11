#include <QFile>
#include "mainwindow.h"
#include "define.h"
#include "cube.h"
#include "cubeview.h"

MainWindow::MainWindow(){
    // Génération des widgets de la fenêtre principale
    creerActions();
    creerMenus();
    creerBarresOutils();
    creerBarreEtat();

    //Définition de la fenetre principale
    setMaximumSize(800,450);
    setMinimumSize(800,450);
    setWindowTitle("Projet SDD: Résolution Rubik's cube");

    tableWidget = new QTableWidget(12, 9, this);
    tableWidget->horizontalHeader()->setResizeMode (QHeaderView::Stretch);
    setCentralWidget(tableWidget);
    displayCube();

}
MainWindow::~MainWindow(){

}

/* Méthodes d'initialisation de la GUI */
void MainWindow::creerActions(){
    actionOuvrirFichier = new QAction(tr("&Ouvrir Fichier"), this);
    actionOuvrirFichier->setShortcut(tr("Ctrl+T"));
    connect(actionOuvrirFichier, SIGNAL(triggered()), this, SLOT(loadCubeMixture()));

    actionLancer = new QAction(tr("&Lancer"), this);
    actionLancer->setShortcut(tr("Ctrl+N"));
    //connect(actionLancer, SIGNAL(triggered()), this, SLOT(lancer()));

    actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut((tr("Ctrl+Q")));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    actionOptions = new QAction("&Options", this);
    //connect(actionOptions, SIGNAL(triggered()), this, SLOT(ouvrirOptions()));

    actionPropos = new QAction("&À propos du projet", this);
    //connect(actionPropos, SIGNAL(triggered()), this, SLOT(ouvrirPropos()));



}
void MainWindow::creerMenus(){
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        menuFichier->addAction(actionOuvrirFichier);
        menuFichier->addAction(actionLancer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
          menuEdition->addAction(actionOptions);

    QMenu *menuAPropos = menuBar()->addMenu("&?");
           menuAPropos->addAction(actionPropos);
}
void MainWindow::creerBarresOutils(){
    QToolBar *toolBarNavigation = addToolBar(tr("Navigation"));
        toolBarNavigation->addAction(actionOuvrirFichier);
        toolBarNavigation->addAction(actionOptions);
        toolBarNavigation->addAction(actionLancer);
        toolBarNavigation->addAction(actionQuitter);
}
void MainWindow::creerBarreEtat(){
    barreEtat = statusBar();
    messageStatus = new QLabel;
    barreEtat->addWidget(messageStatus);

    progression = new QProgressBar(this);
    progression->setAlignment(Qt::AlignRight);
    progression->setVisible(false);
    progression->setMaximumHeight(14);
    statusBar()->addWidget(progression, 1);
}
void MainWindow::displayCube(){
    //CubeView v(this, c.getCube() );
    for(int i = 0; i < 3; i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(24+i)));
        tableWidget->setItem(i, 3, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(21+i)));
        tableWidget->setItem(i, 4, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(18+i)));
        tableWidget->setItem(i, 5, newItem);
    }
    for(int i = 3, k = 0; i < 6; i++, k+=3){
        for(int j = 9; j < 12; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(j+k)));
            tableWidget->setItem(i,j%3, newItem);
        }
        for(int j = 0; j < 3; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(j+k)));
            tableWidget->setItem(i,j%3 +3, newItem);
        }
    }
    for(int i = 3; i < 6 ; i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(38-(i%3))));
        tableWidget->setItem(i, 6, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(41-(i%3))));
        tableWidget->setItem(i, 7, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(44-(i%3))));
        tableWidget->setItem(i, 8, newItem);
    }
    for(int i = 6, k = 0; i < 9; i++, k+=3){
        for(int j = 27; j < 30; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(j+k)));
            tableWidget->setItem(i,j%3 +3, newItem);
        }
    }
    for(int i = 9; i <12 ; i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(51+(i%3))));
        tableWidget->setItem(i, 3, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(48+(i%3))));
        tableWidget->setItem(i, 4, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(45+(i%3))));
        tableWidget->setItem(i, 5, newItem);
    }
}
void MainWindow::loadCubeMixture() {
    messageStatus->setText("Sélection du fichier");
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier texte", QString(), "Text files (*.txt)");
    QFile file(fichier);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this, "Fichier", "Impossible d'ouvrir le fichier!");
        messageStatus->setText("Prêt");
        return;
    }
    this->mixture = file.readLine();
    file.close();
    //qDebug() << mixture;
    cubeMixture();
    messageStatus->setText("Prêt");
}
void MainWindow::cubeMixture(){
    if(mixture == NULL) mixture = "JHGLDZGLYZ@DPU@IHKGRTJ@AWLCVXZSIASMYKCU@HGAXLMMWDDPNPTEKXR@";
    c.mixture(mixture);
}
