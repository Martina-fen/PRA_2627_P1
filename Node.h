#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next; //puntero al siguiente nodo
		
		//Constructor, si no se le pasa next, vale nullptr
		Node(T data, Node<T>* next = nullptr) {
			this->data= data; //this->dara = el atributo; data = el parametro
			this->next= next;
		}

		//Operador <<, imprime solo el dato del nodo
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node.data;
			return out;
		}
};

#endif
