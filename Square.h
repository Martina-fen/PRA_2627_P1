#ifndef SQUARE_H
#define SQUARE_H

#include <ostream>
#include "Rectangle.h"

//Cuadrado es un rectangulo con los 4 lados iguales
//No usa atributos, usa los de Rectangle
class Square : public Rectangle {
	private:
		//Comprueba si los 4 vertices forman un cuadrado valido
		static bool check(Point2D* vertices);

	public:
		//Construstor por defecto
		//v0=(-1,1), v1=(1,1), v2=(1,-1), v3=(-1,-1)
		Square();

		//Constructor con color y vertices
		Square(std::string color, Point2D* vertices);

		//Metodos de rectangle q se sobreescriben
		void set_vertices(Point2D* vertices) override;
		void print() override;
		friend std::ostream& operator<<(std::ostream &out, const Square &square);

};

#endif
