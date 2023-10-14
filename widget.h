#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>             //для изменения фона Widget (так как мы будем работать с функцией наследования)
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent * event);
public slots:
    void slotLeft();
    void slotRight();
    void slotStart();
    void slotAbout();
    void onGameAreaButtonClicked();
    void onPCSLOT();
private:
    Ui::Widget *ui;
    void setInterfaceStyle();
    void changeLeftRightButtonStatus(int num);  //изменение стиля для кнопки по выбору игрока

    void configurationTabWidget();  //установка конфигурации Tab
    void signalslotFunction();      //работа со сигналами и слотами
    void configurationFont();       //работа со шрифтами

    void configurationGameAreButtons();
    void lockPlayer();
    void  computerInGame();

    //создание массива для игры
    char gamerArea[3][3] =
    {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
    };

    char player = 'X';  //X OR O
    int progress = 0;   //инициализируем ходы партии
    bool gameStart = false;
    bool isAbout = false;
    bool playerLocked = true;
    QTimer* timer;
    bool stop;
    char winner;

    void changeButtonStyleArea(int row, int column,QString str);   //изменение кнопки на ту которой ходят
    void setGameAreaButton();
    void start();
    void chechGameStop();
    void endGame();

};
#endif // WIDGET_H
