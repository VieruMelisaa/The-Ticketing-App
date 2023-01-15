#pragma once
#include<iostream>
#include <map>
using namespace std;
class Locatie
{
private:
	string adresa;
	string* zone;
	int nrZone;
	int capacitate;
	int* nrLocuriZone;
	map<int, pair<int, bool>>locuri;//cheie-locul//utilizata pentru a vedea disponibilitatea locurilor pt fiecare zona
									//<zona,disponibilitate>

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
	void getLocuri();
	bool valid();
	bool loc_dat(int loc);
	bool valid_zona(string zona);
	friend ostream& operator<<(ostream&, Locatie&);
	friend istream& operator>>(istream&, Locatie&);
	friend class Eveniment;
	friend ifstream& operator>>(ifstream&, Locatie& );
	friend ofstream& operator<<(ofstream&, Locatie& );
};

