#include <iostream>
#include<string>
using namespace std;
class Student {
private:
	string name;
	string group;
	int id;
public:
	Student() :name("_"), group("_"), id(0) {}
	Student(string n, string g, int id) : name(n), group(g), id(id) {}
	string Getname() {
		return name;
	}
	string Getgroup() {
		return group;
	}
	int Getid() {
		return id;
	}
	void Setid(int id_new) {
		id = id_new;
	}
	void Input() {
		cout << "Enter your name" << endl;
		cin >> name;
		cout << "Enter your group" << endl;
		cin >> group;
		cout << "Enter your id" << endl;
		cin >> id;

	}
	void Print() {
		cout << "Name__" << name << endl;
		cout << "Group__" << group << endl;
		cout << "Id__" << id << endl;
	}
	void main() {
		Student stud1;
		Student stud2("Sonia", "pmi-11", 1000);
		int n;
		cout << "Enter amount of students" << endl;
		cin >> n;
		Student* array = new Student[n];
		array[0] = stud1;
		array[1] = stud2;
	}
}