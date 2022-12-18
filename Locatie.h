#pragma once
#include<iostream>
using namespace std;
class Locatie
{
private:
	string adresa;
	string* zone;
	int nrZone;
	int capacitate;
	int* nrLocuriZone;

public:
	Locatie();
	Locatie(const string adresa, string* zone, int nrZone, int capacitate, int* nrLocuriZone);
	Locatie(const Locatie& l);
	Locatie& operator=(const Locatie& l);
	string operator[](int i);
	bool operator!();
	~Locatie();
	int getNrZone();
	void setNrZone(int nrZone);
	int getCapacitate();
	void setCapacitate(int capacitate);
	string getAdresa();
	void setAdresa(string adresa);
	string* getZone();
	string getZone(int);
	void setZone(string* zone, int nrZone);
	int* getNrLocuriZone();
	int getNrLocuriZone(int i);
	void setNrLocuriZone(int* nrLocuriZone, int nrZone);
	bool valid();
	void loc_indisponibil(int loc, string zona);
	bool disponibilitate_locuri(string zona, int loc);
	bool valid_zona(string zona);
	friend ostream& operator<<(ostream&, Locatie&);
	friend istream& operator>>(istream&, Locatie&);
	friend class Eveniment;
};

