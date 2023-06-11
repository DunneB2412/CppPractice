//
// Created by Brian Dunne on 11/06/2023.
//
#include <cmath>

#ifndef UNTITLED_FIBONIES_H
#define UNTITLED_FIBONIES_H

#endif //UNTITLED_FIBONIES_H

int fib(int n){
    unsigned long xnm1 = 1;
    unsigned long xnm2 = -1;
    unsigned long xn = 0;
    size_t i;
    for(i=0; i<n;i++){//iterate over the sequence until xn is for the provided n
        xn = xnm1+xnm2;
        xnm2=xnm1;
        xnm1=xn;
        //printf( "%lu,", xn);
    }
    return xn;
}
