#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.141592653589793238;
class Circle {
private:
	double radius;
	string color;
public:
	Circle () {}
	Circle( double r, string c): radius(r),color(c) {}


	void set_color(string c) {
		color = c;
	}

	// повертаємо колір круга
	string get_color() {
		return color;
	}

	// метод для визначення площі круга
	double calculateSquare() {
		return PI * pow(radius, 2);
	}

	double get_radius() {
		return radius;
	}

	void printInfo() {
		cout << "R: " << radius << " " << "COLOR: " << color << endl;
	}
};

int main() {
	// вводимо дані про 7 кілець
	Circle circles[7] = {
	   Circle(1, "blue"),
	   Circle(2, "green"),
	   Circle(3, "blue"),
	   Circle(4, "yellow"),
	   Circle(5, "black"),
	   Circle(6, "blue"),
	   Circle(7, "grey")
	};

	// виводемо площі всіх кругів з синім кольором
	double A[7] = {};
	for (int i = 0; i < 7; i++) {
		A[i] = circles[i].calculateSquare();
		if (circles[i].get_color() == "blue") {
			cout << "Square of blue colors circles" << " " << circles[i].calculateSquare() << endl;
		}
	}

	// шукаємо найбільшу площу
	double maxSquare = 0;
	int maxIndex = 0;
	for (int i = 0; i < 7; i++)
	{
		if (circles[i].calculateSquare() > maxSquare)
		{
			maxSquare = circles[i].calculateSquare();
			maxIndex = i;
		}
	}
	cout << "Circle with max area: " << circles[maxIndex].get_color() << endl;

	int n;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 0; i < 7; i++) {
		if (circles[i].get_radius() < n) {
			circles[i].set_color("red");
		}
	}

	for (int i = 0; i < 7; i++) {
		circles[i].printInfo();
	}
}