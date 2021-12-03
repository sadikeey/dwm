#include <stdio.h>
#include <math.h>

float eqn(float x)
{
    return (2 * x - cos(x) - 3);
}

float f(float x)
{
    return ((cos(x) + 3) / 2);
}

float df(float x)
{
    return (-sin(x) / 2);
}

void main()
{
    float a = 1, b = 2, x0 = 1.5, x;
    int i = 1;
    float f2;

    f2 = fabs(df(x0));
    if (f2 < 1)
    {
        do
        {
            printf("Iteration %d\n", i);
            x = f(x0);
            printf("Approx root=%f\n", x);
            x0 = x;
            i++;
        } while (i <= 8);
    }
    else
    {
        printf("Approx root can't be find with the help of iteration method");
    }
    printf("Thus, Approximated value= %4f", x);
}
