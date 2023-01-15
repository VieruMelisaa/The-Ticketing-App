#define _CRT_SECURE_NO_WARNINGS
#include"Eveniment.h"
#include"Locatie.h"
#include<iostream>
#include<string>
#include <fstream>
using namespace std;
Eveniment::Eveniment()
{
	this->denumire = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumire, "Necunoscut");
	this->ora = "hh:mm";
	this->data = "DD.MM.YYYY";
	this->locatie =new Locatie();
}
Eveniment::Eveniment(const char* denumire, const string ora, const string data, Locatie locatie)
{
	if (denumire != nullptr)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
	else throw exception("Nu ati introdus un eveniment");
	if (locatie.valid()==true)
	{
		this->locatie = new Locatie(locatie);
	}
	else throw exception("Locatie invalida");
	
	if (data.length() == 10)
	{
		string zi = data.substr(0, 2);
		string luna = data.substr(3, 2);
		string an = data.substr(6, 4);
		if ((stoi(zi) > 0 && stoi(zi) < 32) && (stoi(luna) > 0 && stoi(luna) < 13) && stoi(an) > 2021)
		{
			this->data = data;
		}
		else throw exception("Data nu este valida");
	}
	else throw exception("Data nu este valida (format DD.MM.YYYY)");

	if (ora.length() == 5)
	{
		string h = ora.substr(0, 2);
		string m = ora.substr(3, 2);
		if (stoi(h) > -1 && stoi(h) < 25 && stoi(m) > -1 && stoi(m) < 60)
			this->ora = ora;
		else throw exception("Ora nu este valida");
	}
	else throw exception("Ora nu este valida (format HH:MM)");
	
	

}
Eveniment::Eveniment(const Eveniment& e)
{
		if (e.denumire != nullptr)
		{
			this->denumire = new char[strlen(e.denumire) + 1];
			strcpy(this->denumire, e.denumire);
		}
		if (e.locatie->valid())
		{
			this->locatie = new Locatie(*e.locatie);
		}
		if (e.data.length() == 10)
		{
			string zi = e.data.substr(0, 2);
			string luna = e.data.substr(3, 2);
			string an = e.data.substr(6, 4);
			if ((stoi(zi) > 0 && stoi(zi) < 32) && (stoi(luna) > 0 && stoi(luna) < 13) && stoi(an) > 2021)
			{
				this->data = e.data;
			}
		}
		if (e.ora.length() == 5)
		{
			string h = e.ora.substr(0, 2);
			string m = e.ora.substr(3, 2);
			if (stoi(h) > -1 && stoi(h) < 25 && stoi(m) > -1 && stoi(m) < 60)
				this->ora = e.ora;
		}
	
}
Eveniment&Eveniment::operator=(const Eveniment& e)
{
	
	if (this != &e)
	{
		if (denumire != nullptr)
		{
			delete[]denumire;
			denumire = nullptr;
		}
		if (locatie != nullptr)
		{
			delete locatie;
			locatie = nullptr;
		}
		if (e.denumire != nullptr)
		{
			this->denumire = new char[strlen(e.denumire) + 1];
			strcpy(this->denumire, e.denumire);
		}

		if (e.locatie->valid())
		{
			this->locatie = new Locatie(*e.locatie);
		}

		if (e.data.length()==10)
		{
			string zi = e.data.substr(0, 2);
			string luna = e.data.substr(3, 2);
			string an = e.data.substr(6, 4);
			if ((stoi(zi) > 0 && stoi(zi) < 32) && (stoi(luna) > 0 && stoi(luna) < 13) && stoi(an) > 2021)
			{
				this->data = e.data;
			}
			
		}

		if (e.ora.length()==5)
		{
			string h = e.ora.substr(0, 2);
			string m = e.ora.substr(3, 2);
			if (stoi(h) > -1 && stoi(h) < 25 && stoi(m) > -1 && stoi(m) < 60)
				this->ora = e.ora;
		}
		return *this;
	}

}
bool Eveniment::operator==(const Eveniment& e)
{
	if (denumire != e.denumire && ora != e.ora && data != e.data && locatie != e.locatie)
		return false;
	else return true;
}
string Eveniment::operator ()(int a)
{
	string an =data.substr(6, 4);
	int b=stoi(an) + 1;
	data = data.substr(0, 6) + to_string(b);
	return data;
}
Eveniment::~Eveniment()
{
	if (this->denumire != nullptr)
	{
		delete[]this->denumire;
		this->denumire = nullptr;
	}
	if (locatie != nullptr)
	{
		delete locatie;
	}
}
char* Eveniment::getDenumire()
{
	return denumire;
}
void Eveniment::setDenumire(const char* denumire)
{
	if (denumire != nullptr)
	{
		delete[]this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}

}
string Eveniment::getData()
{
	return data;
}
void Eveniment::setData(string data)
{
	if (data.length() == 10)
	{
		string zi = data.substr(0, 2);
		string luna = data.substr(3, 2);
		string an = data.substr(6, 4);
		if ((stoi(zi) > 0 && stoi(zi) < 32) && (stoi(luna) > 0 && stoi(luna) < 13) && stoi(an) > 2021)
		{
			this->data = data;
		}
	}
}
string Eveniment::getOra()
{
	return ora;
}
void Eveniment::setOra(string ora)
{
	if (ora.length() ==5 )
	{
		string h = ora.substr(0, 2);
		string m = ora.substr(3, 2);
		if (stoi(h) > -1 && stoi(h) < 25 && stoi(m) > -1 && stoi(m) < 60)
			this->ora = ora;
	}
}
ostream& operator<<(ostream& out, Eveniment& e)
{
	out << "Evenimentul " << e.denumire << " va avea loc pe data de " << e.data << " la ora " << e.ora << " (Locatia: " << e.locatie->getAdresa() << " )";
	return out;
}
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Introduceti numele evenimentului:";
	string buffer;
	getline(in, buffer);
	if (buffer.length() > 0)
	{
		if (e.denumire != nullptr)
		{
			delete[]e.denumire;
		}
		e.denumire = new char[buffer.length() + 1];
		strcpy(e.denumire, buffer.c_str());
	}
	else cout<<"Nu ati introdus un eveniment";
	cout << "Introduceti data (format dd.mm.yyyy):";
	string data;
	in >> e.data;
	cout << "Introduceti ora (format hh:mm):";
	in >> e.ora;
	cout << "Introduceti locatia:";
	in.ignore();
	Locatie l;
	in >> l;
	if (l.valid())
	{
		e.locatie = new Locatie(l);
	}
	return in;
}
bool Eveniment::valid()
{
	if (this->denumire != nullptr && this->data != "" && ora != "" && this->locatie->valid() == true)
	{
		return true;
	}
	else false;
}
//ofstream& operator<<(ofstream& ofs, Eveniment& e)
//{
//	ofs<< "Evenimentul " << e.denumire << " va avea loc pe data de" << e.data << " la ora " << e.ora << " (Locatia: " << e.locatie->getAdresa() << " )";
//	return ofs;
// }
ofstream& operator<<(ofstream& outF, Eveniment& e)
{
	outF.write((char*)&e.denumire, sizeof(e.denumire));
	outF.write((char*)&e.data, sizeof(e.data));
	outF.write((char*)&e.ora, sizeof(e.ora));
	outF.write((char*)&e.locatie, sizeof(e.locatie));
	return outF;
}
ifstream& operator>>(ifstream& inF, Eveniment& e)
{
	char buffer[256]; 
	inF.getline(buffer,256);
	e.setDenumire(buffer);
	getline(inF, e.ora);
	getline(inF, e.data);
	
	Locatie locatie;
	string file = "";
	cout << "Introduceti numele fisierului de unde se va extrage locatia(locatii.txt):";
	getline(cin, file);
	ifstream f(file);
	if (f.is_open())
	{
		while (!f.eof())
		{
			f >> locatie;
			cout << locatie;
			if (locatie.valid())
			{	
				e.locatie = new Locatie(locatie);
				
			}
		}
	}
	else cout << "Fisierul nu exista."<<endl;
	f.close();
	return inF;
}


