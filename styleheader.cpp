#include "styleheader.h"


QString StyleHeader::getMainWidgetStyle()
{
    return "QWidget"
           "{background-image: url(:/resImg/img/images/bg.png)"
           "};";

    //устанавливает картинку фона
}

QString StyleHeader::getGradientButtonStyle()
{
    return "QPushButton "
           "{"
           "background: none;"
           "border: none;"
           "border-radius: 19px;"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 164, 255, 255), stop:1 rgba(255, 255, 255, 255));"
           "font-family: 'Roboto Medium';"
           "font-size: 16px;"
           "min-height: 38px;"
           "color: black;}"
           "QPushButton::hover"
           "{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 101, 157, 255), stop:1 rgba(255, 255, 255, 255));"
           "color: white;}"
           "QPushButton::pressed"
           "{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 24, 37, 255), stop:1 rgba(255, 255, 255, 255));"
           "color:black;}";

    //устанавливаем градиент для некоторых кнопок
    //background: none; - означает удаление основного фона с картиной, так как без него он перекрывает градиент
    //border: none; - аналогично
}

QString StyleHeader::getButtonRed()
{
    return "QPushButton "
           "{"
           "background: none;"
           "border: none;"
           "border-radius: 19px;"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
           "font-family: 'Roboto Medium';"
           "font-size: 16px;"
           "min-height: 38px;"
           "color: black;}"
           "QPushButton::hover"
           "{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(182, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
           "color: white;}"
           "QPushButton::pressed"
           "{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(93, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
           "color:black;}";

}

QString StyleHeader::getLabelTab2()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "color: #ffffff;"
           "font-style:italic;"
           "}";
}

QString StyleHeader::getlefftButtonStyle()
{
    return "QPushButton{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 164, 255, 255), stop:1 rgba(255, 255, 255, 255));"
           "background-image: url(:/resImg/img/images/cross_small.png);"
           "background-repeat: no-repeat;"
           "background-position: center center;"
           "border: 1px solid #333;"
           "border-top-left-radius: 5px;"
           "border-bottom-left-radius: 5px;"
           "min-height: 38px;"
           "}";
}

QString StyleHeader::getRightButtonStyle()
{
    return "QPushButton{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 164, 255, 255), stop:1 rgba(255, 255, 255, 255));"
           "background-image: url(:/resImg/img/images/zero_small.png);"
           "background-repeat: no-repeat;"
           "background-position: center center;"
           "border: 1px solid #333;"
           "border-left: none;"
           "border-top-right-radius: 5px;"
           "border-bottom-right-radius: 5px;"
           "min-height: 38px;"
           "}";
}

QString StyleHeader::getlefftActiveButtonStyle()
{
    return "QPushButton{"
           "background-color: #2d313b;"
           "background-image: url(:/resImg/img/images/cross_small.png);"
           "background-repeat: no-repeat;"
           "background-position: center center;"
           "border: 1px solid #333;"
           "border-top-left-radius: 5px;"
           "border-bottom-left-radius: 5px;"
           "min-height: 38px;"
           "}";
}

QString StyleHeader::getRightActiveButtonStyle()
{
    return "QPushButton{"
           "background-color: #2d313b;"
           "background-image: url(:/resImg/img/images/zero_small.png);"
           "background-repeat: no-repeat;"
           "background-position: center center;"
           "border: 1px solid #333;"
           "border-left:none;"
           "border-top-right-radius: 5px;"
           "border-bottom-right-radius: 5px;"
           "min-height: 38px;"
           "}";
}

QString StyleHeader::getTabWidgetStyle()
{
    return "QTabWidget{"
           "border: none;"
           "}"
           "QTabWidget::pane{"
           "border: 1px solid #222;"
           "border-radius: 5px;"
           "}";

    //изменение цвета StyleSheet кнопок
    //в данной логике, мы устанавливаем стиль для кнопки, а дальше при вызово определенной функции, изменения будут наладываться
    //Сначала задали стиль обычной кнопки (текст цвет-красный, фон- серый, граница 1 пик- темносерый), а после для кнопки при наведении (текст-белый, фон - темносерый)
}

QString StyleHeader::getTabWidgetPainStyle()
{
    return  "QWidget#tab_2{"
           "background: none;"
           "background-color: rgb(33,40,50);"
           "}";
}

QString StyleHeader::getBlankButtonStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: #272D39;"
           "}"
           "QPushButton::hover{"
           "    background: #373D49;"
           "}";
}

QString StyleHeader::getCrossNormanlStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: #272D39 url(:/resImg/img/images/cross_large.png) no-repeat center center; "
           "}"
           "QPushButton::hover{"
           "    background-color: #373D49;"
           "}";
}

QString StyleHeader::getCrossVictoryStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: green url(:/resImg/img/images/cross_large.png) no-repeat center center;"
           "}"
           "QPushButton::hover{"
           "    background-color: darkgreen;"
           "}";
}

QString StyleHeader::getCrossLostStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: red url(:/resImg/img/images/cross_large.png) no-repeat center center;"
           "}"
           "QPushButton::hover{"
           "    background-color: darkred;"
           "}";
}

QString StyleHeader::getZeroNormanlStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: #272D39 url(:/resImg/img/images/zero_large.png) no-repeat center center; "
           "}"
           "QPushButton::hover{"
           "    background-color: #373D49;"
           "}";
}

QString StyleHeader::getZeroVictoryStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: green url(:/resImg/img/images/zero_large.png) no-repeat center center;"
           "}"
           "QPushButton::hover{"
           "    background-color: darkgreen;"
           "}";
}

QString StyleHeader::getZeroLostStyle()
{
    return "QPushButton{"
           "border:none;"
           "background: red url(:/resImg/img/images/zero_large.png) no-repeat center center;"
           "}"
           "QPushButton::hover{"
           "    background-color: darkred;"
           "}";
}

QString StyleHeader::getNormalMessageStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "background: none;"
           "color: #ffffff"
           "}";
}

QString StyleHeader::getVictoryMessageStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "background: green;"
           "border: 1px solid #1C7C32;"
           "color: #ffffff"
           "}";
}

QString StyleHeader::getLoseMessageStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "background: red;"
           "border: 1px solid #1C7C32;"
           "color: #ffffff"
           "}";
}
