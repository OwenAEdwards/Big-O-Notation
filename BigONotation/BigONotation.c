#include "BigONotation.h"

int main() {
    int N=input();
    
    double constantTime=constant(N);

    double logarithmicTime=logarithmic(N);
    
    double linearTime=linear(N);
    
    double loglinearTime=loglinear(N);

    double quadraticTime=quadratic(N);

    double cubicTime=cubic(N);

    double exponentialTime=exponential(N);

    double factorialTime=factorial(N);

    printf("\n");

    summary
    (
    constantTime,
    logarithmicTime,
    linearTime,
    loglinearTime,
    quadraticTime,
    cubicTime,
    exponentialTime,
    factorialTime
    );

    return 0;
}