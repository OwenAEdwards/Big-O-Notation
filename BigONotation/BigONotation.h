#pragma once
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

int N,c;
struct timeval start,stop;

int input() {
    printf("Input \'N\' to compare time complexities: ");
    scanf("%d",&N);
    getchar();
    printf("\n");
    return N;
}

double constant(int N) {
    printf("Constant time complexity, O( 1 ): \n");
    // getchar();
    gettimeofday(&start,NULL);
    printf("%d\n",N);
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

/* 
two other implementations of O( log_2(N) ) below:
1.)
for (int i=1;i<=N;i=i*2)

2.) 
x = N 
while ( x > 0 ) { 
    x = x / 2 
}

takeaway: each input is divided in half after each iteration
*/
double logarithmic(int N) {
    printf("Logarithmic time complexity, O( log_2(N) ): \n");
    // getchar();
    c=1;
    gettimeofday(&start,NULL);
    for (int i=1;i<=log(N);i++) {
        printf("%d\n",c);
        c++;
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

// NOTE: O(N+2), O(N-2), O(N*2), O(N/2) are all functions of the same set as O(N) where exponentiation makes the real
// difference in time complexity, we simply refer to all of these functions as O(N)
double linear(int N) {
    printf("Linear time complexity, O( N ): \n");
    // getchar();
    gettimeofday(&start,NULL);
    for (int i=1;i<=N;i++) {
        printf("%d\n",i);
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

/*
another implementation of O( N*log_2(N) ):
x = N
while ( x > 0 ) {
    y = N
    while ( y > 0 ) {
        y = y / 2 
    }
    x = x - 1 
}
*/
double loglinear(int N) {
    printf("Quasilinear/Linearithmic/Log-Linear time complexity, O( N*log_2(N) ): \n");
    // getchar();
    c=1;
    gettimeofday(&start,NULL);
    for (int i=1;i<=(N*log(N));i++) {
        printf("%d\n",c);
        c++;
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

double quadratic(int N) {
    printf("Quadratic time complexity, O( N^(2) ): \n");
    // getchar();
    c=1;
    gettimeofday(&start,NULL);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d\n",c);
            c++;
        }
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

double cubic(int N) {
    printf("Cubic time complexity, O( N^(3) ): \n");
    // getchar();
    c=1;
    gettimeofday(&start,NULL);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            for (int k=1;k<=N;k++) {
                printf("%d\n",c);
                c++;
            }
        }
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

// NOTE: exponential time complexity is technically c^N where c is any constant >1 however, I arbitrarily chose c=2
// NOTE 2: exponential time is slower than cubic (or any polynomial) time for large N, specifically solving,
// 2^N=N^3 => N>9.93953...
double exponential(int N) {
    printf("Exponential time complexity, O( 2^(N) ): \n");
    // getchar();
    gettimeofday(&start,NULL);
    for (int i=1;i<=pow(2,N);i++) {
        printf("%d\n",i);
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

int recursiveFactorial(int N) {
    if (N==0) {
        return 1;
    }
    else {
        return N*recursiveFactorial(N-1);
    }
}

// NOTE: factorial is slower than exponential for larger N, all of this comes from calculus
double factorial(int N) {
    printf("Factorial time complexity, O( N! ): \n");
    // getchar();
    gettimeofday(&start,NULL);
    for (int i=1;i<=recursiveFactorial(N);i++) {
        printf("%d\n",i);
    }
    gettimeofday(&stop,NULL);
    // getchar();
    return (stop.tv_sec-start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
}

void summary 
(
    double constantTime,
    double logarithmicTime,
    double linearTime,
    double loglinearTime,
    double quadraticTime,
    double cubicTime,
    double exponentialTime,
    double factorialTime
) 
{
    printf("Constant time complexity O( 1 ) execution time: %f milliseconds\n",constantTime/1000);
    printf("Logarithmic time complexity O( log_2(N) ) execution time: %f milliseconds\n",logarithmicTime/1000);
    printf("Linear time complexity O( N ) execution time: %f milliseconds\n",linearTime/1000);
    printf("Quasilinear/Linearithmic/Log-Linear time complexity O( N*log_2(N) ) execution time: %f milliseconds\n",loglinearTime/1000);
    printf("Quadratic time complexity O( N^(2) ) execution time: %f milliseconds\n",quadraticTime/1000);
    printf("Cubic time complexity O( N^(3) ) execution time: %f milliseconds\n",cubicTime/1000);
    printf("Exponential time complexity O( 2^(N) ) execution time: %f milliseconds\n",exponentialTime/1000);
    printf("Factorial time complexity O( N! ) execution time: %f milliseconds\n",factorialTime/1000);
}