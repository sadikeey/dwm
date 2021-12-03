#include <stdio.h>
#include <math.h>

float f(int x)
{
    return (x * x * x - 4 * x - 9);
}

void main()
{
    float x1 = 2, x2 = 3, x3, fx;
    for (int i = 1; i <= 7; i++)
    {
        printf("\nIteration %d\n", i);
        x3 = (x1 + x2) / 2;
        printf("Approx Value of x%d = %f\n", i, x3);
        fx = f(x3);
        if (fx > 0)
            x2 = x3;
        else
            x1 = x3;
    }
}
