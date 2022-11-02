#include <string>
#include <iostream>
#include <cmath>
#include "Point2D.h"

using namespace std;

Point2D::Point2D() {
    x = 0.0;
    y = 0.0;
    label = "";
}

Point2D::Point2D(double x_pos, double y_pos, string label_str) {
    x = x_pos;
    y = y_pos;
    label = label_str;
}

double Point2D::getX() const {
    return x;
}

double Point2D::getY() const {
    return y;
}

string Point2D::getLabel() const {
    return label;
}

void Point2D::setX(double x_pos) {
    x = x_pos;
}

void Point2D::setY(double y_pos) {
    y = y_pos;
}

void Point2D::setLabel(string label_str) {
    label = label_str;
}

void Point2D::print() {
    if(label != "")
        cout << label << ": (" << x << "," << y << ")" << endl; 
        return;
    
    cout << "(" << x << "," << y << ")" << endl;
}

double Point2D::distance(Point2D point1) {
    return sqrt(pow((x - point1.getX()), 2) + pow((y - point1.getY()), 2));
}
