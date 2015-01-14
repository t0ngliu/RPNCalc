/* @author Tong Liu
 * @version 1.0
 */

#ifndef STACK_H
#define STACK_H

struct NODE{
    float num;
    NODE* next;
};

class stack
{
    private:
        int top;    //keeps track of how many items are in the stack
        NODE* head;
    
    public:
        stack();
        ~stack();
        //pushes a new number on the stack, it becomes the head of the linked list
        void push(float in);
        //returns the number on the top of the stack, then delete it and release memory
        float pop();
        float get(int num); //get the value of the (num+1)th position in the stack
        bool isEmpty();
        //returns the number of items in the stack
        int getSize();
        //clear the stack
        void emptyList();
};

/* Each of the opration functions calls the push and pop methods
   defined in parent class stack. Each time one of these operations
   is executed, the size of the stack drops by one.
   All operation functions return true if the operation succeeds,
   otherwise return false */
class mathStack : public stack
{
    public:
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

#include "stack.cpp"
#include "mathstack.cpp"
    
#endif
