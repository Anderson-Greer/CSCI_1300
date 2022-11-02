#ifndef POINT2D_H
#define POINT2D_H

#include <string>

using namespace std;

class Point2D {
    private:
        double x;
        double y;
        string label;

    public:
        Point2D();
        Point2D(double, double, string);

        double getX() const;
        double getY() const;
        string getLabel() const;

        void setX(double);
        void setY(double);
        void setLabel(string);

        void print();
        double distance(Point2D);
};

#endif