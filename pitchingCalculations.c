#include <stdio.h>

 struct leagueNumbers {
  float leagueERA;
  double leagueHRAllowed;
  double leagueBBAllowed;
  double leagueHBPAllowed;
  double leagueK;
  double leagueIP;
};

struct pitcherNumbers {
  double HRAllowed;
  double BBAllowed;
  double HPBAllowed;
  double HitsAllowed;
  double K;
  double IP;
};


float calculateHR9(struct pitcherNumbers pitcher)
{
  return ( pitcher.HRAllowed / pitcher.IP ) * 9;
}

float calculateH9(struct pitcherNumbers pitcher) {
	return ( pitcher.HitsAllowed / pitcher.IP ) * 9;
}

float calculateFIPConstant(struct leagueNumbers year)
{
  return year.leagueERA - (((year.leagueHRAllowed * 13) + (3 * (year.leagueBBAllowed + year.leagueHBPAllowed)) - (2 * year.leagueK)) / year.leagueIP); 
}

float calculateFIP(struct pitcherNumbers pitcher, float fipConstant)
{
  return ((pitcher.HRAllowed * 13) + (3 * (pitcher.BBAllowed + pitcher.HPBAllowed)) - (2 * pitcher.K)) / pitcher.IP + fipConstant;
}


// I'm pretty sure this is correct now, I'm just missing the actual park factor baseballref uses. 
int calculateERAPlus(float parkFactor, float leagueERA, float ERA) {
  return (leagueERA * parkFactor) * 100 / ERA;
}


int main() {

  struct leagueNumbers s2024;
  struct pitcherNumbers gray;

  s2024.leagueERA = 4.07;
  s2024.leagueHRAllowed = 5453;
  s2024.leagueBBAllowed = 14929;
  s2024.leagueHBPAllowed = 2020;
  s2024.leagueK = 41197;
  s2024.leagueIP = 43116.1;

  gray.HRAllowed = 21;
  gray.BBAllowed = 39;
  gray.HPBAllowed = 3;
  gray.HitsAllowed = 142;
  gray.K = 203;
  gray.IP = 166.1;

  float sonnyFIP, sonnyH9, sonnyHR9;

  sonnyFIP = calculateFIP(gray, calculateFIPConstant(s2024));
  printf("Sonny Gray's 2024 FIP is: %.2f\n", sonnyFIP);

  sonnyH9 = calculateH9(gray);
  printf("Sonny Gray's 2024 H/9 is : %.1f\n", sonnyH9);

  sonnyHR9 = calculateHR9(gray);
  printf("Sonny Gray's 2024 HR/9 is: %.1f\n", sonnyHR9);

  return 0;
}
