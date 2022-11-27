#include "mainscene.h"

#include <QApplication>
#include <QGraphicsView>
#include "../source/headers/Interpolation.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView view;
    view.setFixedSize(500,500);

    QGraphicsScene *scene = new QGraphicsScene(&view);
    //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой.
    //Теперь, раз это график, то построим координатные оси X и Y.

    QPen pen(Qt::black);//Просто выбираем цвет для карандашика
    scene->addLine(0,90,180,90,pen);//x
    scene->addLine(90,0,90,180,pen);//y

    pen = QPen(Qt::red);
    matrix mat = { {1,2}, {3,4} ,{3.5,3}, {6,7}};
    auto kofes = interpolation::get_range(mat);
    auto xes = get_column_matrix(mat,0);

    bool is_first = true;
    double x_before=0, y_before= 0;

    // INTERPOLATION
    for(double x=-10;x<10;x+=1) {
        auto y = interpolation::get_y(x,xes,kofes);
        if(!is_first)
            scene->addLine(x_before*25+90,90-y_before*25,x*25+90,90-y*25,pen);

        is_first=false;
        x_before = x;
        y_before = y;
    }

    //LAGRANGE
    x_before=0, y_before= 0;
    is_first = true;
    pen = QPen(Qt::blue);
    for(double x=-0.5;x<6.6;x+=0.1) {
        auto y = lagrange::get_y(x,mat);
        if(!is_first)
            scene->addLine(x_before*25+90,90-y_before*25,x*25+90,90-y*25,pen);

        is_first=false;
        x_before = x;
        y_before = y;
    }

    view.setScene(scene);
    view.show();

    return a.exec();
}
