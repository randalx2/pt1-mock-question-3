///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name: Praneel Misthry
// Student No: 202515355
// Date: 16 March 2016
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(){ num = 1; denom = 1; }  //Added a default constructor
	Fraction(int n, int d) : num(n), denom(d) { };
	~Fraction(){};
	void print() { cout << num << "/" << denom << endl; };

	//overloading the greater than operator as non member function using friendship
	friend bool operator > (Fraction f1, Fraction f2){
		bool temp = 0;
		if (f1.num*f2.denom > f2.num*f1.denom)
		{
			temp = 1;
			return temp;
		}
		return temp;
	}

	Fraction add(int n, Fraction f)  //Overloading fraction and integer addition
	{
		/*Fraction temp;
		temp.num = n*f.denom + f.num;
		temp.denom = f.denom;*/

		int tnum, tden;
		tnum = n*f.denom + f.num;
		tden = f.denom;

		return Fraction (tnum, tden); 		
	}

	Fraction add(Fraction f, int n)
	{
		/*Fraction temp;
		temp.num = n*f.denom + f.num;
		temp.denom = f.denom;

		return temp;*/   //NB THIS METHOD IS ALSO CORRECT

		int tnum, tden;
		tnum = n*f.denom + f.num;
		tden = f.denom;               //This method is preferable if you have to call a gcd function
		                              //for the numerator and denominar as you would need both to be available already

		return Fraction(tnum, tden);

	}
};

//Designing main driver code

int main()
{
	//Demonstrating the greater than overloading operator
	Fraction f1(1, 2);
	f1.print();

	Fraction f2(1, 4);
	f2.print();

	Fraction f3;
	f3.print();

	if (f1 > f2)
	{
		cout << "Fraction f1 is greater than f2" << endl;
	}
	else
	{
		cout << "Fraction f2 is less than or equal to f1" << endl;
	}

	//Demonstrating addition functions
	f3 = f1.add(1, f2);
	f3.print();

	f3 = f2.add(2, f1);
	f3.print();

	f3 = f1.add(1, f2);
	f3.print();

	system("PAUSE");
	return 0;
}