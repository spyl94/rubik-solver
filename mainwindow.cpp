#include "mainwindow.h"
#include "define.h"
#include "cube.h"

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
    case 6:
        return QColor("yellow");
    default:
        return QColor("white");
    }
}
void MainWindow::displayCube(){
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
    qApp->processEvents();

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
    QString solution = "";
    time.start();

    /* On resout la croix sur la première face */
    if(!c.resolveFirst1Cross(&solution)) {
        QMessageBox::information(this, "La simulation a échouée.","");
        return;
    }
    for(int i =0; i < solution.length(); i++)
    {
        c.rotation(solution.at(i));
        saveCube(solution.at(i));
    }
    this->displayCube();
    solution = "";

    if(!c.resolveFirst2Cross(&solution)) {
        QMessageBox::information(this, "La simulation a échouée.","");
        return;
    }
    for(int i =0; i < solution.length(); i++)
    {
        c.rotation(solution.at(i));
        saveCube(solution.at(i));
    }
    solution = "";
    displayCube();
    if(!c.resolveFirst3Cross(&solution)) {
        QMessageBox::information(this, "La simulation a échouée.","");
        return;
    }
    for(int i =0; i < solution.length(); i++)
    {
        c.rotation(solution.at(i));
        saveCube(solution.at(i));
    }
    solution = "";
    displayCube();
    if(!c.resolveFirstCross(&solution)) {
        QMessageBox::information(this, "La simulation a échouée.","");
        return;
    }
    for(int i =0; i < solution.length(); i++)
    {
        c.rotation(solution.at(i));
        saveCube(solution.at(i));
    }
    solution = "";
    displayCube();

    /*if(!c.resolveFirstFace(&solution)) {
        QMessageBox::information(this, "La simulation a échouée.","");
        return;
    }
    for(int i =0; i < solution.length(); i++)
    {
        c.rotation(solution.at(i));
        saveCube(solution.at(i));
    }
    solution = "";
    displayCube();*/

    QString message= "La simulation s'est déroulée avec succès! \n";
    message += "Le temps d'éxécution a été de: ";
    message += QString::number(time.elapsed());
    message += "ms.\nLe nombre de rotations a été de ";
    message += QString::number(c.getRotationCount());
    message += ".\nLa simulation a été enregistrée dans le fichier: output.txt";
    QMessageBox::information(this, "Simulation terminée!", message);
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
    actionG = new QAction("&G",this);
    connect(actionG, SIGNAL(triggered()), this, SLOT(rotationG()));
    actionH = new QAction("&H",this);
    connect(actionH, SIGNAL(triggered()), this, SLOT(rotationH()));
    actionI = new QAction("&I",this);
    connect(actionI, SIGNAL(triggered()), this, SLOT(rotationI()));
    actionJ = new QAction("&J",this);
    connect(actionJ, SIGNAL(triggered()), this, SLOT(rotationJ()));
    actionK = new QAction("&K",this);
    connect(actionK, SIGNAL(triggered()), this, SLOT(rotationK()));
    actionL = new QAction("&L",this);
    connect(actionL, SIGNAL(triggered()), this, SLOT(rotationL()));
    actionM = new QAction("&M",this);
    connect(actionM, SIGNAL(triggered()), this, SLOT(rotationM()));
    actionN = new QAction("&N",this);
    connect(actionN, SIGNAL(triggered()), this, SLOT(rotationN()));
    actionO = new QAction("&O",this);
    connect(actionO, SIGNAL(triggered()), this, SLOT(rotationO()));
    actionP = new QAction("&P",this);
    connect(actionP, SIGNAL(triggered()), this, SLOT(rotationP()));
    actionQ = new QAction("&Q",this);
    connect(actionQ, SIGNAL(triggered()), this, SLOT(rotationQ()));
    actionR = new QAction("&R",this);
    connect(actionR, SIGNAL(triggered()), this, SLOT(rotationR()));
    actionS = new QAction("&S",this);
    connect(actionS, SIGNAL(triggered()), this, SLOT(rotationS()));
    actionT = new QAction("&T",this);
    connect(actionT, SIGNAL(triggered()), this, SLOT(rotationT()));
    actionU = new QAction("&U",this);
    connect(actionU, SIGNAL(triggered()), this, SLOT(rotationU()));
    actionV = new QAction("&V",this);
    connect(actionV, SIGNAL(triggered()), this, SLOT(rotationV()));
    actionW = new QAction("&W",this);
    connect(actionW, SIGNAL(triggered()), this, SLOT(rotationW()));
    actionX = new QAction("&X",this);
    connect(actionX, SIGNAL(triggered()), this, SLOT(rotationX()));
    actionY = new QAction("&Y",this);
    connect(actionY, SIGNAL(triggered()), this, SLOT(rotationY()));
    actionZ = new QAction("&Z",this);
    connect(actionZ, SIGNAL(triggered()), this, SLOT(rotationZ()));
    actionAr = new QAction("&@",this);
    connect(actionAr, SIGNAL(triggered()), this, SLOT(rotationAr()));

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
        toolBarNavigation->addAction(actionG);
        toolBarNavigation->addAction(actionH);
        toolBarNavigation->addAction(actionI);
        toolBarNavigation->addAction(actionJ);
        toolBarNavigation->addAction(actionK);
        toolBarNavigation->addAction(actionL);
        toolBarNavigation->addAction(actionM);
        toolBarNavigation->addAction(actionN);
        toolBarNavigation->addAction(actionO);
        toolBarNavigation->addAction(actionP);
        toolBarNavigation->addAction(actionQ);
        toolBarNavigation->addAction(actionR);
        toolBarNavigation->addAction(actionS);
        toolBarNavigation->addAction(actionT);
        toolBarNavigation->addAction(actionU);
        toolBarNavigation->addAction(actionV);
        toolBarNavigation->addAction(actionW);
        toolBarNavigation->addAction(actionX);
        toolBarNavigation->addAction(actionY);
        toolBarNavigation->addAction(actionZ);
        toolBarNavigation->addAction(actionAr);
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
void MainWindow::rotationG() {
    c.rotation(QChar('G'));
    displayCube();
}
void MainWindow::rotationH() {
    c.rotation(QChar('H'));
    displayCube();
}
void MainWindow::rotationI() {
    c.rotation(QChar('I'));
    displayCube();
}
void MainWindow::rotationJ() {
    c.rotation(QChar('J'));
    displayCube();
}
void MainWindow::rotationK() {
    c.rotation(QChar('K'));
    displayCube();
}
void MainWindow::rotationL() {
    c.rotation(QChar('L'));
    displayCube();
}
void MainWindow::rotationM() {
    c.rotation(QChar('M'));
    displayCube();
}
void MainWindow::rotationN() {
    c.rotation(QChar('N'));
    displayCube();
}
void MainWindow::rotationO() {
    c.rotation(QChar('O'));
    displayCube();
}
void MainWindow::rotationP() {
    c.rotation(QChar('P'));
    displayCube();
}
void MainWindow::rotationQ() {
    c.rotation(QChar('Q'));
    displayCube();
}
void MainWindow::rotationR() {
    c.rotation(QChar('R'));
    displayCube();
}
void MainWindow::rotationS() {
    c.rotation(QChar('S'));
    displayCube();
}
void MainWindow::rotationT() {
    c.rotation(QChar('T'));
    displayCube();
}
void MainWindow::rotationU() {
    c.rotation(QChar('U'));
    displayCube();
}
void MainWindow::rotationV() {
    c.rotation(QChar('V'));
    displayCube();
}
void MainWindow::rotationW() {
    c.rotation(QChar('W'));
    displayCube();
}
void MainWindow::rotationX() {
    c.rotation(QChar('X'));
    displayCube();
}
void MainWindow::rotationY() {
    c.rotation(QChar('Y'));
    displayCube();
}
void MainWindow::rotationZ() {
    c.rotation(QChar('Z'));
    displayCube();
}
void MainWindow::rotationAr() {
    c.rotation(QChar('@'));
    displayCube();
}
