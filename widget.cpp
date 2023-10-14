#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "styleheader.h"
#include <QStyleOption>         //для изменения основного фона
#include <QFontDatabase>
#include <time.h>
#include <QGridLayout>
//конструктор
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    configurationTabWidget();       //устанавливаем конфигурацию TabWidget
    setInterfaceStyle();    //вызываем функцию, которая занимается установкой стилей для обьектов
    configurationFont();    //работа со шрифтами
    configurationGameAreButtons();  //запуск работы кнопок игры Х0

    timer = new QTimer(this);
    signalslotFunction();  //работа с сигналами и слотами
}

//деструктор
Widget::~Widget()
{
    delete ui;
}

//установка фона основного приложения (QPainter)
void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);             //инициализация обьекта данным Widget
    QPainter painter(this);         //создаем обьект Painter
    this->style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);  //вызываем метод для отрисовки примитива (WIdget)
    QWidget::paintEvent(event);                                             //вызываем данные действия при конструкторе
}

//назначения правила QSS для элементов интерфейса
void Widget::setInterfaceStyle()
{
    this->setStyleSheet(StyleHeader::getMainWidgetStyle());                 //устанавливаем фон, только для Widget!
    ui->leftButton->setStyleSheet(StyleHeader::getlefftButtonStyle());
    ui->rightButton->setStyleSheet(StyleHeader::getRightActiveButtonStyle());

    ui->aboutButton->setStyleSheet(StyleHeader::getGradientButtonStyle());
    ui->startButton->setStyleSheet(StyleHeader::getGradientButtonStyle());

    ui->tabWidget->setStyleSheet(StyleHeader::getTabWidgetStyle());      //изменение цвета StyleSheet кнопок
    ui->tab_2->setStyleSheet(StyleHeader::getTabWidgetPainStyle());         // добавление темного фона по зади кнопок крестик-нолик
    ui->labelMessage->setStyleSheet(StyleHeader::getNormalMessageStyle());
    ui->text_label->setText("Крестики-нолики - это игра для двух игроков, \nкоторые по очереди ставят крестики или "
                            "\nнолики на игровое поле, состоящее из девяти клеток. \nЦель игры - выстроить три одинаковых"
                            " символа \nв ряд по горизонтали, вертикали или диагонали.");
    ui->text_label->setStyleSheet(StyleHeader::getLabelTab2());
    ui->labelMessage->setText("");

    setGameAreaButton();
}

//если игрок выбрал крестик
void Widget::slotRight()
{
    changeLeftRightButtonStatus(1);
    player = 'X';
}

void Widget::slotStart()
{
    if(!gameStart)
    {
        ui->labelMessage->setText("Ваш ход!");
        ui->labelMessage->setStyleSheet(StyleHeader::getNormalMessageStyle());
        gameStart = !gameStart;
        isAbout = true;
        slotAbout();
        start();
        lockPlayer();
        ui->startButton->setStyleSheet(StyleHeader::getButtonRed());
        ui->startButton->setText("Сдаюсь...");
        ui->leftButton->setDisabled(true);
        ui->rightButton->setDisabled(true);
    }
    else
    {
        playerLocked = true;
        gameStart = !gameStart;
        ui->startButton->setStyleSheet(StyleHeader::getGradientButtonStyle());
        ui->startButton->setText("Играть");
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        ui->labelMessage->setText("Вы проиграли!");
        ui->labelMessage->setStyleSheet(StyleHeader::getLoseMessageStyle());
    }
}

void Widget::slotAbout()
{
    if(!isAbout)
    {
        isAbout =!isAbout;
        ui->tabWidget->setCurrentIndex(0);      //выбор нужной вкладки в программе tabWidget    (0 - Об игре , 1-Игра, и тд)
        ui->aboutButton->setStyleSheet(StyleHeader::getButtonRed());
    }
    else
    {
        isAbout =!isAbout;
        ui->aboutButton->setStyleSheet(StyleHeader::getGradientButtonStyle());
        ui->tabWidget->setCurrentIndex(1);
    }
}

void Widget::onGameAreaButtonClicked()
{
    if(!playerLocked)
    {
        QPushButton * btn = qobject_cast<QPushButton*>(sender());
        int row = btn->property("row").toInt();
        int col = btn->property("column").toInt();

        QString style;
        if(gamerArea[row][col] == '-')
        {
            if(player == 'X')
            {
                style = StyleHeader::getCrossNormanlStyle();
                gamerArea[row][col] = 'X';
            }
            else
            {
                style = StyleHeader::getZeroNormanlStyle();
                gamerArea[row][col] = '0';
            }
            changeButtonStyleArea(row, col, style);
            playerLocked = true;
            progress++;
            chechGameStop();
            endGame();
            computerInGame();
        }
    }
}

