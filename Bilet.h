#pragma once
#include"Eveniment.h"
#include<iostream>
using namespace std;
class Bilet
{
private:
	const int id;
	static int nrBilete;
	char* categorie;
	string eveniment;
	float pret;
	int loc;
	string zona;
	Eveniment *e;
	int nrMaxBilete;
public:
	Bilet();
	Bilet(const char* categorie, const string zona, float pret, int loc, Eveniment e);
	Bilet(const Bilet& b);
	Bilet &operator=(const Bilet& b);
	float operator+(Bilet &b);
	Bilet operator++(int);
	~Bilet();
	static float suma_vanzare_bilete(Bilet* bilete, int nrBilete);
	char* getCategorie();
	void setCategorie(string categorie);
	string getEveniment();
	void setEveniment(string eveniment);
	float getPret();
	void setPret(float pret);
	int getLoc();
	void setLoc(int loc);
	int getRand();
	void setRand(int rand);
	string getZona();
	void setZona(string zona);
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
	friend class Eveniment;
	

};


