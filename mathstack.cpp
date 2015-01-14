/* @author Tong Liu
 * @version 1.0
 */

#ifndef MATHSTACK_CPP
#define MATHSTACK_CPP
#define PI 3.14159265359

#include <cmath>

/* Each of the opration functions calls the push and pop methods
   defined in stack header file. Each time one of these operations
   is executed, the size of the stack drops by one.
   All operation functions return true if the operation succeeds,
   otherwise return false */
   
bool mathStack::add()
{
    push(pop() + pop());
    return(true);
}

bool mathStack::subtract()
{
    push(0 - pop() + pop());
    return(true);
}

bool mathStack::multiply()
{
    push(pop() * pop());
    return(true);
}

bool mathStack::divide()
{
    if (get(0) != 0)  //cannot divide by zero
    {
        push(1/pop() * pop());
        return(true);
    }
    return(false);
}

bool mathStack::takesin()
{
    if (fmod(get(0), 180) == 0)     //for rounding reasons when converting to degrees, sin(90) will not return 0 otherwise
        push(0);
    else
        push(sin(pop() / 180 * PI));
    return(true);
}

bool mathStack::takecos()
{
    if (fmod(get(0) - 90, 180) == 0) //see above
        push(0);
    else
        push(cos(pop() / 180 * PI));
    return(true);
}

bool mathStack::taketan()
{
    if (fmod(get(0) - 90, 180) != 0)
    {
        if (fmod(get(0), 180) == 0)     //see above
            push(0);
        else
            push(tan(pop() / 180 * PI));
        return(true);
    }
    return(false);
}

bool mathStack::takeasin()
{
    if (get(0) >= -1 && get(0) <= 1)  //domain check
    {
        push(asin(pop()) / PI * 180);
        return(true);
    }
    return(false);
}

bool mathStack::takeacos()
{
    if (get(0) >= -1 && get(0) <= 1)  //domain check
    {
        push(acos(pop()) / PI * 180);
        return(true);
    }
    return(false);
}

bool mathStack::takeatan()
{
    push(atan(pop()) / PI * 180);
    return(true);
}

bool mathStack::power()
{
    if (finite(pow(get(1), get(0))))  //finite(float) checks if the number is defined (that is, not NaN) 
    {
        push(pow(pop(), pop()));
        return(true);
    }
    return(false);
}

bool mathStack::square()
{
    float num = pop();
    push(num * num);
    return(true);
}

bool mathStack::sqroot()
{
    if (get(0) >= 0)        //domain check
    {
        push(sqrt(pop()));
        return(true);
    }
    return(false);
}

bool mathStack::takelog()
{
    if (get(0) > 0)         //domain check
    {
        push(log10(pop()));
        return(true);
    }
    return(false);
}

bool mathStack::ln()
{
    if (get(0) > 0)         //domain check
    {
        push(log(pop()));
        return(true);
    }
    return(false);
}

bool mathStack::rcp()
{
    if (get(0) != 0)       //0 has no defined reciprocal
    {
        push(1 / pop());
        return(true);
    }
    return(false);
}

bool mathStack::flipsign()
{
    push(-1 * pop());
    return(true);
}

bool mathStack::xchge()
{
    float a = pop();
    float b = pop();
    push(a);
    push(b);
    return(true);
}

//returns the value from the top of the stack without removing it from the stack
float mathStack::display()
{
    return get(0);
}
#endif
