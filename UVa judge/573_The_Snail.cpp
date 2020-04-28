#include <stdio.h>
#include <cmath>

int main ()
{
    int H,U,D,F,days;
    float u, distance_climb, distance_sliding, fatigue;
    while (scanf("%d %d %d %d", &H, &U, &D, &F), H > 0)
    {
        days = 0;
        fatigue = (U*(F))/100.0;
        distance_sliding = 0;
        distance_climb = 0;
        u = U;
        while(distance_sliding >= 0 && distance_climb <= H)
        {
            days ++;
            distance_climb = distance_sliding + u;
            if (distance_sliding + u - D >= 0)
                distance_sliding = distance_sliding + u - D;
            else
                break;
            u = (u - fatigue > 0) ? u - fatigue : 0; 
        }
        if (distance_climb > H)
            printf("success on day %d\n", days);
        else
            printf("failure on day %d\n", days);
    }
    
}