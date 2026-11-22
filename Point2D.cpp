#include <ostream>
#include<cmath>
#include "Point2D.h"

//Constructor
Point2D::Point2D(double x, double y){
	this->x = x;
	this->y = y;
}

//Distanci euclidea, raiz cuadrada de dx² + dy²
double Point2D::distance(const Point2D &a, const Point2D &b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return std::sqrt(dx*dx + dy*dy);
}

//iguales si tienen la misma x y la misma y
bool Point2D::operator==(const Point2D &other){
	return x == other.x && y == other.y;
}

//Distintos 
bool Point2D::operator!=(const Point2D &other){
	return !(*this == other);
}

//preguntar el formato
std::ostream& operator<<(std::ostream &out, const Point2D &p){
	out<<"("<< p.x <<", "<< p.y << ")";
	return out;
}
