﻿#include <iostream>
#include<string.h>

using namespace std;

//task # 1 ======================================================================

class Shape {
public:
	virtual double area() = 0;
};

class Parallelogram : public Shape {
protected:
	double _a, _h;
public:
	Parallelogram(double a, double h)
	{
		this->_a = a;
		this->_h = h;
	};

	double area () override 
	{
		return this->_a * this->_h;
	}
};
class Circle : public Shape {
protected: 
	double _r;
public:
	Circle(double r) 
	{
		this->_r = r;
	}

	double area () override 
	{
		return 3.14 * std::pow(this->_r, 2);
	}
};

class Reactangle : public Parallelogram {
public: 
	Reactangle(double a, double h) : Parallelogram(a, h) {};

	double area() override 
	{
		return (this->_a * this->_h);
	}
};

class Square : public Parallelogram {
public:
	Square(double a, double h) : Parallelogram(a, h) {};

	double area() override
	{
		return std::pow(this->_a, 2);
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(double a, double h) : Parallelogram(a, h) {};

	double area() override
	{
		return this->_a * this->_h;
	}
};

// task #2 ==================================================================================

class Car { //class Car
protected: 
	string _company;
	string _model;
	
public:
	Car() { cout << "Car::Car() called" << endl; } //Base constructor
	Car(string company, string model) 
	{
		this->_company = company;
		this->_model = model;
		cout << "Car::constructor called" << endl;
	}

	void printInfo() 
	{
		cout << "info";
	}
};

class PassangerCar : virtual public Car { //class PassangerCar inherits Car
public:
	PassangerCar(string company, string model) :Car(company, model) {
		cout << "PassangerCar::constructor called" << endl;
	}
};

class Bus : virtual public Car { //class Bus inherits Car
public:
	Bus(string company, string model) :Car(company, model) {
		cout << "Bus::constructor called" << endl;
	}
};

class MiniVan : public PassangerCar, public Bus { //class MiniVan inherits PassangerCar and Bus
public:
	MiniVan(string company, string model) :Bus(company, model), PassangerCar(company, model) {
		cout << "MiniVan::constructor called" << endl;
	}
};

int main() {
	Parallelogram par(3, 10);
	Circle circ(25);
	Reactangle rect(2, 4);
	Square sqr(4, 2);
	Rhombus rhomb(3, 5);	

	cout << "Parallelogram" << par.area() << endl;
	cout << "Circle" << circ.area() << endl;
	cout << "Reactangle" << rect.area() << endl;
	cout << "square" << sqr.area() << endl;
	cout << "Rhombus" << rhomb.area() << endl;	

	cout << "\n==============Task 2==============" << endl;

	MiniVan batmobile("Wayne inc", "tank");	
};