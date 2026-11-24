#include "Drawing.h"
#include "ListLinked.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

//Constructor elige ListLinked como implementacion d la lista
Drawing::Drawing() {
	shapes = new ListLinked<Shape*>();
}

//Destructor, libera la lista
Drawing::~Drawing(){
	for(int i = 0; i < shapes->size(); i++){
		delete shapes->get(i);
	}
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}

//Reaprovecha el print d cada figura
void Drawing::print_all(){
	std::cout << "Drawing contents:" << std::endl;
	for(int i = 0; i < shapes->size(); i++){
		shapes->get(i)->print();
	}
}

//Si la figura es un circulo devuelve el puntero, sino devuelve null
double Drawing::get_area_all_circles(){
	double total = 0;
	for (int i = 0; i < shapes->size(); i++){
		Circle* c = dynamic_cast<Circle*>(shapes->get(i));
		if(c != nullptr){
			total += c->area();
		}
	}
	return total;
}

//Igual pero con cuadrados
void Drawing::move_squares(double incX, double incY) {
	for(int i = 0; i < shapes->size(); i++){
		Square* s = dynamic_cast<Square*>(shapes->get(i));
		if (s != nullptr) {
			s->translate(incX, incY);
		}
	}
}
