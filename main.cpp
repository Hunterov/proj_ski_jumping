#include "declarations.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define HIT_INTERVAL 500000

using namespace std;

int main(int argc, char const *argv[])
{
	srand(argc == 2 
		? atoi(argv[1]) 
		: time(NULL));

	int jmp = 50;

	int dead = 0;

	jumper jumpers[jmp];

	hill hills;

	printf("Dzisiaj skoczkowie skaczą na skoczni K%d\n", hills.h_size());

	usleep(HIT_INTERVAL);

	for(int i=0; i<jmp; i++)
	{
		usleep(HIT_INTERVAL);

		printf("%d. %s: ", i+1, jumpers[i]._name().c_str());

		if (jumpers[i].jump())
		{	
			printf("Wybił się. ");

			if (jumpers[i].flight(hills.h_profile(), hills.change_wind(), hills.h_size() ))
			{	
				printf("Leci. ");

				if (jumpers[i].land(hills.h_danger() ))
				{	
					printf("Wylądował. ");

					printf("Odległość: %d. ", jumpers[i]._jump_length());
					int score = 3*jumpers[i]._notes() + 120 + floor(1.2*(jumpers[i]._jump_length() - hills.h_size()));

					printf("Punkyty za skok: %d.\n", score);
				}
				else
				{
					if(jumpers[i]._death())
						printf("Złamał kark podczas telemarku. ", dead++);
					else
						printf("Wyrżnął glebę, nie wzbudził poruszenia. ");

					printf("Odległość: %d. ", jumpers[i]._jump_length());
					int score = 3*jumpers[i]._notes() + 60 + floor(1.2*(jumpers[i]._jump_length() - hills.h_size()));

					printf("Punkyty za skok: %d.\n", score);
				}
			}
			else
			{
				if(jumpers[i]._death())
					printf("Spadł na śmierć. \n", dead++);
				else
					printf("Spadł, ale przeżył. \n");
			}	
		}
		else
		{
			if(jumpers[i]._death())
				printf("Zginął na progu. \n", dead++);
			else
				printf("Nie wybił się, przeżył. \n");
		}
	}

	printf("Podczas zawodów do wieczności odeszło: %d skoczów. Wieczny odpoczynek...\n", dead);

	if (dead >= floor(jmp*0.7))
		printf("Zawody obfite w śmierć i emocje.\n");
	else
		printf("Nuda...\n");
}