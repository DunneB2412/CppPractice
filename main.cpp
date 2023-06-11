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
    std::cout << "Hello, World!" << std::endl;//

    printf( "Hello, World! here is a thing:%d",isPrime(21));


    return 0;
}


