#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"

static double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;
bool oldnumber = false;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->Display->setPlainText(QString::number(calcVal));

    ui->HistoryLine->setPlainText("");
    QAbstractButton *numButtons[10];
    for(int i = 0; i < 10; ++i)
    {
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QAbstractButton *>(butName);
        connect(numButtons[i], SIGNAL(released(QAbstractButton *)), this, SLOT(NumPressed(QAbstractButton *)));
               connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));

    }

    connect(


        ui->adder,
        SIGNAL(released(QAbstractButton  *)),
        this,
        SLOT(MathButtonPressed(QAbstractButton *)))

        ;
    connect(


        ui->adder,
        SIGNAL(released()),
        this,
        SLOT(MathButtonPressed()))

        ;
    connect(


        ui->subtractor,
        SIGNAL(released(QAbstractButton *)),
        this,
        SLOT(MathButtonPressed(QAbstractButton *)))

        ;

    connect(


        ui->subtractor,
        SIGNAL(released()),
        this,
        SLOT(MathButtonPressed()))

        ;
    connect(


        ui->divider,
        SIGNAL(released(QAbstractButton *)),
        this,
        SLOT(MathButtonPressed(QAbstractButton *)))

        ;
    connect(


        ui->divider,
        SIGNAL(released()),
        this,
        SLOT(MathButtonPressed()))

        ;
    connect(


        ui->multiplier,
        SIGNAL(released(QAbstractButton *)),
        this,
        SLOT(MathButtonPressed(QAbstractButton *)))

        ;
    connect(


        ui->multiplier,
        SIGNAL(released()),
        this,
        SLOT(MathButtonPressed()))

        ;
    connect(


        ui->Equals,
        SIGNAL(released(QAbstractButton *)),
        this,
        SLOT(EqualButtonPressed(QAbstractButton *)))

        ;

    connect (
        ui->Equals,
        SIGNAL(released()),
        this,
        SLOT(EqualButtonPressed()))
        ;

    connect (
        ui->ChangeSign,
        SIGNAL(released()),
        this,
        SLOT(ChangeNumberSign())
        );

    connect (
        ui->Clear,
        SIGNAL(released(QAbstractButton *)),
        this,
        SLOT(ClearButtonPressed(QAbstractButton *))
        );

    connect (
        ui->Clear,
        SIGNAL(released()),
        this,
        SLOT(ClearButtonPressed())
        );

    connect (
        ui->Delete,
        SIGNAL(released(QAbstractButton *)),
        this,
        SLOT(DeleteButtonPressed(QAbstractButton *))
        );

    connect (
        ui->Delete,
        SIGNAL(released()),
        this,
        SLOT(DeleteButtonPressed())
        );
    connect(


        ui->PointButton,
        SIGNAL(released(QAbstractButton  *)),
        this,
        SLOT(PointButton(QAbstractButton *)))

        ;
    connect(


        ui->PointButton,
        SIGNAL(released()),
        this,
        SLOT(PointButton()))

        ;



}











MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::NumPressed(QAbstractButton *button)
{

    QString butVal = button->text();
    QString displayVal = ui->Display->toPlainText();

    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0))
    {
        ui->Display->setPlainText(butVal);



    }
    else
    {
        QString newVal = displayVal + butVal;
                double dblNewVal = newVal.toDouble();
        ui->Display->setPlainText(QString::number(dblNewVal, 'g',16));






    }



}


void MainWindow::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->toPlainText();
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0))
    {
        ui->Display->setPlainText(butVal);


    }
    else
    {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setPlainText(QString::number(dblNewVal, 'g',16));






    }

}
void MainWindow::MathButtonPressed(QAbstractButton *button)
{

    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->toPlainText();
    calcVal = displayVal.toDouble();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0)
    {
        divTrigger = true;
    }
    else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0)
    {
        multTrigger = true;
    }
    else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }
    else
    {
        subTrigger = true;
    }

    ui->Display->setPlainText("");
    ui->HistoryLine->setPlainText(ui->HistoryLine->toPlainText() + displayVal + butVal);

}


void MainWindow::MathButtonPressed()
{

    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->toPlainText();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0)
    {
        divTrigger = true;
    }
    else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0)
    {
        multTrigger = true;
    }
    else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }
    else
    {
        subTrigger = true;
    }

    ui->Display->setPlainText("");
    ui->HistoryLine->setPlainText(ui->HistoryLine->toPlainText() + displayVal + butVal);

}
void MainWindow::EqualButtonPressed(QAbstractButton*){
    static double solution;
    QString displayVal = ui->Display->toPlainText();
    double dblDisplayVal = displayVal.toDouble();

    if(addTrigger || subTrigger || multTrigger || divTrigger){

        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        }
        else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        }
        else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        }
        else {
            solution = calcVal / dblDisplayVal;
        }

        divTrigger = false;
        multTrigger = false;
        addTrigger = false;
        subTrigger = false;
    }
    ui->Display->setPlainText(QString::number(solution));
    ui->HistoryLine->setPlainText(ui->HistoryLine->toPlainText() + displayVal + tr("=") + QString::number(solution));
    ui->HistoryLine->append("\n");




}

