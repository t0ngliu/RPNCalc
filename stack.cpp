#ifndef STACK_CPP
#define STACK_CPP

stack::stack()
{
    head = NULL;
    top = -1;
}

stack::~stack()
{
    emptyList();
}

//pushes a new number on the stack, it becomes the head of the linked list
void stack::push(float in)
{
    top++;
    NODE* node = new NODE;
    node -> num = in;
    node -> next = head;
    head = node;
}

//returns the number on the top of the stack, then delete it and release memory
float stack::pop()
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

//get the value of the (num+1)th position in the stack
float stack::get(int num)
{
    NODE* node = head;
    if (num > top)      //if not enough numbers
        return(0);
    for (int i = 0; i < num; i++)   //counts over num times
        node = node -> next;
    return(node -> num);
}

bool stack::isEmpty()
{
    if(head == NULL)
        return(true);
    return(false);
}

//returns the number of items in the stack
int stack::getSize()
{
    return(top + 1);
}

//clear the stack
void stack::emptyList()
{
    while(head)
        pop();
    top = -1;
}
#endif
