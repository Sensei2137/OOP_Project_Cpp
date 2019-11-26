#include <iostream>
#include <cstdlib>
#include "czlowiek.h"
#include "programista.h"
#include "stazysta.h"

#include <limits>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;
vector <czlowiek*> tab;
void wyj2(){
	
	
		cout << "Nie podales prawidlowych danych, zamykam!\n";
					exit(0);
	
}
void wyj()
{
	if (!cin.good()) 
					{
					cout << "Nie podales prawidlowych danych, zamykam!\n";
					exit(0);
					}
}



template <class T>
class kasa{
	protected:
		int w; string imie, nazwisko;
		float konto,zrzuta,b;
	
	public:
		float operator+=(float war)
	{
		b += war;
		return b;
	}
	float operator-=(float war)
	{
		b -= war;
		return b;
	}
		void ustaw_zrzute(float d)
		{
			zrzuta=d;
			}
		void wyswietl_zrzuta()
			{
			cout << "Stan zrzuty to"<< " "<<zrzuta<<endl;
		}
		float get_zrzuta()
			{
				return zrzuta;
			}
		void dodaj_konto()
		{
			cout << "Programista (1), stazysta (0)?"<<endl;
			cin >> w;
			wyj();
			switch(w){
			
		case 0:
				{
				czlowiek *s;
				s = new stazysta();
				cout << "Podaj imie i nazwisko oraz stan konta"<< endl;
				cin >>  imie ;
				cin >> nazwisko ;
				cin >> konto;
				if (imie.size()>50) throw -1;
				for (int i=0;i<imie.size();i++)
				{
					if(imie[i]<65 || (imie[i]>90 && imie[i]<97) || imie[i]>122) throw -1;
				}
				if (nazwisko.size()>100) throw -2;
				for (int i=0;i<nazwisko.size();i++)
				{
					if(nazwisko[i]<65 || (imie[i]>90 && imie[i]<97) || imie[i]>122) throw -2;
				}
				if (!cin.good()) throw -3;
					
				s->ustaw_dane(imie,nazwisko);
				s->ustaw_konto(konto);
				s->ustaw_id(0);
				tab.push_back(s);
				s->przedstaw() ;
				}
				break;
		case 1:
				{
				czlowiek *p;
				p=new programista();
				cout << "Podaj imie i nazwisko oraz stan konta"<< endl;
				cin >>  imie >> nazwisko >> konto;
				wyj();
				p->ustaw_dane(imie,nazwisko);
					if (imie.size()>50) throw -1;
				for (int i=0;i<imie.size();i++)
				{
					if(imie[i]<65 || (imie[i]>90 && imie[i]<97) || imie[i]>122) throw -1;
				}
				if (nazwisko.size()>100) throw -2;
				for (int i=0;i<nazwisko.size();i++)
				{
					if(nazwisko[i]<65 || (imie[i]>90 && imie[i]<97) || imie[i]>122) throw -2;
				}
				if (!cin.good()) throw -3;	
				p->ustaw_konto(konto);
				p->ustaw_id(1);
				tab.push_back(p);
				p->przedstaw();
				}
				break;
	default:
		 cout << "zle dane!" << endl;
            break;
       
	
		}
	}
		void usun_konto(int n)
		{
			cout << "podaj iterator konta do usuniecia" << endl;
		cin >> n;
		if (!cin.good()) throw -1;
		if (( n>tab.size()) || (n<0)) throw -2;
		//wyj();
	//	wyj2(n);
	
		if (tab[n]->get_konto()==0)
		tab.erase(tab.begin() + n);
		else
		cout<<"nie mozna usunac konta, saldo nie wynosi zero"<<endl;
		}
		void edytuj_konto(int n,float c)
		{
			cout << "podaj iterator konta do edytowania" << endl;
			cin >> n;
			if (!cin.good()) throw -1;
			if (( n>tab.size()) || (n<0)) throw -2;
		//	wyj();
		//	wyj2(n);
			cout << "podaj kwote wplacona lub wyplacona"<< endl;
			cin >> c;
			if (!cin.good()) throw -1;
		//	wyj();
			float d = tab[n]->get_konto();
			tab[n]->ustaw_konto(c+=d);
		}
	void przelew(int n,float c)
	{
		int m,z;
		cout << "podaj iterator konta przelewajacego"<<endl;
		cin >> n;
		if (!cin.good()) throw -1;
		if (( n>tab.size()) || (n<0)) throw -2;
		//wyj();
		//wyj2(n);
		cout << "Podaj kwote przelewu"<<endl;
		cin >> c;
		if (!cin.good()) throw -1;
		if (c<0) throw -3;
	//	wyj();
		cout << "Przelew miedzy kontami (1), przelew do skarbony (0)"<<endl;
		cin >> m;
		if (!cin.good()) throw -1;
	//	wyj();
		
		switch(m)
			{
				case 0:
					{	
						float d = tab[n]->get_konto();
						tab[n]->ustaw_konto(d-=c);
						ustaw_zrzute(get_zrzuta()+c);
						break;
					
					}
					case 1:
						cout<<"Wprowadz iterator konta odbiorcy"<<endl;
						cin >> z;
						if (!cin.good()) throw -1;
						if (( z>tab.size()) || (z<0)) throw -2;
					//	wyj();
					//	wyj2(z);
						int q = tab[z]->get_id();
						if(q==0)
						{
							cout<<"stazystom nie pozyczamy"<<endl;
						}
						else
						{
						float d = tab[n]->get_konto();
						tab[n]->ustaw_konto(d-=c);
						float f = tab[z]->get_konto();
						tab[z]->ustaw_konto(z+=c);
						
						}
						
						
		
			}
		
	}
};
int fileExists (const char* fileName)
{
        FILE* plik;
        plik = fopen(fileName, "rwa+"); 
        if ( plik )
        {
            //fclose(plik);
            return 1;
        }
        //fclose(plik);
        return 0;
}
 

