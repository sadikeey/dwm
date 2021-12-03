#include <stdio.h>
#include <math.h>
float f(float x)
{
       return (x * x * x - 4 * x - 9);
}
float eqn(float x1, float x2, float f1, float f2)
{
       float x;
       return x = (x1 * f2 - x2 * f1) / (f2 - f1);
}
void main()
{
       float x1 = 2, x2 = 3, x3, f1, f2, f3;
       for (int i = 1; i <= 6; i++)
       {
              printf("\n\nIteration %d:", i);
              f1 = f(x1);
              printf("\nf1=%f", f1);
              f2 = f(x2);
              printf("\nf2=%f", f2);
              x3 = eqn(x1, x2, f1, f2);
              printf("\nx3=%4f", x3);
              f3 = f(x3);
              printf("\nf3=%4f", f3);
              x1 = x2;
              x2 = x3;
       }
       printf("\n\nFinal Root = %4f\n", x3);
}
