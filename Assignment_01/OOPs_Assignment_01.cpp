/*
	ASSIGMENT -01(COMPLEX NUMBER)
Implement a class complex which represent the complex number data type .Implement the following operation
1)constructor including default constructor which create the complex number 0+0i
2)overloaded operator + to add two complex number.
3)overloaded operator * to multiply two complex number.
4)overloaded operator << and >> to print and read complex number.
*/
//***********************************************************************************//
#include <string>
#include <limits> //header file
#include <iostream>
using namespace std;

class complex // complex type class is define
{
private:
	float real, img;

public:
	// Acess control specifier is define i.e public (by default it is private)
	// consrtuctor is a member function used to intialize the object of class and called automatically when object is created!!
	// default contructor
	complex()
	{
		real = 0.0;
		img = 0.0;
	}
	// opretor overloading is done
	complex operator+(complex o)
	// operator overloading is always done inside the class
	//  operator is overloaded because In complex the addition is not as simple as 3+4 .
	// the real part must be added to real for that opreation is overloaded.
	{
		complex sum; // sum object is cretaed of same class
		sum.real = real + o.real;
		sum.img = img + o.img;
		return sum;
	}
	/*                  a1+(b1)i  and  a2+(b2)i   Multiplication->(a1a2-b1b2)+((a1b2)+(a2b1))i         */

	complex operator*(complex o)
	{
		complex multi;
		multi.real = (real * o.real) - (img * o.img);
		multi.img = (real * o.img) + (img * o.real);
		return multi;
	}

	complex operator-(complex o)
	{
		complex sub;
		sub.real = real - o.real;
		sub.img = img - o.img;
		return sub;
	}
	// FRIEND FUNCTION HAS RIGHT TO ACCESS ALL PRIVATE AND PROTECTED MEMBER OF THE CLAASS
	// insertion(<<) operator & extraction always prefered to be with friend function
	// in insertion and extraction operator friend function can be define inside or outside the class
	friend ostream &operator<<(ostream &c, complex &o) //<< belongs to ostream(output stream)
	{
		if (o.img < 0)
		{
			c << o.real << "" << o.img << "i"
		}
		else
		{
			c << o.real << "+" << o.img << "i";
		}
		return c;
	}
	friend istream &operator>>(istream &i, complex &o) //&i is nothing but the reference variable of istream class
	{
		cout << "";
		i >> o.real; //>>o.img;
		while (true)
		{
			if (i.fail())
			{
				i.clear();
				i.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.Enter the interger value again:" << endl;
				i >> o.real;
			}
			if (!i.fail())
				break;
		}
		cout << "";
		i >> o.img;

		while (true)
		{
			if (i.fail())
			{
				i.clear();
				i.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enetr the peoper integer.Enetr the value again:" << endl;
				i >> o.img;
			}
			if (!i.fail())
				break;
		}

		return i;
	}

}; // class ends here!!

int main()
{ // main function is statred

	complex c1, c2, c3; // complex number are called (c3 is the result)
	int choice;
	char Ans;
	{
		cout << "\n***MENU***";
		cout << "\n";
		cout << "##addition##";
		cout << "\n";
		cout << "##subtration##";
		cout << "\n";
		cout << "##multipication##";
		cout << "\n\n";
		cout << "enetr the choice:";
		cin >> choice;
		cout << "\n";
		cout << "enetr the real part & img part:";
		cin >> c1;
		cout << "enter the real part & img part:";
		cin >> c2;
		switch (choice)
		{ // swap case used whether to perform addition ,multipication & subtration
		case 1:
			c3 = c1 + c2; //  c3=c1.add(c2)
			cout << "\n";
			cout << "addition is:" << c3; // addition is performed
			break;
		case 2:
			c3 = c1 - c2;
			cout << "\n";
			cout << "substraction is:" << c3; // subtration is performed
			break;
		case 3:
			c3 = c1 * c2;
			cout << "\n";
			cout << "multipication is:" << c3; // multipication is performed
			break;
		default:
			cout << "0!!";
		}
	}
	return 0;
}
