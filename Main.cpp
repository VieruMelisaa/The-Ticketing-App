#define _CRT_SECURE_NO_WARNINGS
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include <iostream>
#include<string>

using namespace std;
int main()
{
	try {

		cout<<"-----------Locatie-----------"<<endl;
		Locatie l;
		cout << "-----------Locatie: Operator >>-----------";
		cin>>l;
		cout << endl << "\n-----------Locatie: Operator <<-----------";
		cout<<endl<<l<<endl;
		string zone[3] = { "1","a","b" };
		int nr[3] = { 3,4,5 };
		cout<<"\n----------Locatie:Constructor cu toti parametri------------"<<endl;
		Locatie l1("Bucuresti", zone, 3, 200, nr);
		cout<<l1<<endl;
		cout<<"\n----------Locatie:Getteri si Setteri-----------------"<<endl;
		cout <<"getAdresa():"<< l1.getAdresa()<<endl;
		cout << "setAdresa(Constanta):"; l1.setAdresa("Constanta");
		cout << l1.getAdresa()<<endl;
		cout << "getCapacitate():" << l1.getCapacitate()<<endl;
		cout << "setCapacitate(30):"; l1.setCapacitate(30);
		cout << l1.getCapacitate()<<endl;
		cout <<"getNrZone():" << l1.getNrZone()<<endl;
		cout << "getZone(int i):"<<endl;
		for (int i = 0; i < l1.getNrZone(); i++)
		{
			cout << "Zona "<<l1.getZone(i) << "; ";
			cout << "getNrLocuriZone(int i):" << l1.getNrLocuriZone(i) << endl;
		}


		cin.ignore();
		cout<<"-----------Eveniment-----------"<<endl;
		Eveniment e;
		cout << "-----------Eveniment: Operator >> -----------"<<endl;
		cin >> e;
		cout << endl << "-----------Eveniment: Operator << -----------"<<endl;
		cout << endl << e << endl;
		/*string zone[3] = { "1","a","b" };
		int nr[3] = { 3,4,5 };
		Locatie l1("Bucuresti", zone, 3, 200, nr);*/
		Eveniment ev("Fotbal", "15:00", "22.02.2023", l1);
		cout << ev << endl;
		cout << "\n----------Eveniment:Getteri si Setteri-----------------" << endl;
		cout << "getDenumire():" << ev.getDenumire() << endl;
		cout << "setDenumire(Campionat):"; ev.setDenumire("Campionat");
		cout << ev.getDenumire() << endl;
		cout << "getData():" << ev.getData() << endl;
		cout << "setData(30.03.2023):"; ev.setData("30.03.2023");
		cout << ev.getData() << endl;
		cout << "getOra():" << ev.getOra() << endl;
		cout << "setOra(15:40)"; ev.setOra("15:40");
		cout << ev.getOra() << endl;

		cin.ignore();
		cout << "-----------Bilet-----------" << endl;
		Bilet b1;
		cout << "-----------Bilet: Operator >> -----------" << endl;
		cin >> b1;
		cout << endl << "-----------Bilet: Operator << -----------" << endl;
		//cout << endl << b1 << endl;
		/*string zone[3] = { "A","B","C" };
		int nr[3] = { 3,4,5 };
		Locatie l1("Bucuresti", zone, 3, 200, nr);
		Eveniment ev("Fotbal", "15:00", "22.02.2023", l1);*/
		Bilet b("VIP", "A", 10, 1, ev);
		cout << b<<endl;
		cout << "\n----------Bilet:Getteri si Setteri-----------------" << endl;
		cout << "getEveniment():" << b.getEveniment() << endl;
		cout << "setEveniment(Campionat):"; b.setEveniment("Campionat");
		cout << b.getEveniment() << endl;
		cout << "getCategorie():" << b.getCategorie() << endl;
		cout << "setCategorie(Standard):"; b.setCategorie("Standard");
		cout << b.getCategorie() << endl;
		cout << "getZona():" << b.getZona() << endl;
		cout << "setZona(B)"; b.setZona("B");
		cout << b.getZona() << endl;
		cout << "getLoc():" << b.getLoc() << endl;
		cout << "setLoc(2)"; b.setLoc(2);
		cout << b.getLoc() << endl;
		cout << "getPret():" << b.getPret() << endl;
		cout << "setPret(50):"; b.setPret(50);
		cout << b.getPret() << endl;
	}
	catch (exception e)
	{
		cout << e.what();
	
	}	
	return 0;
}