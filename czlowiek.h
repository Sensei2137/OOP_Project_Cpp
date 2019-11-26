#ifndef CZLOWIEK_H
#define CZLOWIEK_H
#include <iostream>
#include <cstdlib>
using namespace std;
class czlowiek
{

	protected:
		string imie, nazwisko;
		float konto;
		int id;
	
			public:
			
				virtual void ustaw_dane(string a, string b);
	virtual void ustaw_konto(float c);
	virtual void przedstaw()=0;
	string get_imie();
	string get_nazwisko();
	float get_konto();
	virtual void ustaw_id(int i);
	int get_id();
};

#endif
