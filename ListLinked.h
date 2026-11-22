#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

//Lista enlanzada todos los elementos van en nodos sueltos unidos por punteros 
template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first; //apuna al primer nodo
		int n;

	public:
		//Constructor, lista vacia
		ListLinked() {
			first = nullptr;
			n = 0;
		}

		//Inserta e en la posición pos
		void insert(int pos, T e) override {
			if(pos < 0 || pos > n) {
				throw std::out_of_range("Posición no valida");
			}
			if(pos == 0) {
				//el nuevo nodo apunta al antiguo primero
				first = new Node<T>(e, first);
			} else {
				//Busca el nodo anterior a pos
				Node<T>* prev = first;
				for(int i = 0; i < pos - 1; i++) {
					prev = prev->next;
				}
				//El nuevo apunta al que iba detras de prev, 
				//y prev apunta al nuevo
				prev->next = new Node<T>(e, prev->next);
			}
			n++;
		}

		//Inserta e al final
		void append(T e) override {
			insert(n, e);
		}

		//Insertar e al principio 
		void prepend(T e) override {
			insert(0, e);
		}

		//Elimina y devuelve el elemento de la pos
		T remove(int pos) override {
			if(pos < 0 || pos > n - 1) {
				throw std::out_of_range("Posición no válida");
			}
			Node<T>* borrar;
			if (pos == 0) {
				borrar = first;
				first = first->next; //el segundo pasa a ser el primero
			}else {
				Node<T>* prev = first;
				for(int i = 0; i < pos - 1; i++){
					prev = prev->next;
				}
				borrar = prev->next;
				prev->next = borrar->next; //"saltarse" el nodo q se borra
			}
			T elem = borrar->data; //guardar el dato antes de borrar
			delete borrar;
			n--;
			return elem;
		}

		//Devuelve el elemento de pos
		T get(int pos) override {
			if (pos < 0 || pos > n - 1) {
				throw std::out_of_range("Posicion no valida");
			}
			Node<T>* aux = first;
			for(int i = 0; i < pos; i++) {
				aux = aux->next; //avanza pos veces
			}
			return aux->data;
		}

		//Devuelve la posicion de la primra aparicion de e
		int search(T e) override {
			Node<T>* aux = first;
			int pos = 0;
			while(aux != nullptr) {
				if(aux->data == e) {
					return pos;
				}
				aux = aux->next;
				pos++;
			}
			return -1;
		}

		//true si no hay elementos
		bool empty() override {
			return n == 0;
		}

		//Numero de elementos
		int size() override {
			return n;
		}

		//Operador [], lista[pos] (hace lo mismo que get(pos))
		T operator[](int pos){
			return get(pos);
		}

		//Operador <<, recorre los nodos imprimiendo cada dato
		//preguntar: formato List => [1 2 3]?
		friend std::ostream& operator<<(std::ostream &out, ListLinked<T> &list) {
			out << "List => [";
			Node<T>* aux = list.first;
			while(aux != nullptr) {
				out << " "<< aux->data;
				aux = aux->next;
			}
			out<< " ]";
			return out;
		}
};

#endif
