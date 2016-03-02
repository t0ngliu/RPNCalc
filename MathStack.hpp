#ifndef MATHSTACK_HPP
#define MATHSTACK_HPP

/* Each of the opration functions calls the push and pop methods
   defined in parent class stack. Each time one of these operations
   is executed, the size of the stack drops by one.
   All operation functions return true if the operation succeeds,
   otherwise return false */
class MathStack : public Stack
{
    public:
        MathStack();
        bool add();
        bool subtract();
        bool multiply();
        bool divide();
        bool takesin();
        bool takecos();
        bool taketan();
        bool takeasin();
        bool takeacos();
        bool takeatan();
        bool power();
        bool square();
        bool sqroot();
        bool takelog();
        bool ln();
        bool rcp();
        bool flipsign();
        bool xchge();
        //returns the value from the top of the stack without removing it from the stack
        float display();
};

#endif