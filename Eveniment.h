#pragma once
#include"Locatie.h"
#include<iostream>

using namespace std;
class Eveniment
{
private:
	char* denumire;
	string ora;
	string data;
	Locatie* locatie;

public:
	Eveniment();
	Eveniment(const char* denumire, const string ora, const string data, Locatie locatie);
	Eveniment(const Eveniment& e);
	Eveniment& operator=(const Eveniment& e);
	string operator ()(int a);
	bool operator==(const Eveniment& e);
	~Eveniment();
	char* getDenumire();
	void setDenumire(const char* denumire);
	string getData();
	void setData(string data);
	string getOra();
	void setOra(string ora);
	bool valid();
	friend ostream& operator<<(ostream&, Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	friend class Bilet;
	friend ifstream& operator>>(ifstream&, Eveniment&);
	friend ofstream& operator<<(ofstream&, Eveniment&);

};
   