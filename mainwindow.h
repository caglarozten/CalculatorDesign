#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QAbstractButton>
#include <QScrollBar>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void NumPressed(QAbstractButton *button);
    void MathButtonPressed(QAbstractButton *button);
    void EqualButtonPressed(QAbstractButton *button);
    void ChangeNumberSign();
    void ClearButtonPressed(QAbstractButton *button);
    void DeleteButtonPressed(QAbstractButton *button);
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ClearButtonPressed();
    void DeleteButtonPressed();
    void PointButton();
    void PointButton(QAbstractButton *button);




};
#endif // MAINWINDOW_H
