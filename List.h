#ifndef LIST_H
#define LIST_H

#include<stdexcept>

//Solo dice que hace una lista no como, eso lo haran las clases hijas

template <typename T>
class List {
	public:
		//metodos virtuales puros

		//Inserta e en la posicion pos
		virtual void insert(int pos, T e) = 0;

		//Insertar e al final de la lista
		virtual void append(T e) = 0;

		//insertar e al final de la lista
		virtual void prepend(T e) = 0;

		//Elimina y devuelve el elemento de pos
		virtual T remove(int pos) = 0;

		//Devuelve elemento pos
		virtual T get(int pos) = 0;

		//Devuelve la posicion de la primera aparicion de e
		virtual int search(T e) = 0;

		//Devuelve true si la lista esta vacia 
		virtual bool empty() = 0;

		//Devuelve el numero de elementos
		virtual int size() = 0;

		//Destructor virtual: necesario para el polimorfismo 
		virtual ~List() = default;

	private:

};

#endif
