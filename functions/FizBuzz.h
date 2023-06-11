//
// Created by Brian Dunne on 11/06/2023.
//

#include <string>
#include <iostream>

#ifndef UNTITLED_FIZBUZZ_H
#define UNTITLED_FIZBUZZ_H

#endif //UNTITLED_FIZBUZZ_H


bool isFizz(int a){
    return a%3==0;
}
bool isBuzz(int a){
    return a%5==0;
}
std::string fizzBuzzIt(int a){
    bool hit=false;
    std::string result ="";
    if(isFizz(a)){
        hit= true;
        result+="Fizz";
    }
    if(isBuzz(a)){
        hit= true;
        result += "Buzz";
    }
    if(!hit)result = std::to_string(a);
    return result;
}
