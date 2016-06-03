#include "declarations.h"
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <math.h>
#include <string>

using namespace std;

double randomValueHill()
{
	return ((double) rand() / (RAND_MAX));
}

//funkcja inicjujaca skocznie
hill::hill()
{
	k = rand() % 60 + 240;
	profile = randomValueHill();
	danger_status = randomValueHill();
	wind = { randomValueHill(), randomValueHill() * 3.14 };
}

int hill::h_size() { return k; }

double hill::h_profile() { return profile; }

double hill::h_danger() { return danger_status; }

wd hill::change_wind()
{
	wind.w_strength = randomValueHill() * wind.w_strength + randomValueHill() * (1 - wind.w_strength);
	wind.w_direction = wind.w_direction + (randomValueHill() - 0.5);

	return wind;
}