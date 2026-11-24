#ifndef DRAWING_H
#define DRAWING_H

#include "List.h"
#include "Shape.h"

//Dibujo = lista de figuras donde el orden importa
class Drawing{
	private:
		//El puntero a la interfaz List (es abstracta)
		//En el constructor se decide q lista usar
		List<Shape*>* shapes;

	public:
		Drawing(); //Reserva memoria
		~Drawing(); //libera la memoria de shapes

		void add_front(Shape* shape); //añade al inicio d la lista
		void add_back(Shape* shape); //añade al final de la lista

		void print_all(); 
		double get_area_all_circles(); //suma d las areas de todos los circulos
		void move_squares(double incX, double incY); //mueve solo los cuadrados

};

#endif
