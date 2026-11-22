#ifndef POINT2D_H
#define POINT2D_H

#include<ostream>

//punto en el plano (x, y)
//aqui solo se delcara
class Point2D{
	public:
		double x; 
		double y;

		//Constructor, si no se pasan valores: x=0 e y=0
		Point2D(double x = 0.0, double y = 0.0);

		//Distancia euclidea entre a y b
		static double distance(const Point2D &a, const Point2D &b);

		//p1 == p2, true si son iguales
		bool operator==(const Point2D &other);

		//p1 != p2 true si son distintos
		bool operator!=(const Point2D &other);

		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif
