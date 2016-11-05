#include <iostream>
using namespace std; 
class ccomplex {
public:
	float real;
	float imag;
	ccomplex(float _real = 0.0f, float _imag = 0.0f);
	~ccomplex();
	ccomplex operator+(const ccomplex &rhs);
	ccomplex operator++();
	ccomplex operator++(int);
	bool operator==(const ccomplex &rhs);
	ccomplex operator+(const int real);
	friend ccomplex operator+(const int real, const ccomplex &rhs);
	
};

ccomplex operator+(const int re, const ccomplex &rhs)
{
	ccomplex toret;
	toret.real = re + rhs.real;
	toret.imag = rhs.imag;
	return toret;
}

bool ccomplex::operator==(const ccomplex &rhs)
{
	if (real == rhs.real && imag == rhs.imag)
		return true;
	else
		return false;
}
ccomplex ccomplex::operator++()
{
	real++;
	imag++;
	return *this;
}

ccomplex ccomplex::operator++(int)
{
	ccomplex toret = *this;
	(*this).real++; //this->real++ //real++
	imag++;
	return toret; 
}

ccomplex::ccomplex(float _real, float _imag)
{
	this->real = _real; 
	this->imag = _imag;
	cout << "\nCreated complex number\n";
}
ccomplex::~ccomplex()
{
	cout << "\nDestroying complex number\n";
}
ccomplex ccomplex::operator+(const ccomplex &rhs)
{
	ccomplex toret;
	toret.real = real + rhs.real;
	toret.imag = imag + rhs.imag;
	return toret;
}

ccomplex ccomplex::operator+(const int real)
{
	ccomplex toret = *this;
	
	toret.real += real;
	return toret;
}

int main()
{
	ccomplex c1, c2(5, 5), c3, c4;
	c3 = c1 + c2;
	//c3 = c1.operator+(c2);

	c4 = c2 + 5;
	//c4 = c2.operator+(5);
	c2 = 5 + c4; 
	++c4;
	c4++;
	if (c4 == c2)
		cout << "Equal"; 
	bool abool = c2 == c1; 
	return 0;
}