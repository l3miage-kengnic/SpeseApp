#ifndef INTEST
#define INTEST

#include<iostream>
#include<string>
#include"listTest.h"
using namespace std;




class singMese {
private:
	string mese;
	Item spese;
	Money totmese;
public:
	
	singMese(string a = " ") { mese = a;}

	string getmese() const { return mese; }
	Money gettot() const { return totmese; }
	Item getspese() const { return spese; }
	void setmese(string m) { mese = m; }
	void setspese(Item s) { spese = s; }
	void settot(Money t) { totmese = t; }

};

void printMese(singMese A1,LList<Item>& A2) {
	cout << A1.getmese()<<": ";
	cout << "spendimento Totale del mese: " << A1.gettot()<<"€"<<endl;

	int currpos = A2.currPos();
	A2.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << A2.getValue() << endl;
		A2.next();
	}
	cout << "| ";
	while (A2.currPos() < A2.length()) {
		cout << A2.getValue() << endl;
		A2.next();
	}
	cout << ">\n";
	A2.moveToPos(currpos); // Reset the fence to its original position
}
#endif
