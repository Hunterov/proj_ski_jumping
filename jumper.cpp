#include "declarations.h"
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <math.h>
#include <string>

using namespace std;

vector <string> jumper::names;

void jumper::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

double randomValueJumper()
{
	return ((double) rand() / (RAND_MAX));
}

jumper::jumper()
{
	static int amountOfNames = (init(), names.size());
	name = names[rand() % amountOfNames];

	strength = randomValueJumper() + 1;
	form = sqrt(randomValueJumper());
	gain = { randomValueJumper() + 1, randomValueJumper() + 1, randomValueJumper() + 1 };
	loss = { randomValueJumper() + 1, randomValueJumper() + 1 };
}

string jumper::_name() {return name; }

bool jumper::jump()
{
	double if_jump_succeed = randomValueJumper();
	death = strength + if_jump_succeed - 1 < 0.7;
	return if_jump_succeed >= 0.4;
}

bool jumper::flight(int h_profile, wd h_wind, int h_k)
{
	double if_flight_succeed = 2 * ( h_profile * gain.issue_force + ( 1 - h_profile ) * gain.silhouette ) 
				- loss.fall_chance - loss.exposure_to_wind * sqrt((sin(h_wind.w_direction))*(sin(h_wind.w_direction))) 
				* h_wind.w_strength;

	double length = ( h_profile * gain.issue_force + ( 1 - h_profile ) * gain.silhouette ) 
					+ sin(h_wind.w_direction) * h_wind.w_strength;

	length = length * h_k/4 + h_k/2;

	jump_length = floor(length);

	notes = rand() % 5 + (if_flight_succeed>1)*10;

	notes += floor(length / h_k * 4);

	death = strength + if_flight_succeed - 2 < 0.7;

	return if_flight_succeed>1;
}

int jumper::_notes() { return notes; }

bool jumper::land(int h_danger)
{
	double if_land_succeed = 1.5 * gain.landing - loss.fall_chance - h_danger;

	death = if_land_succeed < 0.7;

	return if_land_succeed > 1;
}

int jumper::_jump_length() { return jump_length; }

bool jumper::_death() { return death; }