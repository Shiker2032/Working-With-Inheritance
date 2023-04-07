#include<iostream>
#include<string.h>

using namespace std;

class Function {
public:
	virtual void print(int x) {};
};

class Ellipse : public Function {
public:
	void print (int x) override 
	{
		cout << "Ellipse " << x << endl;
	}
};

class Hiperbola : public Function {
public:
	void print(int x) override
	{
		cout << "Hiperbola  " << x << endl;
	}
};

class Parabola : public Function {
public:
	void print(int x) override
	{
		cout << "Parabola  " << x << endl;
	}
};

int main () {
	int x = 39;

	Function* ptrEllips;
	Function* ptrHiperb;
	Function* ptrParab;
	
	Ellipse ellips;
	Hiperbola hiperbola;
	Parabola parab;

	ptrEllips = &ellips;
	ptrHiperb = &hiperbola;
	ptrParab = &parab;

	ptrEllips->print(x);
	ptrHiperb->print(x);
	ptrParab->print(x);
}

