#include<iostream>
#include "BiletPrioritar.h"
#include<string>
#include<fstream>
using namespace std;
BiletPrioritar::BiletPrioritar():Bilet()
{
	prioritate = "mica";
}
BiletPrioritar::BiletPrioritar(const char* categorie, const string zona, float pret, int loc, Eveniment e,const string prioritate):Bilet(categorie, zona, pret, loc, e)
{
	if (prioritate != "" && (prioritate=="mare" || prioritate == "mica"))
	{
		this->prioritate = prioritate;
	}
}
BiletPrioritar::BiletPrioritar(const BiletPrioritar& b):Bilet(b)
{
	if (b.prioritate != "")
	{
		this->prioritate = b.prioritate;
	}
}
BiletPrioritar& BiletPrioritar:: operator=(const BiletPrioritar& b)
{
	if (this != &b)
	{
		Bilet::operator=(b);
		if (b.prioritate != "" && (prioritate == "mare" || prioritate == "mica"))
		{
			this->prioritate = b.prioritate;
		}
		return *this;
	}
}
string BiletPrioritar::getPrioritate()
{
	return prioritate;
}
void BiletPrioritar::setPrioritate(string prior)
{
	if (prior != "" && (prior == "mare" || prior == "mica"))
	{
		this->prioritate = prior;
	}
}
float BiletPrioritar:: getPretFinal()
{
	return (getPret() * 1 + TVA) * 1.2;
}
ostream& operator<<(ostream& out, BiletPrioritar& b)
{
	out << (Bilet)b;
	out << "\nPrioritatea biletului:" << b.prioritate;
	return out;
}
istream& operator>>(istream& in, BiletPrioritar& b)
{
	in >> (Bilet&)b;
	cout << "Prioritatea biletului:";
	string prior;
	getline(in, prior);
	if (prior != "" && (prior == "mare" || prior == "mica"))
	{
		b.prioritate = prior;
	}
	return in;

}
ifstream& operator>>(ifstream& inF, BiletPrioritar& b)
{
	inF >> (Bilet&)b;
	string prior;
	getline(inF, prior);
	b.setPrioritate(prior);
	return inF;
}
ofstream& operator<<(ofstream& outF, BiletPrioritar& b)
{
	outF.write((char*)&(Bilet&)b, sizeof((Bilet)b));
	outF.write((char*)&b.prioritate, sizeof(b.prioritate));
	return outF;
}