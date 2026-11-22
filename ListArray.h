#ifndef LISTARRAY_H 
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;		//puntero al inicio del array	
		int max;	//tamaño del array
		int n;
		static const int MINSIZE = 2;

		//Cambia el tamaño del array
		void resize(int new_size) {
			T* nuevo = new T[new_size];
			for (int i = 0; i < n; i++){
				nuevo[i] = arr[i];
			}
			delete[] arr; 		//libera la memoria del array viejo
			arr = nuevo;
			max = new_size;

		}
	public:
		//Constructor: reserva un array de minsize elementos (lista vacia)
		ListArray() {
			arr = new T[MINSIZE];
			max = MINSIZE; 
			n = 0;
		}

		//Destructor: libera la memoria reservada con new[]
		~ListArray() override {
			delete[] arr;
		}

		//Insertar e en la posicion pos
		void insert(int pos, T e) override {
			if(pos < 0 || pos > n){
				throw std::out_of_range("Posicion no valida");
			}
			//Preguntar si esta lleno, se duplica?
			//if (n == 0){
			//	resize(max * 2);
			//}
			//Mover a la derecha los elemento desde pos hasta el final
			for(int i = n; i > pos; i--){
				arr[i] = arr[i - 1];
			}
			arr[pos] = e;
			n++;
		}

		//Insertar e al final (insertar en la posicion n)
		void append(T e) override{
			insert(n, e);
		}

		//Insertar e al principio 
		void prepend(T e) override{
			insert(0, e);
		}

		//Elimina y devuelve el elemento de pos 
		T remove(int pos) override {
			if(pos < 0 || pos > n - 1){
				throw std::out_of_range("Posicion no valida");
			}
			T elem = arr[pos];
			//Mover una posicion a la izquierda los elementos despues de pos
			for(int i = pos; i < n; i++){
				arr[i] = arr[i + 1];
			}
			n--;
			//preguntar si se queda 1/4 o menos ocupado, se reduce a la mitad?
			//if(n<=max/4 && max/2>=MINSIZE){
			//	resize(max/2);
			//}
			return elem;
		}

		//Devuelve el elemento de pos
		T get(int pos) override {
			if(pos < 0 || pos > n - 1){
				throw std::out_of_range("Posicion no valida");
			}
			return arr[pos];
		}

		//Devuelve la posicion de la primera aparicion de e
		int search(T e) override{
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

		//True si no hay elementos
		bool empty() override {
			return n == 0;
		}

		//Numero de elementos
		int size() override {
			return n;
		}

		//Operador [] (hace lo mismo que get(pos))
		T operator[](int pos){
			return get(pos);
		}

		//Operador << permite hacer std::cout lista;
		//preguntar por el formato, es List => [1 2 3]
		friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list){
			out << "List => [";
			for(int i = 0; i < list.n; i++){
				out<<" "<< list.arr[i];
			}
			out<< "]";
			return out;
		}
	};

#endif

