#include <iostream>
#include <cstdio>
#include "functions/FizBuzz.h"
#include "functions/Fibonies.h"
#include "functions/Prime.h"


int main() {
    std::cout << "Hello, World please give a natural number to see if it is prime" << std::endl;
    int n;
//    std::cin >> n;
//
//    printf( "Hello, the number you have selected is %d and it is%s prime",n,isPrime(n)?"":" not");

//    std::cout << "\nHow about we find a specific prime, please give a natural number to request that nth prime number" << std::endl;
//    std::cin >> n;
//
//    printf( "Hello, the number you have selected is %d and behold %d is your new lucky number\n",n, findNth(n));

//    size_t i;
//    for(i=1; i<100;i++){//starts at 7 as next bigest prime, only check odd numbers
//        printf( "%s,", fizzBuzzIt(i).c_str());
//    }

    printf( "Hello,behold %ull is your new  supper doper lucky number\n",fib(50));

    return 0;
}
