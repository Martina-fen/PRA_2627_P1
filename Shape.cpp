#include "Shape.h"
#include <stdexcept>
#include <string>

//Constructor por defecto (color rojo)
Shape::Shape() : color("red"){

}

//Constructor con color
Shape::Shape(std::string color) {
	set_color(color);
}

//Devuelve el color
std::string Shape::get_color() const{
	return color;
}

//Cambiar el color 
void Shape::set_color(std::string c){
	if(c == "red" || c == "green" || c == "blue"){
		color = c;
	} else{
		throw std::invalid_argument("Color no valido: " + c);
	}
}
