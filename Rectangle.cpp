#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Rectangle.h"

// Método privado
bool Rectangle::check(Point2D* vertices) {
	double d01 = Point2D::distance(vertices[0], vertices[1]);
	double d23 = Point2D::distance(vertices[2], vertices[3]);
	double d12 = Point2D::distance(vertices[1], vertices[2]);
	double d30 = Point2D::distance(vertices[3], vertices[0]);
	return std::fabs(d01 - d23) < 1e-9 && std::fabs(d12 - d30) < 1e-9;
}

//Constructores y destructor
//Por defecto, color rojo y los 4 vértices del enunciado
Rectangle::Rectangle() : Shape() {
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}

// Con color y vértices. Se comprueba antes del new, para no perder memoria si lanza la excepción
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
	if (!check(vertices)) {
		throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
	}
	vs = new Point2D[N_VERTICES];
	for (int i = 0; i < N_VERTICES; i++) {
		vs[i] = vertices[i];
	}
}

// Constructor de copia, array nuevo y se copian los vértices uno a uno
Rectangle::Rectangle(const Rectangle &r) : Shape(r) {
	vs = new Point2D[N_VERTICES];
	for (int i = 0; i < N_VERTICES; i++) {
		vs[i] = r.vs[i];
	}
}

// Destructor, liberar el array creado con new[]
Rectangle::~Rectangle() {
	delete[] vs;
}

//Consultores
Point2D Rectangle::get_vertex(int ind) const {
	if (ind < 0 || ind > N_VERTICES - 1) {
		throw std::out_of_range("Índice de vértice no válido");
	}
	return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
	return get_vertex(ind);
}

//Modificadores
void Rectangle::set_vertices(Point2D* vertices) {
	if (!check(vertices)) {
		throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
	}
	for (int i = 0; i < N_VERTICES; i++) {
		vs[i] = vertices[i];
	}
}

// Asignación r1 = r2, copiar color y vértices (los dos ya tienen su propio array de 4)
Rectangle& Rectangle::operator=(const Rectangle &r) {
	if (this != &r) { // evitar copiarse a sí mismo (r1 = r1)
		color = r.color;
		for (int i = 0; i < N_VERTICES; i++) {
			vs[i] = r.vs[i];
		}
	}
	return *this; // permite encadenar: r1 = r2 = r3
}

//Métodos heredados de Shape
// Área = d(v0,v1) * d(v1,v2)
double Rectangle::area() const {
	return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

// Perímetro = 2 * (d(v0,v1) + d(v1,v2))
double Rectangle::perimeter() const {
	return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

// Mover el rectángulo = mover sus 4 vértices
void Rectangle::translate(double incX, double incY) {
	for (int i = 0; i < N_VERTICES; i++) {
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

// print aprovecha el operador <<
void Rectangle::print() {
	std::cout << *this << std::endl;
}

//preguntar formato de impresión
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
	out << "[Rectangle: color = " << r.color;
	for (int i = 0; i < Rectangle::N_VERTICES; i++) {
		out << "; v" << i << " = " << r.vs[i];
	}
	out << "]";
	return out;
}
