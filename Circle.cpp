#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Circle.h"

const double PI = 3.141592;

//Constructor por defecto
Circle::Circle() : Shape(), center(0,0), radius(1){

}

//Constructor con parametros (el color lo gestiona Shape) y el radio set_radius
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
	this->center = center;
	set_radius(radius);
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p) {
	center = p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	if(r < 0) {
		throw std::invalid_argument("El radio no puede ser negativo");
	}
	radius = r;
}

//Area = p1 * r² (pow(base, exponente) de <cmath>
double Circle::area() const {
	return PI * std::pow(radius, 2);
}

//Perimetro = 2 * PI * r
double Circle::perimeter() const{
	return 2 * PI * radius;
}

//Mover el circulo (mover su centro)
void Circle::translate(double incX, double incY) {
	center.x += incX;
	center.y = incY;
}

//print aprovecha el operador <<
void Circle::print(){
	std::cout << *this << std::endl;
}

//preguntar formato
std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "[Circle: color = " << c.color << "; center = " << c.center 
		<< "; radius = " << c.radius << "]";
	return out;
}
