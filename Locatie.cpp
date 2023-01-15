#include "Locatie.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
Locatie::Locatie()
{
	this->adresa = "Necunoscuta";
	this->zone = nullptr;
	this->capacitate = 0;
	this->nrZone = 0;
	this->nrLocuriZone = nullptr;
}
Locatie::Locatie(const string adresa, string* zone, int nrZone, int capacitate, int* nrLocuriZone)
{
	if (adresa != "")
	{
		this->adresa = adresa;
	}
	else throw exception("Adresa invalida");
	if (nrZone > 0)
	{
		this->nrZone = nrZone;
	}
	else throw exception("Nu ati introdus un numar de zone valid");
	if (zone != nullptr && nrZone > 0)
	{
		this->zone = new string[nrZone+1];
		for (int i = 0; i < nrZone; i++)
		{
			this->zone[i] = zone[i];
		}
	}
	
	if (capacitate > 0)
		this->capacitate = capacitate;
	else throw exception("Capacitate invalida");
	if (nrLocuriZone != nullptr)
	{
		this->nrLocuriZone = new int[nrZone+1];
		for (int i = 0; i < nrZone; i++)
		{
			this->nrLocuriZone[i] = nrLocuriZone[i];
		}
	}
	else throw exception("Numarul de locuri per zona nu este valid");
	int k = 0;
	for (int i = 0; i < this->nrZone; i++) {
		for (int j = 1; j <= this->nrLocuriZone[i]; j++) {
			locuri[++k] = make_pair(i, true);
		}
	}
}
Locatie::Locatie(const Locatie& l)
{
	if (l.adresa != "")
	{
		this->adresa = l.adresa;
	}
	if (l.nrZone > 0)
	{
		this->nrZone = l.nrZone;
	}
	if (l.zone != nullptr && l.nrZone > 0)
	{
		this->zone = new string[l.nrZone+1];
		for (int i = 0; i < l.nrZone; i++)
		{
			this->zone[i] = l.zone[i];
		}
	}
	if (l.capacitate > 0)
		this->capacitate = l.capacitate;
	if (l.nrLocuriZone != nullptr &&l.nrZone>0)
	{
		this->nrLocuriZone = new int[l.nrZone+1];
		for (int i = 0; i < l.nrZone; i++)
		{
			this->nrLocuriZone[i] = l.nrLocuriZone[i];
		}
	}
	locuri = l.locuri;

}
Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{

		if (zone != nullptr)
		{
			delete[]zone;
			zone = nullptr;
		}
		if (nrLocuriZone != nullptr)
		{
			delete[]nrLocuriZone;
			nrLocuriZone = nullptr;
		}
		if (l.adresa != "")
		{
			this->adresa = l.adresa;
		}
		if (l.nrZone > 0)
		{
			this->nrZone = l.nrZone;
		}
		if (l.zone != nullptr && l.nrZone > 0)
		{
			this->zone = new string[l.nrZone+1];
			for (int i = 0; i < l.nrZone; i++)
			{
				this->zone[i] = l.zone[i];
			}
		}
		if (l.capacitate > 0)
			this->capacitate = l.capacitate;
		if (l.nrLocuriZone != nullptr)
		{
			this->nrLocuriZone = new int[l.nrZone+1];
			for (int i = 0; i < l.nrZone; i++)
			{
				this->nrLocuriZone[i] = l.nrLocuriZone[i];
			}
		}
		locuri = l.locuri;

		return *this;

	}
}
bool Locatie::operator!()
{
	return capacitate == 0;
}
Locatie::~Locatie()
{
	if (this->nrLocuriZone != nullptr)
	{
		delete[]this->nrLocuriZone;
		this->nrLocuriZone = nullptr;
	}
	if (this->zone != nullptr)
	{
		delete[]this->zone;
		this->zone = nullptr;
	}
}
int Locatie::getNrZone()
{
	return this->nrZone;
}
void Locatie::setNrZone(int nrZone)
{
	if (nrZone > 0)
	{
		this->nrZone = nrZone;
	}
}
int Locatie::getCapacitate()
{
	return this->capacitate;
}
void Locatie::setCapacitate(int capacitate)
{
	if (capacitate > 0)
	{
		this->capacitate = capacitate;
	}
}
string Locatie::getAdresa()
{
	return this->adresa;
}
void Locatie::setAdresa(string adresa)
{
	if (adresa != "")
	{
		this->adresa = adresa;
	}
}
string* Locatie::getZone()
{
	string* copie = new string[nrZone+1];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = zone[i];
	}
	return copie;

}
string Locatie::getZone(int i)
{
	if(i>=0 && i<nrZone)
		return zone[i];
}
void Locatie::setZone(string* zone, int nrZone)
{
	if (zone != nullptr && nrZone > 0)
	{
		delete[]this->zone;
		this->nrZone = nrZone;
		this->zone = new string[nrZone+1];
		for (int i = 0; i < nrZone; i++)
		{
			this->zone[i] = zone[i];
		}
	}
}
int* Locatie::getNrLocuriZone()
{
	int* copie = new int[nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = nrLocuriZone[i];
	}
	return copie;
}
int Locatie::getNrLocuriZone(int i)
{
	if (i >= 0 && i < nrZone)
		return nrLocuriZone[i];
}
void Locatie::setNrLocuriZone(int* nrLocuriZone, int nrZone)
{
	if (nrLocuriZone != nullptr && nrZone == this->nrZone)
	{
		delete[]nrLocuriZone;
		for (int i = 0; i < nrZone; i++)
		{
			this->nrLocuriZone[i] = nrLocuriZone[i];
		}
	}

}
void Locatie::getLocuri()
{
	for (auto const& x : locuri) {
		cout << "Locul " << x.first << " este in zona " << zone[x.second.first] << " si este ";
		if (x.second.second) {
			cout << "disponibil." << endl;
		}
		else {
			cout << "indisponibil." <<endl;
		}
	}
}

