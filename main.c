#include "sabrCalculations.c"

int main() {

  float babip = calculateBABIP(85, 12, 348, 79, 3);
  printf ("Lars Nootbaar's 2024 babip is: %.3f\n", babip);
  return 0;
	
}
