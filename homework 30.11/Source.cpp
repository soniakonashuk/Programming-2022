//Визначити тип чотирикутник за координатами чотирьох його вершин. Крім необхідних методів (конструкторів, введення-виведення,...) визначити метод знаходження його периметру, метод перевірки, чи є заданий чотирикутник прямокутником, квадратом, оператор < - порівняння двох чотирикутників за периметром. Ввести дані про 10 чотирикутників. Посортувати їх (використовуючи оператор<) у порядку спадання периметрів. Видрукувати список тих чотирикутників, що є квадратами і окремо тих, що є прямокутниками.
#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	double x, y;
public:
	Point() { x = 0; y = 0; }
	Point(double xx,double yy) : x(xx),y(yy){}
};
class Quadrangle {
	Point x, x1, y, y1;
	Quadrangle(Point xx,Point xx1,Point yy,Point yy1):x(xx),x1(xx1),y(yy),y1(yy1) {}
	double side(Point A, Point B) {
		return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	}

	double perimetr(double a, double b) {
		return 2*(a + b);
	}


	

	




};


// Point A point B

int main() {

}