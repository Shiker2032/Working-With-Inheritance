#include <iostream>
#include<string.h>

using namespace std;

class Person {
protected:
	string name;
	int age;
	char gender;
	float weight;
public:
	Person(string name, int age, char gender, float weight) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->weight = weight;
	}
	void setName(string newName) {
		this->name = newName;
	}
	void setAge(int newAge) {
		this->age = newAge;
	}
	void setWeight(float newWeight) {
		this->weight = newWeight;
	}
	void printInfo() {
		cout << "name: " << this->name << ",";
		cout << " age: " << this->age << ",";
		cout << " weight " << this->weight << ",";
	}
	string getName() {
		return this->name;
	}
};

class Student : public Person {
private:
	int enrollYear;
	string role = "Student";
public:
	Student(int enrollYear, string name, int age, char gender, float weight) :Person(name, age, gender, weight) {
		this->enrollYear = enrollYear;
	}
	int getEnrollYear() {
		return this->enrollYear;
	}
	void printInfo() {
		Person::printInfo();
		cout << " Enrolled years: " << this->enrollYear;
	}
	string getRole() {
		return this->role;
	}
};

class Teacher : public Person {
private:
	int enrollYear;
	string role = "Teacher";
public:
	Teacher(string name, int age, char gender, float weight) :Person(name, age, gender, weight) {
		this->enrollYear = enrollYear;
	}
	void printInfo() {
		Person::printInfo();
		cout << " Enrolled years: " << this->enrollYear;
	}
	string getRole() {
		return this->role;
	}
};

string authorize(string role) {
	if (role == "Teacher") {
		return "Teacher access";
	}
	if (role == "Student") {
		return "Student access";
	}
}


int main()
{

	//task #1 create example of studen inherited from person
	Student alex(2, "Alex", 18, 'm', 64);
	alex.printInfo();


	// task #2 create authoriztion system based on class type
	Teacher martin("Martin", 64, 'm', 72);
	cout << authorize(martin.getRole()) << endl;
	cout << authorize(alex.getRole());

}