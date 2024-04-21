///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

string verschluesseln(char schluessel[2][26], string wort)
{
	for(int i=0; i < wort.length(); i++){
		wort[i] = schluessel[1][wort[i]-65];
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	for(int i=0; i < wort.length(); i++){
		for(int k=0; k<26; k++){
			if(wort[i] == schluessel[1][k]){
				wort[i] = schluessel[0][k];
				break;
			}
		}
	}

	return wort;
}

int main()
{
	 char supersecretLUT[2][26] = {	{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
	 								{'G', 'O', 'K', 'F', 'T', 'J', 'X', 'V', 'Y', 'A', 'S', 'D', 'M', 'N', 'H', 'I', 'Q', 'P', 'L', 'U', 'B', 'W', 'Z', 'C', 'R', 'E'}};

	
	string testwort;
	cout << "Enter one word in ALL CAPS:\n";
	getline(cin, testwort);
	cout << "\n";
	cout << testwort << "  ----->  ";
	cout << verschluesseln(supersecretLUT, testwort);
	cout << "  ----->  " << entschluesseln(supersecretLUT, verschluesseln(supersecretLUT, testwort)) << "\n";
	cout << "Enter one encoded word, for example \"VTDDHZHPDF\":\n";
	getline(cin, testwort);
	cout << "\n";
	cout << testwort << "  ----->  ";
	cout << entschluesseln(supersecretLUT, testwort) << "\n";
	return 0;
}