bool Locatie::valid()
{
	if (adresa != "" &&capacitate > 0 && nrZone > 0 &&zone != nullptr && nrLocuriZone != nullptr)
	{
		return true;
	}
	else return false;
	
}
bool Locatie::loc_dat(int loc)
{
	if (locuri[loc].second)
	{
		locuri[loc].second = false;
		return true;
		//cout << "Bilet cumparat in zona" << zone[locuri[loc].first] << ": locul " << loc;
	}
	else return false; //cout << "Locul " << loc << "este indisponibil";
}
ostream& operator<<(ostream& out, Locatie &l)
{
	out<< "Locatia se afla la " << l.adresa << " si are o capacitate de " << l.capacitate<<endl;
	out << "Are " << l.nrZone << " zone disponibile:";
	for (int i = 0; i < l.nrZone; i++)
	{
		out << "\nZona "<<l.zone[i] << ": " << l.nrLocuriZone[i] << " locuri";
	}
	out << "\nDisponibilitatea locurilor per Zona:"<<endl; l.getLocuri();
	return out;

}
istream& operator>>(istream& in, Locatie& l)
{
	cout << endl << "Introduceti adresa locatiei:";
	getline(in, l.adresa);
	cout << "Introduceti capacitatea maxima a locatiei:";
	in >> l.capacitate;
	in.ignore();
	cout << "Introduceti numarul de zone disponibile:";
	in >> l.nrZone;
	l.zone = new string[l.nrZone];
	cout << "Introduceti zonele:"<<endl;
	for (int i = 0; i < l.nrZone; i++)
	{
		cout<< "Zona " << i + 1<<":";
		in >> l.zone[i];
	}
	l.nrLocuriZone = new int[l.nrZone];
	cout << "Introduceti nr de locuri per zona:";
	for (int i = 0; i < l.nrZone; i++)
	{
		in >> l.nrLocuriZone[i];
	}
	int k = 0;
	for (int i = 0; i < l.nrZone; i++) {
		for (int j = 1; j <= l.nrLocuriZone[i]; j++) {
			cout << "Introduceti disponibilitatea locului " << k<<": ";
			in >> l.locuri[++k].second;
		}
	}
	return in;

}
string Locatie::operator[](int i)
{
	return zone[i];
}

bool Locatie::valid_zona(string zona)
{
	int k = 0;
	if (zona != "")
	{
		for (int i = 0; i < nrZone; i++)
		{
			if (zona == zone[i])
			{
				k = 1;
			}
		}
		if (k == 1)return true;
	}
}
ifstream& operator>>(ifstream& inF, Locatie& l)
{
	
		getline(inF, l.adresa);
		inF >> l.capacitate;
		inF >> l.nrZone;
		l.zone = new string[l.nrZone];
		for (int i = 0; i < l.nrZone; i++)
		{
			inF >> l.zone[i];
		}
		l.nrLocuriZone = new int[l.nrZone];
		for (int i = 0; i < l.nrZone; i++)
		{
			inF >>l.nrLocuriZone[i];
		}
		int k = 0;
		for (int i = 0; i < l.nrZone; i++) {
			for (int j = 1; j <= l.nrLocuriZone[i]; j++) {
				
				inF >> l.locuri[++k].second;//true || false
			}
		}
			return inF;
}
//ofstream& operator<<(ofstream& ofs, Locatie& l)
//{	
//	ofs << "Locatia se afla la " << l.adresa << " si are o capacitate de " << l.capacitate << endl;
//	ofs << "Are " << l.nrZone << " zone disponibile:";
//	for (int i = 0; i < l.nrZone; i++)
//	{
//		ofs << "\nZona " << l.zone[i] << ": " << l.nrLocuriZone[i] << " locuri";
//	}
// 
//	return ofs;
//}
ofstream& operator<<(ofstream& outF, Locatie& l)
{
	outF.write((char*)&l.adresa, sizeof(l.adresa));
	outF.write((char*)&l.capacitate, sizeof(l.capacitate));
	outF.write((char*)&l.nrZone, sizeof(l.nrZone));
	for (int i = 0; i < l.nrZone; i++)
	{
		outF.write((char*)&l.zone[i], sizeof(l.zone[i]));
	}
	for (int i = 0; i < l.nrZone; i++)
	{
		outF.write((char*)&l.nrLocuriZone[i], sizeof(l.nrLocuriZone[i]));
	} 
	outF.write((char*)&l.locuri, sizeof(l.locuri));
	return outF;
}




