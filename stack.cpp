#include "Stack.hpp"

Stack::Stack()
{
    head = NULL;
    top = -1;
}

Stack::~Stack()
{
    emptyList();
}

//pushes a new number on the Stack, it becomes the head of the linked list
void Stack::push(float in)
{
    top++;
    NODE* node = new NODE;
    node -> num = in;
    node -> next = head;
    head = node;
}

//returns the number on the top of the Stack, then delete it and release memory
float Stack::pop()
{
    if (head)
    {
        top--;
        NODE* popped = head;
        float value = head -> num;
        head = head -> next;        //the next number becomes the new head
        delete popped;
        return(value);
    }
    return(0);
}

//get the value of the (num+1)th position in the Stack
float Stack::get(int num)
{
    NODE* node = head;
    if (num > top)      //if not enough numbers
        return(0);
    for (int i = 0; i < num; i++)   //counts over num times
        node = node -> next;
    return(node -> num);
}

bool Stack::isEmpty()
{
    if(head == NULL)
        return(true);
    return(false);
}

//returns the number of items in the Stack
int Stack::getSize()
{
    return(top + 1);
}

//clear the Stack
void Stack::emptyList()
{
    while(head)
        pop();
    top = -1;
}
