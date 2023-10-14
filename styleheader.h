#ifndef STYLEHEADER_H
#define STYLEHEADER_H

#include <QString>

class StyleHeader
{
public:
    static QString getMainWidgetStyle();        //установка основного стиля (бэкграунд)
    //static QString getStartButtonsStyle();      //установка стиля кнопок
    static QString getGradientButtonStyle();    //установка градиента на стиль кнопок

    static QString getlefftButtonStyle();
    static QString getRightButtonStyle();       //работа с двумя кнопками левой и правой, отвечающие за выбор игрока
    static QString getlefftActiveButtonStyle();
    static QString getRightActiveButtonStyle();    //работа с активными левой и правой кнопкой

    static QString getTabWidgetStyle();         //устанавливаем стиль на tabWidget
    static QString getTabWidgetPainStyle();

    static QString getBlankButtonStyle();       //пуская кнопка
    static QString getCrossNormanlStyle();      //нажатый крестик
    static QString getCrossVictoryStyle();      //победный крестик
    static QString getCrossLostStyle();         //пораженный крестик

    static QString getZeroNormanlStyle();      //нажатый нолик
    static QString getZeroVictoryStyle();      //победный нолик
    static QString getZeroLostStyle();         //пораженный нолик

    static QString getNormalMessageStyle();     //информация о ничье
    static QString getVictoryMessageStyle();    //информация о победе
    static QString getLoseMessageStyle();       //информация о поражении

    static QString getButtonRed();
    static QString getLabelTab2();
};

#endif // STYLEHEADER_H
