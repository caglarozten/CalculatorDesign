#include "mainwindow.h"
#include "ui_mainwindow.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; ++i)
    {
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

        connect(


            ui->adder,
            SIGNAL(released()),
            this,
            SLOT(MathButtonPressed()))

            ;
        connect(


            ui->subtractor,
            SIGNAL(released()),
            this,
            SLOT(MathButtonPressed()))

            ;
        connect(


            ui->divider,
            SIGNAL(released()),
            this,
            SLOT(MathButtonPressed()))

            ;
        connect(


            ui->multiplier,
            SIGNAL(released()),
            this,
            SLOT(MathButtonPressed()))

            ;
        connect(


            ui->Equals,
            SIGNAL(released()),
            this,
            SLOT(EqualButtonPressed()))

            ;
        connect(


            ui->ChangeSign,
            SIGNAL(released()),
            this,
            SLOT(ChangeNumberSign())

            );
        connect(


            ui->Clear,
            SIGNAL(released()),
            this,
            SLOT(ClearButtonPressed())
            );


    }




MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0))
    {
        ui->Display->setText(butVal);

    }
    else
    {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g',16));


    }
}

 void MainWindow::MathButtonPressed()
    {

      divTrigger = false;
      multTrigger = false;
      addTrigger = false;
      subTrigger = false;
      QString displayVal = ui->Display->text();
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

      ui->Display->setText("");
    }
    void MainWindow::EqualButtonPressed(){
      static double solution;
    QString displayVal = ui->Display->text();
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
    ui->Display->setText(QString::number(solution));
    }



void MainWindow::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegExp reg("[-+]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
    double dblDisplayVal = displayVal.toDouble();
    double dblDisplayValSign = -1 * dblDisplayVal;
    ui->Display->setText(QString::number(dblDisplayValSign));

    }
}

void MainWindow::ClearButtonPressed(){
    QString displayVal = ui->Display->text();
    QRegExp reg("[-+]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
    double dblDisplayVal = displayVal.toDouble();
    double dblDisplayValCLEAR = 0 * dblDisplayVal;
    ui->Display->setText(QString::number(dblDisplayValCLEAR));

    }







}









