#include <iostream>
#include <string>
using namespace std;

class Product {
private:
	string name;
	double price;
	double code;

public:
	int GetPrice() {
		return price;
	}
	string GetName() {
		return name;
	}
	friend istream& operator>>(istream& is, Product& product) {
		cout << "Enter name";
		is >> product.name >> product.price >> product.code;
	}
	int GetCode() {
		return code;
	}
	friend ostream& operator<<(ostream& os, Product& product) {
		os << product.name << product.price << product.code << endl;
		return os;
	}
	// добавити оператор булівській не дорівнює//
};



class Cart {
private:
	int cur;
	Product* products_;
	int* counts;
public:
	Cart() :cur(0) {
		Product newProduct[100];
		counts = new int[100];
	}
	void addProd(Product item, int count) { 
		products_[cur] = item;
		counts[cur] = count;
		cur++;
	}
	void removeProd(Product item) {
		int i = 0;
		cur--;
	//цикл в циклі cur це обмеження 
		//додавати товари віднімати список товарів роздрук 
	}
};
