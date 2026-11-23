#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"

//Figura (circulo) hederada de shape
class Circle : public Shape {
	private:
		Point2D center;
		double radius;

	public:
		//Constructor por defecto: color por defecto, centro (0,0) y radio 1
		Circle();

		//Constructor con parámetros
		Circle(std::string color, Point2D center, double radius);

		//Consultores y modificadores
		Point2D get_center() const;
		void set_center(Point2D p);
		double get_radius() const;
		void set_radius(double r);

		//Metodos heredados de Shape
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;

		friend std::ostream& operator<<(std::ostream &out, const Circle &c);

};

#endif
