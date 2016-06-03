#include <string>
#include <vector>

using namespace std;

//struktura wiatru
struct wd
{
	double w_strength, w_direction;
};

//umiejtnosci zawodnika
struct abilities
{
	double issue_force, silhouette, landing;
};

//niedoskonalosci zawodnika
struct shortages
{
	double fall_chance, exposure_to_wind;
};

//skoczek
class jumper
{
	static vector <string> names;

	string name;
	double strength, form;
	int notes, jump_length;
	bool death;
	abilities gain;  //deklaracja zmiennej zyskow
	shortages loss;  //deklaracja zmiennej wad

	static void init();


public:
	jumper();	//inicjacja skoczka
	string _name();
	bool jump();
	bool flight(int h_profile, wd h_wind, int h_k);
	bool land(int h_danger);
	bool _death();
	int _notes();
	int _jump_length();
};

class hill
{
	int k;
	double profile, danger_status;
	wd wind;  //deklaracja zmiennej wiatru

public:
	hill();  //inicjajca skoczni
	wd change_wind();
	int h_size();
	double h_profile();
	double h_danger(); 
};