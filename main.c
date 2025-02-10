#include <stdio.h>

float calculatehr9(float ip, float hr) {
	return (hr / ip) * 9;
}

float calculateh9(float hits, float ip) {
	return (hits / ip ) * 9;
}

double calculateTotalBases(int singles, int doubles, int triples, int homeRuns) {
	return singles + (doubles * 2) + (triples * 3) + (homeRuns * 4);
};

// Todo 
float calculateOPS(float onBase, float slug) {
	return 0;
}

float calculateSlug(int singles, int doubles, int triples, int HR, int atBats) {
	return calculateTotalBases(singles, doubles, triples, HR) / atBats;
}

// Need to adjust for ballpark. 
int calculateOPSPlus (float leagueOBP, float OBP, float leagueSLG, float SLG) {
	return 100 * ((OBP / leagueOBP) + (SLG / leagueSLG) - 1);
}

// I'm pretty sure this is correct now, I'm just missing the actual park factor baseballref uses. 
int calculateERAPlus(float parkFactor, float leagueERA, float ERA) {
	int ERAPlus = (leagueERA * parkFactor) * 100 / ERA;
	return ERAPlus;
}




int main()
{
	/* float ip, hr;

	printf("Enter innings pitched: ");
	scanf("%f", &ip);

	printf("Enter home runs allowed: ");
	scanf("%f", &hr);

	float hr9 = calculatehr9(ip, hr);

	printf("This pitcher's home runs per 9 is %.2f:\n", hr9);

	int opsPlus = calculateOPSPlus(.315, .394, .399, .379);
	printf ("Brendan Donvan's OPS plus is: %i:\n", opsPlus); 

	int eraPlus = calculateERAPlus(1.00, 4.02, 3.51);
	printf ("Sonny Gray's ERA+ is: %d:\n", eraPlus);*/ 

	float slug = calculateSlug(112, 34, 3, 14, 587);
	printf ("Brendan Donovan's slugging is: %.3f:\n", slug);
	return 0;
}
