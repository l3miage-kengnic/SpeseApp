// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.


#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
//#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"



class Money {
private:int euros, cents;
public:Money(int e = 0, int c = 0) { euros = e; cents = c; }
	  int get_euros() { return euros; }
	  void set_euros(int e) { euros = e; }
	  int get_cents() { return cents; }
	  void set_cents(int c) { cents = c; }
};

Money operator+(Money m1, Money m2) {
	Money tmp;
	int tpe = m1.get_euros() + m2.get_euros();
	int tpc = m1.get_cents() + m2.get_cents();
	if (tpc >= 100) { tpe++; tpc = tpc - 100; }
	tmp.set_euros(tpe);
	tmp.set_cents(tpc);
	return tmp;

}

ostream& operator<<(ostream& os, Money m) {

	os << m.get_euros();
	os << ",";
	os << m.get_cents();
	return os;
}





class Item {
private:
	int giorno, mesenum, anno;
	Money importo;
	string causale;
public:
	Item(int a = 0, int b = 0, int c = 0) { giorno = a; mesenum = b; anno = c; causale = " "; }

	int key() const { return mesenum; }
	int getgiorno() const { return giorno; }
	int getanno() const { return anno; }
	Money getmoney() const { return importo; }
	string getcausale() const { return causale; }
	void setmesenum(int m) { mesenum = m; }
	void setmoney(Money m) { importo = m; }
	void setcausale(string s) { causale = s; }


};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.getgiorno() << "/" << i.key() << "/" << i.getanno() << "; " << i.getmoney() << "; " << i.getcausale();
}

// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos() < L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}



#endif


