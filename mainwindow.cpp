#include "mainwindow.h"
#include "define.h"
#include "cube.h"

using namespace std;

MainWindow::MainWindow(){
    // Génération des widgets de la fenêtre principale
    initActions();
    initMenus();
    initBarresOutils();
    initBarreEtat();
    initWindows();

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

void MainWindow::start(){

    /* Initialisation de l'affichage */
    messageStatus->setText("Lancement en cours...");
    progression->setRange(0,100);
    progression->setValue(0);
    progression->setVisible(true);

    /* Lancement de l'algorithme */
    c.restartRotationCount();
    c.setPermuMax(profondeurMax->value());
    c.setRotationList(listeRotation->currentText());
    time.start();
    final="";

    /* On résout le cube */
    if(helper->isChecked()) {
        if(!solver(&Cube::resolveFirst1Cross,0)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst1Cross");
        if(!solver(&Cube::resolveFirst2Cross,0)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst2Cross");
        if(!solver(&Cube::resolveFirst3Cross,0)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst3Cross");
    }
    if(!solver(&Cube::resolveFirstCross,20)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirstCross");
    if(viewRotation->isChecked()) QMessageBox::information(this, "La croix est terminée", "Le nombre de rotation a été de: "+QString::number(c.getRotationCount())+"\n"+final);
    if(!helper->isChecked()) {
        if(!solver(&Cube::resolveFirst1Face,20)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst1Face");
        if(!solver(&Cube::resolveFirst2Face,20)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst2Face");
        if(!solver(&Cube::resolveFirst3Face,20)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst3Face");
        if(!solver(&Cube::resolveFirst4Face,20)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirst4Face");
    }
    if(!solver(&Cube::resolveFirstFace,40)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveFirstFace");
    if(viewRotation->isChecked()) QMessageBox::information(this, "La première face est terminée", "Le nombre de rotation a été de: "+QString::number(c.getRotationCount())+"\n"+final);
    if(!solver(&Cube::resolveSecondEdge,60)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveSecondEdge");
    if(viewRotation->isChecked()) QMessageBox::information(this, "Le deuxième étage est terminé", "Le nombre de rotation a été de: "+QString::number(c.getRotationCount())+"\n"+final);
    if(!solver(&Cube::resolveThirdCross,70)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveThirdCross");
    if(!solver(&Cube::resolveThirdEdge,80)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveThirdEdge");
    if(viewRotation->isChecked()) QMessageBox::information(this, "La troisème face est placée", "Le nombre de rotation a été de: "+QString::number(c.getRotationCount())+"\n"+final);
    if(!solver(&Cube::resolveThirdEdgeCorner,90)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveThirdEdgeCorner");
    if(!solver(&Cube::resolveCube,100)) return (void) QMessageBox::information(this, "La simulation a échouée.","resolveThirdEdgeCorner");

    displayCube();
    solutionOptimizer(&final);

    /* On affiche le message de fin */
    QString message= "La simulation s'est déroulée avec succès! \n";
    message += "Le temps d'éxécution a été de: ";
    message += QString::number(time.elapsed());
    message += "ms.\nLe nombre de rotations a été de ";
    message += QString::number(final.size());
    message += ".\nLa simulation va être enregistrée dans le fichier: output.txt";
    message += ".\nLa liste des rotations:\n";
    message += final;
    QMessageBox::information(this, "Simulation terminée!", message);

    /* on mélange de nouveau puis on enregistre les différents états*/
    cubeMixture();
    c.restartRotationCount();
    initOutput();
    for(int i =0; i < final.length(); i++){
        c.rotation(final.at(i));
        saveCube(final.at(i));
    }
    c.restart();
}

bool MainWindow::solver(bool (Cube::*pt2Member)(QString*), int j){
    QString solution = "";
    if(!(c.*pt2Member)(&solution)) return false;
    qDebug() << solution;
    for(int i =0; i < solutionOptimizer(&solution); i++){
        c.rotation(solution.at(i));
        final += solution.at(i);
    }
    displayCube();
    progression->setValue(j);
    return true;
}

/* Méthodes d'affichage du cube */
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
        return QColor("black");
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
    if(refresh->isChecked()) qApp->processEvents();
}

/* Mélange du cube */
void MainWindow::loadCubeMixture() {
    messageStatus->setText("Sélection du fichier");
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier texte", QString(), "Text files (*.txt)");
    QFile file(fichier);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this, "Fichier", "Impossible d'ouvrir le fichier!");
        return messageStatus->setText("Prêt");
    }
    this->mixture = file.readLine();
    file.close();
    cubeMixture(); // Effectue le mélange
    file.setFileName("output.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append); // maj du fichier texte
    QTextStream flux(&file);
    flux << "/** Etat Après mélange :  ";
    for(int i =0; i < 54; i++) flux << c.getColor(i);
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

/* Méthodes d'enregistrement du fichier output.txt */
void MainWindow::initOutput(){
    QFile fichier("output.txt");
    fichier.open(QIODevice::WriteOnly);
    QTextStream flux(&fichier);
    flux << "/****** Debut de la simulation ******/ " << "\n";
    flux << "/** Etat initial       : ";
    for(int i =0; i < 54; i++) flux << c.getColor(i);
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

/* Méthodes d'initialisation de la GUI */
void MainWindow::initActions(){
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
    connect(actionOptions, SIGNAL(triggered()), this, SLOT(openOptions()));

    actionPropos = new QAction("&À propos du projet", this);
    connect(actionPropos, SIGNAL(triggered()), this, SLOT(openPropos()));

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
void MainWindow::initMenus(){
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
void MainWindow::initBarresOutils(){
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
void MainWindow::initBarreEtat(){
    barreEtat = statusBar();
    messageStatus = new QLabel;
    barreEtat->addWidget(messageStatus);

    progression = new QProgressBar(this);
    progression->setAlignment(Qt::AlignRight);
    progression->setVisible(false);
    progression->setMaximumHeight(14);
    statusBar()->addWidget(progression, 1);
}
void  MainWindow::openOptions(){
    optionsWindow.show();
    connect(valider, SIGNAL(clicked()), this, SLOT(closeOptions()));
}
void MainWindow::openPropos(){
    QLabel *label;
    label = new QLabel("Programme de résolution du rubiks cube <br />Réalisé dans le cadre d'un projet de l'<a href=\"http://www.efrei.fr\">EFREI</a> par Spyl et Alexian.<br /><br />Le fichier à ouvrir doit respecter le format suivant: <br /> Contenir les lettres de A à Z ou @.",&proposWindow);
    proposWindow.show();
}

void  MainWindow::closeOptions(){
    optionsWindow.close();
}
void MainWindow::initWindows(){

    proposWindow.setWindowTitle("A propos");
    proposWindow.setMinimumSize(600,100);
    optionsWindow.setWindowTitle("Options");
    profondeurMax = new QSpinBox;
    profondeurMax->setRange(3,20);
    profondeurMax->setValue(9);
    listeRotation = new QComboBox;
    listeRotation->addItem("ABCDEFGHIJKL");
    listeRotation->addItem("ABCDEFGHIJKLMNOPQRSTUVWXYZ@");
    listeRotation->addItem("ABCDEFG");
    helper = new QCheckBox;
    helper->setChecked(true);
    viewRotation = new QCheckBox;
    viewRotation->setChecked(false);
    refresh = new QCheckBox;
    refresh->setChecked(true);
    firstFace = new QCheckBox;
    firstFace->setChecked(false);
    valider = new QPushButton;
    valider->setText("Enregistrer les modifications");

    //Mise en page de la Fenetre Options
    QVBoxLayout *layout = new QVBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Profondeur de génération des rotations", profondeurMax);
    formLayout->addRow("Rotations utilisées lors de la génération", listeRotation);
    formLayout->addRow("Générer la croix pièce par pièce", helper);
    formLayout->addRow("Générer la première face par arborescence", firstFace);
    formLayout->addRow("Afficher le nombre de rotations par étape", viewRotation);
    formLayout->addRow("Actualiser l'affichage", refresh);
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(valider);
    layout->addLayout(formLayout);
    layout->addLayout(hLayout);
    optionsWindow.setLayout(layout);
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
