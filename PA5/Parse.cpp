#include "Rational.h"
#include "Parse.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

istream& operator >> (istream& is, rational& r)
{
	int a,b;
	is >> a;
	is.ignore(1);
	is >> b;
	r.setNumerator(a);
	r.setDenominator(b);
	return is;
}

istream& operator >> (istream& is, ParseTree& t)
{
	rational a;
	rational b;
	char c;

	is >> a >> b >> c;
	ParseTree m(&a);
	ParseTree n(&b);

	t(&m, &n, &c);
	return is;
}





int main()
{
	rational half;
	rational third;
	rational crazy;

	cin >> half >> third;

	ParseTree pt1(&half);
	ParseTree pt2(&third);
	ParseTree l(&pt1, &pt2, '*');

	cout << half.toDouble() << endl;
	cout << third.toDouble() << endl;

	cout << l.eval().toDouble() << endl;
}
