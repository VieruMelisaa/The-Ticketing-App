#pragma once
enum EtipBilet { Film = 1, Concert = 2, Fotbal = 3, Cultural = 4, Avion = 5 };
class EvenimentBilet
{
protected:
	
	static float TVA;
	EtipBilet tipBilet;
public:
	virtual float getPretFinal()=0;
	virtual EtipBilet TipBilet(EtipBilet) =0;
	
};

