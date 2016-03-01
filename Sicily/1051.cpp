#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

#define pi 3.1415927

using namespace std;

// 1051. Biker's Trip Odomete
/* Sample Input

    26 1000 5
    27.25 873234 3000
    26 0 1000
   Sample Output

    Trip #1: 1.29 928.20
    Trip #2: 1179.86 1415.84

*/

int main() {
    int count = 0;
    float diameter,revolutions,time;

    scanf("%f %f %f", &diameter,&revolutions,&time);
    while (revolutions != 0) {
        count ++;

        float distance = diameter * pi * revolutions / 5280 / 12;
        float MPH = distance / (time / 3600);

        printf("Trip #%d: %.2f %.2f\n", count, distance, MPH);

        scanf("%f %f %f", &diameter,&revolutions,&time);
    }
    return 0;
}