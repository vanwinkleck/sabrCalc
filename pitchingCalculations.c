#include <stdio.h>

float calculatehr9(float ip, float hr) {
	return (hr / ip) * 9;
}

float calculateh9(float hits, float ip) {
	return (hits / ip ) * 9;
}

float calculateFIPConstant(float ERA, double HR, double BB, double HBP, double K, double IP)
{
  return ERA - (((HR * 13) + (3*(BB+HBP)) - (2 * K)) / IP);
}

float calculateFIP(double HR, double BB, double HBP, double K, double IP, double fipConstant)
{
  return ((HR * 13) + (3 * (BB + HBP)) - (2 * K)) / IP + fipConstant;
}


// I'm pretty sure this is correct now, I'm just missing the actual park factor baseballref uses. 
int calculateERAPlus(float parkFactor, float leagueERA, float ERA) {
  return (leagueERA * parkFactor) * 100 / ERA;
}


int main() {


  float sonnyFIP;

  sonnyFIP = calculateFIP(21, 39, 3, 203, 166.1, calculateFIPConstant(4.07, 5453, 14929, 2020, 41197, 43116.1));
  printf("Sonny Gray's 2024 FIP is: %.2f\n", sonnyFIP);

  return 0;
}
