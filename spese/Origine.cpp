#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<sstream>

#include"listTest.h"
#include"llist.h"
#include"Intestazione.h"

int main() {
	int gg,mmo,aa,mm,AA ;

	cout << "data di oggi? ";
	cout << "gg: "; cin >> gg;
	cout << "/ mm:"; cin >> mmo;
	cout << "/ aa: "; cin >> aa;
	while(gg < 1 || gg>31 || mmo < 1 || mmo>12 || aa>3000){
		cout << "invalid date, enter a correct date"<<endl;
		cout << "data di oggi? "<<endl;
	    cout << "gg: "; cin >> gg; 
		cout << "/ mm:"; cin >> mmo;
		cout << "/ aa: "; cin >> aa;
	}
	
	
	cout << "Mese e Anno che si vuole esplorare(in numero): "; cout << "Mese: "; cin >> mm; cout<<"  " << "Anno: "; cin >> AA;
	if (AA < 2020) { cout << "Hey the programme wasn't yet exists at this date "; return 0; }
	if (AA>3000 || mm < 1 || mm>12) { cout << "invalid date"; return 0; }
	singMese* A = new singMese[12];

	A[0].setmese("Gennaio"); A[1].setmese("Febbraio"); A[2].setmese("Marzo"); A[3].setmese("Aprile");
	A[4].setmese("Maggio"); A[5].setmese("Giugno"); A[6].setmese("Luglio"); A[7].setmese("Agosto");
	A[8].setmese("Settembre"); A[9].setmese("Ottobre"); A[10].setmese("Novembre"); A[11].setmese("Dicembre");

	LList<Item>* A2 = new LList<Item>[12];

	ifstream file("depenses.txt");
	int giorno, mesenum, anno;
	string d1, d2, d3;
	Money importo;
	int euro, cents;
	string str1, str2;
	string causale;
	if (file.is_open()) {
		while(getline(file,d1,'/')){
			istringstream conv1(d1);
			conv1 >> giorno;
			getline(file, d2, '/');
			istringstream conv2(d2);
			conv2 >> mesenum;
			getline(file, d3, ';');
			istringstream conv3(d3);
			conv3 >> anno;

			getline(file, str1, ',');
			istringstream conv4(str1);
			conv4 >> euro;
			getline(file, str2, ';');
			istringstream conv5(str2);
			conv5 >> cents;
			Money importo(euro, cents);

			getline(file, causale);

			Item it(giorno, mesenum, anno);
			it.setmoney(importo); it.setcausale(causale);
			if (it.getanno() == AA) {
				A2[mesenum - 1].append(it);
				A[mesenum - 1].settot(A[mesenum - 1].gettot() + it.getmoney());
			}
		}
	}file.close();
	singMese A1 = A[mm-1]; 
	LList<Item> A2s;
	Money TotAnno;
	for (A2[mm-1].moveToStart(); A2[mm-1].currPos() < A2[mm-1].length(); A2[mm-1].next()) {
		Item it = A2[mm-1].getValue();
		A2s.append(it); 
	}
	for(int i=0;i<12;i++){ TotAnno = TotAnno + A[i].gettot(); }
	
	printMese(A1, A2s);
	cout <<endl<< "spendimento Totale nell'anno " << AA<<": " << TotAnno << "€" << endl;
	cout << endl << "Registrazione al giorno: " << gg << "/" << mm << "/" << aa;

}