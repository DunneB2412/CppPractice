//
// Created by Brian Dunne on 12/06/2023.
//
#include <string>
#ifndef UNTITLED_BIGINT_H
#define UNTITLED_BIGINT_H

namespace BigMath {
    class Element{
        //flags arangesd as vczn.
        //if n or c is set, just carry. if v is set, preserve negative.
        static const unsigned int nMask = 0x40000000;
        static const unsigned int cMask = 0x80000000;
        static const unsigned int valMask = 0x7fffffff;

        int val;
        Element *next;
    public:
        Element(int val, Element *n){
            this->val = val;
            this->next = n;
        }
        explicit Element(int val) : Element(val, nullptr){}


        short add(Element *o, short _c_in);
        Element * getNext(){
            return next;
        }
        void setNext(Element *e){
            next = e;
        }
        int getValue(){
            return val;
        }

//        Element * getComp2s(){
//            return new Element((val*-1)&valMask);
//        }
    };

    class BigInt {
        static const unsigned int sMask = 0x8000;
        static const unsigned int zMask = 0x4000;
        static const unsigned int sizeMask = 0x0FFF;

        [[maybe_unused]] Element *start;
        short props;

    public:
        BigInt(int init){
            if(init < 0){
                props = props | sMask;
                init = init*-1;
            }
            if(init == 0){
                props = props | zMask;
            }
            start = new Element(init);
        }
        BigInt() : BigInt(0) { }


        short add(BigInt *o);
        short sub(BigInt *o);
        short mul(BigInt *o);
        short div(BigInt *o);
        short mod(BigInt *o);
        std::string to_string();

    };



} // BigMath

#endif //UNTITLED_BIGINT_H
