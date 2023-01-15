#define _CRT_SECURE_NO_WARNINGS
#include "Bilet.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int Bilet::nrBilete = 0;
Bilet::Bilet() :id(nrBilete++)
{
	this->categorie = new char[strlen("N/A") + 1];
	strcpy(this->categorie, "N/A");
	this->eveniment = "Necunoscut";
	this->pret = -1;
	this->loc = -1;
	this->zona = "N/A";
	this->e = nullptr;//new Eveniment();
	this->nrMaxBilete = 0;

}
Bilet::Bilet(const char* categorie, const string zona, float pret, int loc, Eveniment e) :id(nrBilete++)
{
	if (categorie != nullptr && strlen(categorie) > 0)
	{
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
	}
	else throw exception("Categoria biletului este invalida");
	if (e.valid())
	{
		this->e = new Eveniment(e);
	}
	else throw exception("Eveniment invalid");
	this->eveniment = e.getDenumire();
	this->nrMaxBilete = e.locatie->getCapacitate();
	if (e.locatie->valid_zona(zona) == true)
	{
		this->zona = zona;
	}
	else throw exception("Zona invalida");
	
		this->pret = pret;
		if (e.locatie!=nullptr)
		{
			if (e.locatie->loc_dat(loc))
			{
				this->loc = loc;
			}
			else throw exception("Loc indisponibil");
		}
}
Bilet::Bilet(const Bilet& b) :id(b.id)
{
	if (b.categorie != nullptr && strlen(b.categorie) > 0)
	{
		this->categorie = new char[strlen(b.categorie) + 1];
		strcpy(this->categorie, b.categorie);
	}
	if (b.e->valid()==true)
	{
		this->e = new Eveniment(*b.e);
	}
	this->eveniment = b.e->getDenumire();
	this->nrMaxBilete = b.e->locatie->getCapacitate();
	if (b.e->locatie->valid_zona(b.zona) == true)
	{
		this->zona = b.zona;
	}
	this->pret = b.pret;
	if (b.e->locatie != nullptr)
	{
		if (b.e->locatie->loc_dat(b.loc))
		{
			this->loc = b.loc;
		}
	}

}
Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b)
	{
		if (this->categorie != nullptr)
		{
			delete[]this->categorie;
			this->categorie = nullptr;
		}
		if (e != nullptr)
		{
			delete[]e;
			e = nullptr;
		}
		if (b.categorie != nullptr && strlen(b.categorie) > 0)
		{
			this->categorie = new char[strlen(b.categorie) + 1];
			strcpy(this->categorie, b.categorie);
		}
		if (b.e->valid())
		{
			this->e = new Eveniment(*b.e);
		}
		this->eveniment = b.e->getDenumire();
		this->nrMaxBilete = b.e->locatie->getCapacitate();
		if (b.e->locatie->valid_zona(zona) == true)
		{
			this->zona = b.zona;
		}
			this->pret = b.pret;

		if (b.e->locatie != nullptr)
			{
				if (b.e->locatie->loc_dat(b.loc))
				{
					this->loc = b.loc;
				}
			}
		
		return *this;
	}

}
float Bilet::operator+(Bilet &b)
{
	//reducere 5% la 2 bilete
	return (this->pret + b.pret)*0.95;
}
Bilet Bilet::operator++(int)
{
	//taxa bilet
	Bilet copie = *this;
	this->pret++;
	return copie;
}
Bilet::~Bilet()
{
	if (this->categorie != nullptr)
	{
		delete[]this->categorie;
		this->categorie = nullptr;
	}
	if (e != nullptr)
	{
		delete e;
		e = nullptr;
	}
}
float Bilet::suma_vanzare_bilete(Bilet* bilete, int nrBilete)
{	
	float suma = 0;
	if (bilete != nullptr && nrBilete > 0)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			suma += bilete[i].pret;
		}
	}
	return suma;
}
char* Bilet::getCategorie()
{
	return categorie;
}
void Bilet::setCategorie(string categorie)
{
	if (categorie != "")
	{
		this->categorie = new char[categorie.length() + 1];
		strcpy(this->categorie, categorie.c_str());
	}
}
string Bilet::getEveniment()
{
	return eveniment;
}
void Bilet::setEveniment(string eveniment)
{
	if (eveniment != "")
	{
		this->eveniment = eveniment;
	}
}
float Bilet::getPret()
{
	return pret;
}
void Bilet::setPret(float pret)
{
	if (pret >= 0)
	{
		this->pret = pret;
	}
}
int Bilet::getLoc()
{
	return loc;
}
void Bilet::setLoc(int loc)
{
	if (e->locatie->loc_dat(loc)==true)
	{
		this->loc = loc;
	}
}

string Bilet::getZona()
{
	return zona;
}
void Bilet::setZona(string zona)
{
	if (e->locatie->valid_zona(zona))
	{
		this->zona = zona;
	}

}


ostream& operator<<(ostream& out, Bilet b)
{
	out << "Biletul pentru evenimentul " <<b.eveniment<< " este din categoria " << b.categorie << ", are pretul de " << b.getPretFinal();
	out << " lei si corespunde locului " << b.loc << " zona " << b.zona;
	out << "\nNr maxim de bilete este: " << b.nrMaxBilete;
	return out;
}
istream& operator>>(istream& in, Bilet& b)
{
	//cout << endl << "Introduceti evenimentul la care doriti sa participati:";
	//in.ignore();
	Eveniment ev;
	in >> ev;
	if (ev.valid())
	{
		b.e = new Eveniment(ev);
	}
	b.eveniment=b.e->getDenumire();
	in.ignore();
	cout << "Introduceti categoria dorita: ";
	string buffer;
	getline(in, buffer);
	if (buffer != "")
	{
		if (b.categorie != nullptr)
		{
			delete[]b.categorie;
		}
		b.categorie = new char[buffer.length() + 1];
		strcpy(b.categorie, buffer.c_str());

	}
	cout << "Introduceti zona dorita:";
	getline(in, b.zona);
	
	cout << "Introduceti locul dorit:";
	int loc;
	in >> loc;
	if (loc > 0)
	{
		b.setLoc(loc);
	}
	cout << "Introduceti pretul:";
	in >> b.pret;
	return in;
}
ifstream& operator>>(ifstream& inF, Bilet& b)
{
	Eveniment ev;
	string file = "";
	cout << "Introduceti numele fisierului de unde se va extrage evenimentul(test_ifs.txt):";
	getline(cin, file);
	ifstream f(file);
	if (f.is_open())
	{
		while (!f.eof())
		{
			f >> ev;
			cout << ev << endl;
			if (ev.valid())
			{
				b.e = new Eveniment(ev);
				b.eveniment = b.e->getDenumire();
			}
		}
	}
	else cout << "Fisierul nu exista." << endl;
	f.close();
	string buffer;
	getline(inF, buffer);
	b.setCategorie(buffer);
	getline(inF, b.zona);
	int loc;
	inF >> loc;
	if (loc > 0)
	{
		b.setLoc(loc);
	}
	inF >> b.pret;
	return inF;

}
ofstream& operator<<(ofstream& outF, Bilet& b)
{
	outF.write((char*)&b.eveniment, sizeof(b.eveniment));
	outF.write((char*)&b.categorie, sizeof(b.categorie));
	outF.write((char*)&b.pret, sizeof(b.pret));
	outF.write((char*)&b.loc, sizeof(b.loc));
	outF.write((char*)&b.zona, sizeof(b.zona));
	outF.write((char*)&b.nrMaxBilete, sizeof(b.nrMaxBilete));
	return outF;
}