int main()
{
	string a,b,nazwa;
	float c,d;
	int n,ile,q,o;
	fstream plik;
	kasa<czlowiek> k;
	cout << "Podaj nazwe pliku"<< endl;
	cin >> nazwa;
	 if ( fileExists(nazwa.c_str()) )
			{
	 		
			plik.open(nazwa.c_str(), ios::in);
			plik>>ile;
			for (int i=0;i<ile;i++)
			{
			plik>>a>>b>>c>>q;
			switch(q)
			{
			case 1:
			czlowiek *x;
			x=new programista();
			x->ustaw_dane(a,b);
			x->ustaw_konto(c);
			x->ustaw_id(q);
			tab.push_back(x);
			break;
			case 0:
			czlowiek *s;
			s=new stazysta();
			s->ustaw_dane(a,b);
			s->ustaw_konto(c);
			s->ustaw_id(q);
			tab.push_back(s);
			break;
			default:
				break;
				
		}
			}
			plik>>d;
			k.ustaw_zrzute(d);
			plik.close();
			}
       		 else
       		 printf("Plik zostaje utworzony\n");
       
	
	   
    
	while(true){
	cout << "\n";
	cout << "Aplikacja konsolowa 'Zrzuta'"<< endl;
	cout << "Dodaj Konto - 1\nUsun konto - 2 \nEdytuj konto - 3 \nWykonaj przelew - 4 \nWyswietl kase i salda - 5 \nWyjdz z programu - 6" <<endl ;
	cin >> n;
	wyj();
	if(n == 6){break;}
	else{
	switch(n)
		{
		case 1:
				try{
				
				
				k.dodaj_konto();
			}
			catch(int blad)
			{
				if(blad == -1) cout << "blad imienia"<<endl;
				else if (blad == -2) cout <<"blad nazwiska"<< endl;
				else if (blad == -3) 	wyj();
			
		}
			
				break;
		case 2:
			try{
			
			k.usun_konto(n);
				}
				catch(int blad){
				
				if(blad == -1) wyj();
				else if (blad == -2) wyj2();
			}
			break;
		case 3:
			try {
			
			k.edytuj_konto(n,c);
	}
	catch(int blad){
		if(blad == -1) wyj();
		else if (blad == -2) wyj2();
	}
			break;
		case 4:
			try{
			
			k.przelew(n,c);
		}
		catch(int blad){
		if(blad == -1) wyj();
		else if (blad == -2) wyj2();
		else if (blad == -3) wyj2();
	}
		
			break;
		case 5:
			k.wyswietl_zrzuta();
			cout << "Zapisani ludzie"<<endl;
			for (int x=0; x<tab.size(); x++)
 				{
 				tab[x]->przedstaw();
				}
			
				break;
			
		case 6:
		
			exit(0);
			default:
				cout<<"Wprowadz prawidlowa liczbe"<< endl;
				break;
		}
		plik.open(nazwa.c_str(), ios::out );
		ile=tab.size();
		cout<<ile<<endl;
        plik<<ile<<"\n";
        for (int i=0;i<ile;i++){
		plik<<tab[i]->get_imie()<<" "<<tab[i]->get_nazwisko()<<" ";
		plik<<tab[i]->get_konto()<<" "; 
		plik<<tab[i]->get_id()<<" "; 
		plik<<endl;    
	
    }
    	plik<<k.get_zrzuta()<<"\n";
    	plik.close();	    
}
}
}









