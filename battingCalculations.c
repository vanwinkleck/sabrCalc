#include <stdio.h>

struct leagueNumbers{
  double leagueOBP;
  double leagueSLG;
};

struct playerNumbers {
  double hits;
  double BB;
  double HBP;
  double atBats;
  double PA;
  double SF;
  double SO;
  double singles;
  double doubles;
  double triples;
  double HR;
};


float calculateOnBase(struct playerNumbers player) {
	return (player.hits + player.BB + player.HBP) / (player.atBats + player.BB + player.HBP + player.SF); 
}

double calculateTotalBases(struct playerNumbers player) {
	return player.singles + (player.doubles * 2) + (player.triples * 3) + (player.HR * 4);
};

float calculateSlug(struct playerNumbers player) {
	return calculateTotalBases(player) / player.atBats;
}

float calculateOPS(struct playerNumbers player) {
	return calculateSlug(player) + calculateOnBase(player);
}
// Need to adjust for ballpark. 
int calculateOPSPlus (struct playerNumbers player, struct leagueNumbers lg) {
	return 100 * (calculateOnBase(player) / lg.leagueOBP + calculateSlug(player) / lg.leagueSLG - 1);
}

float calculateBABIP(struct playerNumbers player)
{
  return (player.hits - player.HR) / (player.atBats - player.SO - player.HR + player.SF);
}

float calculateWalkRate(struct playerNumbers player) {
  return (player.BB / player.PA) * 100;
}

int main()
{

  struct playerNumbers donny;
  struct leagueNumbers year;
  int parkFactor = 98;
  
  donny.hits = 163;
  donny.BB = 47;
  donny.HBP = 13;
  donny.atBats = 587;
  donny.PA = 652;
  donny.SF = 5;
  donny.SO = 81;
  donny.singles = 112;
  donny.doubles = 34;
  donny.triples = 3;
  donny.HR = 14;

  year.leagueOBP = 0.312;
  year.leagueSLG = 0.399;

  float onBase = calculateOnBase(donny);
	printf ("Brendan Donovan's onBase is: %.3f:\n", onBase);

	float slug = calculateSlug(donny);
	printf ("Brendan Donovan's slugging is: %.3f\n", slug);

	float ops = calculateOPS(donny);
	printf ("Brendan Donovan's ops is: %.3f\n", ops);

  int opsPlus = calculateOPSPlus(donny, year);
  printf ("Brendan Donovan's 2024 OPS+ is: %i\n", opsPlus);

  double walkRate = calculateWalkRate(donny);
  printf ("Brendan Donovan's 2024 walk rate is: %.2f%%\n", walkRate);

	return 0;
}
