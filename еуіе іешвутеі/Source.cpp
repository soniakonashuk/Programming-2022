#include <iostream>
#include <vector>
using namespace std;

class Student {
private: 
	string fullname;

public:
	Student() :
	fullname(""){}//дефолтний конструктор
	Student(const string& name) : fullname(name) {}
	
	string getFullName() {
		return fullname;
	}

	void setFullName(string n) {
		fullname = n;
	}
	friend istream& operator >>(istream& is, const Student& student) {
		cout << "Enter your full name" << endl;//зсув вправо
	}
	friend ostream& operator<<(ostream& os, const Student& s) {
		os << s.fullname;
		return os;
	}//зсув вліво
};

class Group {
private:
	Student* students;
	int num_students;
	string group_name;
	int year_of_entry;

public:
	Group() : students(nullptr), num_students(0), group_name(""), year_of_entry(0) {}//дефолтний конструктор
	Group(const string& group_name, int year_of_entry) : students(nullptr), num_students(0), group_name(group_name), year_of_entry(year_of_entry) {}//конструктор копіювання
	Group(const Group& other) : students(new Student[other.num_students]), num_students(other.num_students), group_name(other.group_name), year_of_entry(other.year_of_entry) {
		for (int i = 0; i < num_students; i++) {
			students[i] = other.students[i];//оператор копіювання
		}
	}
	~Group() {
		delete[] students;//деструктор
	}
	string get_group_name() const {
		return group_name;
	}

	void set_group_name(const string& group_name) {
		this->group_name = group_name;
	}

	int get_year_of_entry() const {
		return year_of_entry;
	}

	void set_year_of_entry(int year_of_entry) {
		this->year_of_entry = year_of_entry;
	}
	Group& operator=(const Group& other) {//оператор присвоєння
		if (this != &other) {
			delete[] students;
			students = new Student[other.num_students];
			num_students = other.num_students;
			group_name = other.group_name;
			year_of_entry = other.year_of_entry;
			for (int i = 0; i < num_students; i++) {
				students[i] = other.students[i];
			}
		}
		return *this;
	}
	Student& operator[](int i) {
		return students[i];
	}

	friend ostream& operator<<(ostream& os, const Group& group) {
		os << "Group: " << group.group_name << endl;
		os << "Year of entry: " << group.year_of_entry << endl;
		os << "Number of students: " << group.num_students << endl;
		os << "Students:" << endl;
		for (int i = 0; i < group.num_students; i++) {
			os << "\t" << i + 1 << ". " << group.students[i] << endl;
		}
		return os;
	}
	const Student& operator[](int i) const {
		return students[i];
	}//індексування масиву 

};

int main() {

	}
