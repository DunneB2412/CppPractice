//
// Created by Brian Dunne on 12/06/2023.
//

#include "BigInt.h"

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
            flags = a->add(b,(flags&4)>>3);
        }while ((flags&6)>0);
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

    std::string BigInt::to_string() {
        return std::string();
    }
} // BigMath