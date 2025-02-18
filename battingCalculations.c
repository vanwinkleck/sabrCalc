#include <stdio.h>

float calculateOnBase(double hits, double walks, double HBP, double atBats, double sacFly) {
	return (hits + walks + HBP) / (atBats + walks + HBP + sacFly); 
}

double calculateTotalBases(int singles, int doubles, int triples, int homeRuns) {
	return singles + (doubles * 2) + (triples * 3) + (homeRuns * 4);
};

float calculateSlug(int singles, int doubles, int triples, int HR, int atBats) {
	return calculateTotalBases(singles, doubles, triples, HR) / atBats;
}

float calculateOPS(double singles, double doubles, double triples, double HR, double hits, double walks, double HBP, double atBats, double sacFly) {
	return calculateSlug(singles, doubles, triples, HR, atBats) + calculateOnBase(hits, walks, HBP, atBats, sacFly);
}
// Need to adjust for ballpark. 
int calculateOPSPlus (float leagueOBP, float OBP, float leagueSLG, float SLG) {
	return 100 * ((OBP / leagueOBP) + (SLG / leagueSLG) - 1);
}

float calculateBABIP(double hits, double HR, double atBats, double SO, double SF)
{
  return (hits - HR) / (atBats - SO - HR + SF);
}

int test()
{
	
  float onBase = calculateOnBase(163, 47, 13, 587, 5);
	printf ("Brendan Donovan's onBase is: %.3f:\n", onBase);

	float slug = calculateSlug(112, 34, 3, 14, 587);
	printf ("Brendan Donovan's slugging is: %.3f\n", slug);

	float ops = calculateOPS(112, 34, 3, 14, 163, 47, 13, 587, 5);
	printf ("Brendan Donovan's ops is: %.3f\n", ops);

	return 0;
}
