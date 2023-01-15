#include "Bilet.h"
class BiletPrioritar :public Bilet
{
private:
	string prioritate;//mica || mare
public:
	BiletPrioritar();
	BiletPrioritar(const char* categorie, const string zona, float pret, int loc, Eveniment e,string prioritate);
	BiletPrioritar(const BiletPrioritar& b);
	BiletPrioritar& operator=(const BiletPrioritar& b);
	~BiletPrioritar();
	float getPretFinal();
	string getPrioritate();
	void setPrioritate(string prior);
	friend ostream& operator<<(ostream&, BiletPrioritar&);
	friend istream& operator>>(istream&, BiletPrioritar&);
	friend ifstream& operator>>(ifstream& , BiletPrioritar&);
	friend ofstream& operator<<(ofstream& , BiletPrioritar&);

};