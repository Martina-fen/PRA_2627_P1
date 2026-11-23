#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include"Point2D.h"

//Figura geometrica abstracta
class Shape{
	protected:	//Solo lo ven esta clase y las hijas
		std::string color;

	public:
		//Constructor por defecto, color rojo
		Shape();

		//Constructor con color
		Shape(std::string color);

		//Destructor virtual (necesario para el polimorfismo)ç
		virtual ~Shape() = default;

		//Devuelve el color
		std::string get_color() const;

		//Cambia el color 
		void set_color(std::string c);

		//Metodos virtuales puros
		virtual double area() const=0;
		virtual double perimeter() const=0;
		virtual void translate(double incX, double incY) = 0;
		virtual void print()=0;
};

#endif

