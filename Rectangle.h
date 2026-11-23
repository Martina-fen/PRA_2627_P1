#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
	private:
		//Comprueba si los cuatro vertices forman un rectangulo válido
		static bool check(Point2D* vertice);

	protected:
		Point2D* vs; //Array dinamico con los 4 vertices (v0, v1, v2, v3)

	public:
		static int const N_VERTICES = 4; 

		//Constructor por defecto, color por defecto
		//v0=(-1,0.5), v1=(1,0.5), v2=(1,-0.5), v3=(-1,-0.5)
		Rectangle();

		//constructor con color y 4 vertices
		Rectangle(std::string color, Point2D* vertices);

		//Constructor de copia (copia los vertices)
		Rectangle(const Rectangle &r);

		//Destructor
		~Rectangle();

		//Devuelve el vertice ind
		Point2D get_vertex(int ind) const;

		//hace lo mismo que get_vertex
		Point2D operator[](int ind) const;

		//Cambia los 4 vertices
		virtual void set_vertices(Point2D* vertices);

		//Asignacion de copia segura r1=r2
		Rectangle& operator=(const Rectangle &r);

		friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

		//Metodos heredados
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;
};

#endif
