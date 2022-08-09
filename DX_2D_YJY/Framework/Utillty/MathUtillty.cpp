#include "framework.h"
#include "MathUtillty.h"

int MathUtillty::RandomInt(int min, int max)
{
    // Random (5.10)....
    int range = rand() % (max - min);

    return min + range;
}

float MathUtillty::RandomFloat(float min, float max)
{
    float normal = (float)rand() / (float)RAND_MAX; 

    return min + (max - min) * normal;
    
}
