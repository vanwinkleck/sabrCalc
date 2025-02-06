#include <stdio.h>

float calculatehr9(float ip, float hr) {
	return (hr / ip) * 9;
}

float calculateh9(float hits, float ip) {
	return (hits / ip ) * 9;
}

// Need to adjust for ballpark. 
int calculateOPSPlus (float leagueOBP, float OBP, float leagueSLG, float SLG) {
	return 100 * ((OBP / leagueOBP) + (SLG / leagueSLG) - 1);
}

int main()
{
	float ip, hr;

	printf("Enter innings pitched: ");
	scanf("%f", &ip);

	printf("Enter home runs allowed: ");
	scanf("%f", &hr);

	float hr9 = calculatehr9(ip, hr);

	printf("This pitcher's home runs per 9 is %.2f:\n", hr9);

	int opsPlus = calculateOPSPlus(.315, .394, .399, .379);
	printf ("Brendan Donvan's OPS plus is: %i:\n", opsPlus);
	return 0;
}
