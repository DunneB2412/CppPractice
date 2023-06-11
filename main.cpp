#include <iostream>
#include <cstdio>
#include <cmath>



bool isPrime(int a){//no significant information avalable
    //trivial filters
    if(a<=1){//assume everything below or equal to 1 as not prime.
        return false;
    }
    int mod = a%6;
    if(a>3&&(mod==2||mod==3||mod==4)){//checks for 2 or 3 as multible
        return false;
    }
    if(a>5&&a%5==0){//checks for 5 as multible
        return false;
    }
    const int cutoff = sqrt(a);
    size_t i;
    for(i=7; i<=cutoff;i+=2){//starts at 7 as next bigest prime, only check odd numbers
        if(a%i==0){
            return false;
        }
    }
    return true;
}

bool isPrime(int a, int p[], int top){//with prepared list,  assumes this list contains all primes up untill this number
    if(a<=1){//assume everything below or equal to 1 as not prime. still needs to catch
        return false;
    }
    const int cutoff = sqrt(a);
    size_t i;
    for(i=0; i<top;i++){//ran out of prim,es to check
        if(a%p[i]==0){
            return false;
        }
        if(i>=cutoff){//ran over the square root
            return true;
        }
    }
    return true;
}

int findNth(int n){
    int *found = new int[n];
    int top=0;

    int check=1;
    while(top<n){
        if(isPrime(check, found, top)){
            found[top]=check;
            top++;
        }
        check++;
    }
    return found[top-1];
}



int main() {
    std::cout << "Hello, World please give a natural number to see if it is prime" << std::endl;
    int n;
//    std::cin >> n;
//
//    printf( "Hello, the number you have selected is %d and it is%s prime",n,isPrime(n)?"":" not");

    std::cout << "\nHow about we find a specific prime, please give a natural number to request that nth prime number" << std::endl;
    std::cin >> n;

    printf( "Hello, the number you have selected is %d and behold %d is your new lucky number",n, findNth(n));


    return 0;
}