void MainWindow::EqualButtonPressed(){
    static double solution;
    QString displayVal = ui->Display->toPlainText();
    double dblDisplayVal = displayVal.toDouble();

    if(addTrigger || subTrigger || multTrigger || divTrigger){

        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        }
        else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        }
        else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        }
        else {
            solution = calcVal / dblDisplayVal;
        }

        divTrigger = false;
        multTrigger = false;
        addTrigger = false;
        subTrigger = false;
    }
    ui->Display->setPlainText(QString::number(solution));
    ui->HistoryLine->setPlainText(ui->HistoryLine->toPlainText() + displayVal + tr("=") + QString::number(solution));
    ui->HistoryLine->append("\n");




}
void MainWindow::ChangeNumberSign(){
    QString displayVal = ui->Display->toPlainText();
    QRegExp reg("[-+]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->Display->setPlainText(QString::number(dblDisplayValSign));

    }
}
void MainWindow::ClearButtonPressed(QAbstractButton*){
    QString displayVal = ui->Display->toPlainText();
    QRegExp reg("[-+]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValCLEAR = 0 * dblDisplayVal;
        ui->Display->setPlainText(QString::number(dblDisplayValCLEAR));
        ui->HistoryLine->setPlainText(QString::number(dblDisplayValCLEAR));



    }
}

void MainWindow::ClearButtonPressed(){
    QString displayVal = ui->Display->toPlainText();
    QRegExp reg("[-+]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValCLEAR = 0 * dblDisplayVal;
        ui->Display->setPlainText(QString::number(dblDisplayValCLEAR));
        ui->HistoryLine->setPlainText(QString::number(dblDisplayValCLEAR));



    }
}

void MainWindow::DeleteButtonPressed(QAbstractButton*)
{

    QString displayLabel = ui->Display->toPlainText();



    if (displayLabel.length() == 0) {
        return;
    }



    displayLabel.QString::chop(1);


    ui->Display->setPlainText(displayLabel);

}



void MainWindow::DeleteButtonPressed()
{

    QString displayLabel = ui->Display->toPlainText();



    if (displayLabel.length() == 0) {
        return;
    }



    displayLabel.QString::chop(1);
    ui->Display->setPlainText(displayLabel);


}


void MainWindow::PointButton()
{
    QString displayVal = ui->Display->toPlainText();

    ui->Display->setText(displayVal+".");

}


void MainWindow::PointButton(QAbstractButton*)
{
    QString displayVal = ui->Display->toPlainText();

    ui->Display->setText(displayVal+".");
}

    void MainWindow::keyPressEvent(QKeyEvent *e) {
        switch (e->key()) {
        case Qt::Key_1:
            NumPressed(ui->Button1);
            break;
        case Qt::Key_2:
            NumPressed(ui->Button2);
            break;
        case Qt::Key_3:
            NumPressed(ui->Button3);
            break;
        case Qt::Key_4:
            NumPressed(ui->Button4);
            break;
        case Qt::Key_5:
            NumPressed(ui->Button5);
            break;
        case Qt::Key_6:
            NumPressed(ui->Button6);
            break;
        case Qt::Key_7:
            NumPressed(ui->Button7);
            break;
        case Qt::Key_8:
            NumPressed(ui->Button8);
            break;
        case Qt::Key_9:
            NumPressed(ui->Button9);
            break;
        case Qt::Key_0:
            NumPressed(ui->Button0);
            break;
        case Qt::Key_Plus:
            MathButtonPressed(ui->adder);
            break;
        case Qt::Key_Minus:
            MathButtonPressed(ui->subtractor);
            break;
        case Qt::Key_Asterisk:
            MathButtonPressed(ui->multiplier);
            break;
        case Qt::Key_Slash:
            MathButtonPressed(ui->divider);
            break;
        case Qt::Key_Enter:
            EqualButtonPressed(ui->Equals);
            break;
        case Qt::Key_G:
            ClearButtonPressed(ui->Clear);
            break;
        case Qt::Key_Backspace:
            DeleteButtonPressed(ui->Clear);
            break;
        case Qt::Key_Period:
            PointButton(ui->PointButton);
            break;
        }
    }










