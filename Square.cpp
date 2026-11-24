#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Square.h"

//Metodo privado
//Cuadrado válido, los cuatro lados con la misma longitud
bool Square::check(Point2D* vertices) {
	double d01 = Point2D::distance(vertices[0], vertices[1]);
	double d12 = Point2D::distance(vertices[1], vertices[2]);
	double d23 = Point2D::distance(vertices[2], vertices[3]);
	double d30 = Point2D::distance(vertices[3], vertices[0]);
	return std::fabs(d01 - d12) < 1e-9 &&
		std::fabs(d12 - d23) < 1e-9 &&
		std::fabs(d23 - d30) < 1e-9;
}

//Constructores
//Por defecto Rectangle reserva array y pone color
//aqui solo se cambian los vertices por los del cuadrado
Square::Square() : Rectangle() {
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1,-1);
	vs[3] = Point2D(-1,-1);
}

//se cambian el color y los vertices
Square::Square(std::string color, Point2D* vertices) : Rectangle(){
	set_color(color);
	set_vertices(vertices);
}

//Metodos reescritos
//Se comprueba que sea un cuadrado
void Square::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("Provided vertices do not build a valid square!");
	}
	for(int i= 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

//print aprobecha el operador <<
void Square::print(){
	std::cout << *this << std::endl;
}

//preguntar formato de impresion
std::ostream& operator<<(std::ostream &out, const Square &square){
	out << "[Square: color = " << square.get_color();
	for( int i = 0; i < Square::N_VERTICES; i++){
		out << "; v" << i << " = " << square[i];
	}
	out << "]";
	return out;
}
