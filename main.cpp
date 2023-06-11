#include <iostream>
#include <cstdio>
#include <cmath>

bool isPrime(int a){
    const int cutoff = sqrt(a);
    bool isPrime= true;
    size_t i;
    for(i=2; i<=cutoff;i++){
        if(a%i==0){
            isPrime= false;
        }
    }
    return isPrime;

}



int main() {
    std::cout << "Hello, World please give a natural number to see if it is prime" << std::endl;
    int n;
    std::cin >> n;

    printf( "Hello, the number you have selected is %d and it is%s prime",n,isPrime(n)?"":" not");


    return 0;
}


