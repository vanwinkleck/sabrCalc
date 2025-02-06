#include <stdio.h>

// Define constants for offensive statistics weights
const float BATTING_AVG_WEIGHT = 0.2;
const float OBP_WEIGHT = 0.3;
const float SLG_WEIGHT = 0.5;
const float WAR_SCALE = 1.8; // This is a scaling factor used in baseball WAR calculations

// Function to calculate WAR based on given offensive statistics
float calculateWAR(float battingAvg, float obp, float slg) {
    float battingComponent = BATTING_AVG_WEIGHT * battingAvg;
    float obpComponent = OBP_WEIGHT * obp;
    float slgComponent = SLG_WEIGHT * slg;
    
    // Sum the components and scale by WAR_SCALE
    return (battingComponent + obpComponent + slgComponent) * WAR_SCALE;
}

int main() {
    // Example usage of the function
    float battingAvg, obp, slg;
    
    printf("Enter batting average: ");
    scanf("%f", &battingAvg);
    
    printf("Enter on-base percentage (OBP): ");
    scanf("%f", &obp);
    
    printf("Enter slugging percentage (SLG): ");
    scanf("%f", &slg);
    
    // Calculate WAR using the function
    float war = calculateWAR(battingAvg, obp, slg);
    
    printf("Calculated WAR: %.2f\n", war);
    
    return 0;
}
