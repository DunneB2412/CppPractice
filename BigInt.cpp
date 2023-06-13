//
// Created by Brian Dunne on 12/06/2023.
//

#include "BigInt.h"
#include <bitset>

namespace BigMath {


    short Element::add(Element *o,short c_in) {
        short flags =0;


        int result = this->val + o->val +c_in;

        //set n flag
        flags |= (result&nMask)!=0?1:0;
        //set z flag
        flags |= (result&valMask)==0?2:0;
        //set c flag
        flags |= (result&cMask)!=0?4:0;
        //sey v flag
        flags |= (result&(cMask|nMask))==(cMask|nMask)?8:0;
        //place the value without the carry
        val = result&valMask;

        return flags;
    }


    short BigInt::add(BigInt *o) {
        Element *a = start;
        Element *b = o->start;
        short flags;
        do{
            flags = a->add(b,(flags&4)>>2);
            if(((flags&4)==4||b->getNext()!= nullptr) && a->getNext()== nullptr){//if the carry is set or b has a next, extend the number
                a->setNext(new Element(0,a, nullptr));
                end=a->getNext();
            }
            a = a->getNext();
            b = b->getNext()!= nullptr? b->getNext() :new BigMath::Element(0);
        }while ((flags&6)>0&&a!= nullptr);
    }

    short BigInt::sub(BigInt *o) {
        return 0;
    }

    short BigInt::mul(BigInt *o) {
        return 0;
    }

    short BigInt::div(BigInt *o) {


        return 0;
    }

    short BigInt::mod(BigInt *o) {
        return 0;
    }

    void BigInt::bitShift(int s){
        if(s==0)return;
        int jumps = s/31;
        int steps = s%31;
        while (jumps>0){
            if(s>0){
                start = new Element(0, nullptr,start); //stick in a new batch of 31 in at the start
            }else{
                start = start->getNext(); //chop of a batch of 31 at the start
            }
            jumps--;
        }
        if(s>0){
            start = new Element(0, nullptr,start); //stick one extra batch at the start
            steps -=31; //change the direction of the shift.
        }

        int carried = 0;
        Element act = s>0?
        do{

        }while();
        return;
    }

    std::string BigInt::to_string() {
        std::string result ="";
        Element *a = start;
        do{
            result = ((std::bitset<32>(a->getValue())).to_string()).erase(0,1)+result;
            a = a->getNext();
        }while(a!= nullptr);
        return result;
    }

//    std::string dec(){
//
//    }
} // BigMath