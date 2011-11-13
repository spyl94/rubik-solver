#include "mainwindow.h"
#include "define.h"
#include "cube.h"
#include "cubeview.h"

using namespace std;

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

    initOutput(); // Preparation fichier output.txt
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
    connect(actionLancer, SIGNAL(triggered()), this, SLOT(start()));

    actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut((tr("Ctrl+Q")));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    actionOptions = new QAction("&Options", this);
    //connect(actionOptions, SIGNAL(triggered()), this, SLOT(ouvrirOptions()));

    actionPropos = new QAction("&À propos du projet", this);
    //connect(actionPropos, SIGNAL(triggered()), this, SLOT(ouvrirPropos()));

    actionA = new QAction("&A",this);
    connect(actionA, SIGNAL(triggered()), this, SLOT(rotationA()));
    actionB = new QAction("&B",this);
    connect(actionB, SIGNAL(triggered()), this, SLOT(rotationB()));
    actionC = new QAction("&C",this);
    connect(actionC, SIGNAL(triggered()), this, SLOT(rotationC()));
    actionD = new QAction("&D",this);
    connect(actionD, SIGNAL(triggered()), this, SLOT(rotationD()));
    actionE = new QAction("&E",this);
    connect(actionE, SIGNAL(triggered()), this, SLOT(rotationE()));
    actionF = new QAction("&F",this);
    connect(actionF, SIGNAL(triggered()), this, SLOT(rotationF()));
}
void MainWindow::creerMenus(){
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        menuFichier->addAction(actionOuvrirFichier);
        menuFichier->addAction(actionLancer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
          menuEdition->addAction(actionOptions);
          menuEdition->addAction(actionA);
    QMenu *menuAPropos = menuBar()->addMenu("&?");
           menuAPropos->addAction(actionPropos);
}
void MainWindow::creerBarresOutils(){
    QToolBar *toolBarNavigation = addToolBar(tr("Navigation"));
        toolBarNavigation->addAction(actionOuvrirFichier);
        toolBarNavigation->addAction(actionOptions);
        toolBarNavigation->addAction(actionLancer);
        toolBarNavigation->addAction(actionQuitter);
        toolBarNavigation->addAction(actionA);
        toolBarNavigation->addAction(actionB);
        toolBarNavigation->addAction(actionC);
        toolBarNavigation->addAction(actionD);
        toolBarNavigation->addAction(actionE);
        toolBarNavigation->addAction(actionF);
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
QColor MainWindow::color(int i) {
    // cf define.h
    switch(i){
    case 1:
        return QColor("white");
    case 2:
        return QColor("blue");
    case 3:
        return QColor("red");
    case 4:
        return QColor("orange");
    case 5:
        return QColor("green");
    default:
        return QColor("yellow");
    }
}
void MainWindow::rotationA() {
    c.rotation(QChar('A'));
    displayCube();
}
void MainWindow::rotationB() {
    c.rotation(QChar('B'));
    displayCube();
}
void MainWindow::rotationC() {
    c.rotation(QChar('C'));
    displayCube();
}
void MainWindow::rotationD() {
    c.rotation(QChar('D'));
    displayCube();
}
void MainWindow::rotationE() {
    c.rotation(QChar('E'));
    displayCube();
}
void MainWindow::rotationF() {
    c.rotation(QChar('F'));
    displayCube();
}
void MainWindow::displayCube(){
    //CubeView v(this, c.getCube() );
    for(int i = 0; i < 3; i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(24+i)));
        newItem->setBackgroundColor(color(this->c.getColor(24+i)));
        tableWidget->setItem(i, 3, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(21+i)));
        newItem->setBackgroundColor(color(this->c.getColor(21+i)));
        tableWidget->setItem(i, 4, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(18+i)));
        newItem->setBackgroundColor(color(this->c.getColor(18+i)));
        tableWidget->setItem(i, 5, newItem);
    }
    for(int i = 3, k = 0; i < 6; i++, k+=3){
        for(int j = 9; j < 12; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(j+k)));
            newItem->setBackgroundColor(color(this->c.getColor(j+k)));
            tableWidget->setItem(i,j%3, newItem);
        }
        for(int j = 0; j < 3; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(j+k)));
            newItem->setBackgroundColor(color(this->c.getColor(j+k)));
            tableWidget->setItem(i,j%3 +3, newItem);
        }
    }
    for(int i = 3; i < 6 ; i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(38-(i%3))));
        newItem->setBackgroundColor(color(this->c.getColor(38-(i%3))));
        tableWidget->setItem(i, 6, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(41-(i%3))));
        newItem->setBackgroundColor(color(this->c.getColor(41-(i%3))));
        tableWidget->setItem(i, 7, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(44-(i%3))));
        newItem->setBackgroundColor(color(this->c.getColor(44-(i%3))));
        tableWidget->setItem(i, 8, newItem);
    }
    for(int i = 6, k = 0; i < 9; i++, k+=3){
        for(int j = 27; j < 30; j++){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(j+k)));
            newItem->setBackgroundColor(color(this->c.getColor(j+k)));
            tableWidget->setItem(i,j%3 +3, newItem);
        }
    }
    for(int i = 9; i <12 ; i++){
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(51+(i%3))));
        newItem->setBackgroundColor(color(this->c.getColor(51+(i%3))));
        tableWidget->setItem(i, 3, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(48+(i%3))));
        newItem->setBackgroundColor(color(this->c.getColor(48+(i%3))));
        tableWidget->setItem(i, 4, newItem);
        newItem = new QTableWidgetItem(tr("%1").arg(this->c.getColor(45+(i%3))));
        newItem->setBackgroundColor(color(this->c.getColor(45+(i%3))));
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
    cubeMixture(); // Effectue le mélange
    file.setFileName("output.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append); // maj du fichier texte
    QTextStream flux(&file);
    flux << "/** Etat Après mélange :  ";
    for(int i =0; i < 54; i++){
        flux << c.getColor(i);
    }
    flux << "\n";
    file.close();
    displayCube();
    messageStatus->setText("Prêt");
}
void MainWindow::cubeMixture(){
    if(mixture == NULL) mixture = "JHGLDZGLYZ@DPU@IHKGRTJ@AWLCVXZSIASMYKCU@HGAXLMMWDDPNPTEKXR@";
    for (int i = 0; i < mixture.size(); ++i) {
        c.rotation(mixture.at(i));
        saveCube(mixture.at(i));
    }
}
void MainWindow::initOutput(){
    QFile fichier("output.txt");
    fichier.open(QIODevice::WriteOnly);
    QTextStream flux(&fichier);
    flux << "/****** Debut de la simulation ******/ " << "\n";
    flux << "/** Etat initial       : ";
    for(int i =0; i < 54; i++){
        flux << c.getColor(i);
    }
    flux << "\n";
    fichier.close();
}
void MainWindow::saveCube(QChar r){
    QFile fichier("output.txt");
    fichier.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream flux(&fichier);
    flux << "/** Rotation n°" << c.getRotationCount() << " : " << r << " **/ ";
    for(int i =0; i < 54; i++){
        flux << c.getColor(i);
    }
    flux << "\n";
    fichier.close();
}
void MainWindow::start(){

    /* Initialisation de l'affichage */
    messageStatus->setText("Lancement en cours...");
    progression->setRange(0,100);
    progression->setValue(0);
    progression->setVisible(true);

    /* Lancement de l'algorithme */
    c.restartRotationCount();
    time.start();

    /* On resout la croix sur la première face */
    c.resolveFirstFace();
   /* c.rotation(QChar('A'));
    c.rotation(QChar('D'));
    //saveCube(QChar('C')); */
    displayCube();
    /*c.rotation(QChar('@'));
    saveCube(QChar('@'));
    displayCube();*/
}