void Widget::computerInGame()
{
    if(stop)
        return;
    srand(time(NULL));
    QStringList lst = {"Мой ход","Так так так...", "Хм... сложно...", "Дайте подумать..."};
    ui->labelMessage->setText(lst[rand()%4]);
    timer->start(2000);
}

void Widget::onPCSLOT()
{
    char comp;
    QString style;
    if(player == 'X')
    {
        comp = '0';
        style = StyleHeader::getZeroNormanlStyle();
    }
    else
    {
        comp = 'X';
        style = StyleHeader::getCrossNormanlStyle();
    }
    timer->stop();
    while(true)
    {
        int row = rand()%3;
        int col = rand()%3;
        if(gamerArea[row][col]== '-')
            {
            gamerArea[row][col] = comp;
            ui->labelMessage->setText("Ваш ход!");
            changeButtonStyleArea(row,col,style);
            progress++;
            chechGameStop();
            endGame();
            playerLocked = false;
            break;
            }
        }
}

//если игрок выбрал нолик
void Widget::slotLeft()
{
    changeLeftRightButtonStatus(0);
    player = '0';
}

//Переключатель выбор крестик-нолик
void Widget::changeLeftRightButtonStatus(int num)           //функция по изменению цвета по выбору игрока
{
    if(num == 1)
    {
        ui->leftButton->setStyleSheet(StyleHeader::getlefftButtonStyle());
        ui->rightButton->setStyleSheet(StyleHeader::getRightActiveButtonStyle());
    }
    else
    {
        ui->leftButton->setStyleSheet(StyleHeader::getlefftActiveButtonStyle());
        ui->rightButton->setStyleSheet(StyleHeader::getRightButtonStyle());
    }
}

//конфигурация TabWidget
void Widget::configurationTabWidget()
{
    ui->tabWidget->tabBar()->hide();            //прячем иконку (игры, об игре)
    ui->tabWidget->setMaximumHeight(320);       //установка максимальной высота у tabWidget;
    ui->tabWidget->setMaximumWidth(320);       //установка максимальной ширины у tabWidget;
    ui->tabWidget->setCurrentIndex(1);      //выбор нужной вкладки в программе tabWidget    (0 - Об игре , 1-Игра, и тд)
}

//работа с сигналами
void Widget::signalslotFunction()
{
    QObject::connect(ui->leftButton,SIGNAL(clicked()),this,SLOT(slotRight()));      //отправляем сигналы на выбор игрока
    QObject::connect(ui->rightButton,SIGNAL(clicked()),this,SLOT(slotLeft()));
    QObject::connect(ui->startButton,SIGNAL(clicked()),this,SLOT(slotStart()));
    QObject::connect(ui->aboutButton,SIGNAL(clicked()),this,SLOT(slotAbout()));
    QObject::connect(timer,&QTimer::timeout,this, &Widget::onPCSLOT);
}

//работа со шрифтами
void Widget::configurationFont()
{

    QFontDatabase::addApplicationFont(":/resImg/img/fonts/Roboto-Medium.ttf"); //загрузка шрифта в базу данных шрифтов (Дальше работа в CSS)
    QFontDatabase::addApplicationFont(":/resImg/img/fonts/Roboto-MediumItalic.ttf"); //загрузка шрифта в базу данных шрифтов (Дальше работа в CSS)
}

void Widget::configurationGameAreButtons()
{
    QGridLayout *grid = qobject_cast <QGridLayout*> (ui->tab_2->layout());
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
        {
            QPushButton * btn = qobject_cast <QPushButton*> (grid->itemAtPosition(row,col)->widget());
            btn->setProperty("row", row);
            btn->setProperty("column",col);
            QObject::connect(btn,&QPushButton::clicked,this,&Widget::onGameAreaButtonClicked);

        }
}

void Widget::lockPlayer()
{
    if(player == 'X')
        playerLocked = false;
    else
        playerLocked = true;
}

void Widget::changeButtonStyleArea(int row, int column, QString str)
{
    QGridLayout *grid = qobject_cast <QGridLayout*> (ui->tab_2->layout());          //получаем указатель на нужный нам  tab_2
    QPushButton * btn = qobject_cast <QPushButton*> (grid->itemAtPosition(row,column)->widget());   //а после в tab_2 получаем нужный указатель на нужню кнопку
    btn->setStyleSheet(str);                                                            //устанавливаем стиль
}

