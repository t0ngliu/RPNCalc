#ifndef STACK_HPP
#define STACK_HPP

struct NODE{
    float num;
    NODE* next;
};

class Stack
{
    private:
        int top;    //keeps track of how many items are in the stack
        NODE* head;
    
    public:
        Stack();
        ~Stack();
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
    
#endif