void Widget::setGameAreaButton()        //стартовое инициализация кнопок игры
{
    for(int row = 0; row <3; row++)
        for(int col = 0; col < 3; col++)
            changeButtonStyleArea(row,col,StyleHeader::getBlankButtonStyle());
}

void Widget::start()
{
    setGameAreaButton();
    ui->tabWidget->setCurrentIndex(1);      //выбор нужной вкладки в программе tabWidget    (0 - Об игре , 1-Игра, и тд)
    for(int row = 0; row <3; row++)
        for(int col = 0; col < 3; col++)
            gamerArea[row][col] = '-';
    progress = 0;
    gameStart = true;
    stop = false;
    if(player!= 'X')
        computerInGame();
}


void Widget::chechGameStop()
{
    QString style;
    winner = '-';
    char symbols[2] = {'X','0'};
    for(int i =0; i<2; i++)
    {
        for(int row = 0; row < 3; row++)
        {
            if((gamerArea[row][0] == symbols[i]) && (gamerArea[row][1] == symbols[i]) && (gamerArea[row][2] == symbols[i]))
            {
                stop = true;
                winner = symbols[i];
                if(winner == player)
                {
                    if(player == 'X')
                        style = StyleHeader::getCrossVictoryStyle();
                    else
                        style = StyleHeader::getZeroVictoryStyle();
                }
                else
                {
                    if(player == 'X')
                        style = StyleHeader::getZeroLostStyle();
                    else
                        style = StyleHeader::getCrossLostStyle();
                }

                changeButtonStyleArea(row,0,style);
                changeButtonStyleArea(row,1,style);
                changeButtonStyleArea(row,2,style);
                return;
            }
        }
        for(int col = 0; col < 3; col++)
        {
            if((gamerArea[0][col] == symbols[i]) && (gamerArea[1][col] == symbols[i]) && (gamerArea[2][col] == symbols[i]))
            {
                stop = true;
                winner = symbols[i];
                if(winner == player)
                {
                    if(player == 'X')
                        style = StyleHeader::getCrossVictoryStyle();
                    else
                        style = StyleHeader::getZeroVictoryStyle();
                }
                else
                {
                    if(player == 'X')
                        style = StyleHeader::getZeroLostStyle();
                    else
                        style = StyleHeader::getCrossLostStyle();
                }

                changeButtonStyleArea(0,col,style);
                changeButtonStyleArea(1,col,style);
                changeButtonStyleArea(2,col,style);
                return;
            }
        }

        if((gamerArea[0][0] == symbols[i]) && (gamerArea[1][1] == symbols[i]) && (gamerArea[2][2] == symbols[i]))
        {
            stop = true;
            winner = symbols[i];
            if(winner == player)
            {
                if(player == 'X')
                    style = StyleHeader::getCrossVictoryStyle();
                else
                    style = StyleHeader::getZeroVictoryStyle();
            }
            else
            {
                if(player == 'X')
                    style = StyleHeader::getZeroLostStyle();
                else
                    style = StyleHeader::getCrossLostStyle();
            }

            changeButtonStyleArea(0,0,style);
            changeButtonStyleArea(1,1,style);
            changeButtonStyleArea(2,2,style);
            return;
        }

        if((gamerArea[0][2] == symbols[i]) && (gamerArea[1][1] == symbols[i]) && (gamerArea[2][0] == symbols[i]))
        {
            stop = true;
            winner = symbols[i];
            if(winner == player)
            {
                if(player == 'X')
                    style = StyleHeader::getCrossVictoryStyle();
                else
                    style = StyleHeader::getZeroVictoryStyle();
            }
            else
            {
                if(player == 'X')
                    style = StyleHeader::getZeroLostStyle();
                else
                    style = StyleHeader::getCrossLostStyle();
            }

            changeButtonStyleArea(0,2,style);
            changeButtonStyleArea(1,1,style);
            changeButtonStyleArea(2,0,style);
            return;
        }
    }

    if(progress == 9)
    {
        stop=true;
    }

}

void Widget::endGame()
{
    if(stop)
    {
        if(winner == player)
        {
            ui->labelMessage->setText("Победа!");
            ui->labelMessage->setStyleSheet(StyleHeader::getVictoryMessageStyle());
        }
        else if (winner == '-')
        {
            ui->labelMessage->setText("Ничья!");
            ui->labelMessage->setStyleSheet(StyleHeader::getNormalMessageStyle());
        }
        else
        {
            ui->labelMessage->setText("Поражение!");
            ui->labelMessage->setStyleSheet(StyleHeader::getLoseMessageStyle());
        }
        playerLocked = true;
        ui->startButton->setText("Играть");
        ui->startButton->setStyleSheet(StyleHeader::getGradientButtonStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStart = false;
    }
}


