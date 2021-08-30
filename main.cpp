/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char *p);   //1
    int value;//2
    std::string name;//3
};

T::T(int v, const char* p) : value(v), name(p){}


struct Compare                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            T &aa = *a;
            T &bb = *b;
            if( aa.value < bb.value ) return *a;
            if( aa.value > bb.value ) return *b;
        }
        return nullptr;
    }
};

struct U
{
    float value1 { 0 }, value2 { 0 };
    float uPrintUpdated(float* updatedValue)      //12
    {   
        if(updatedValue != nullptr)
        {
            float &newValue = *updatedValue;
            std::cout << "U's value1 value: " << value1 << std::endl;
            value1 = newValue;
            std::cout << "U's value1 updated value: " << value1 << std::endl;
            while( std::abs(value2 - value1) > 0.001f )
            {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */

                value2 += 0.5f;
            }
            std::cout << "U's value2 updated value: " << value2 << std::endl;
            return value2 * value1;
        }
        return 0.f;
    }
};

struct PrintUpdated
{
    static float printUpdate(U* that,float* updatedValue )        //10
    {   
        if(updatedValue != nullptr)
        {   
            U &thatt = *that;
            float &updatedValuee = *updatedValue;
            std::cout << "U's value1 value: " << thatt.value1 << std::endl;
            thatt.value1 = updatedValuee;
            std::cout << "U's value1 updated value: " << thatt.value1 << std::endl;
            while( std::abs(thatt.value2 - thatt.value1) > 0.001f )
            {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
                thatt.value2 += 0.5f;
            }
            std::cout << "U's value2 updated value: " << thatt.value2 << std::endl;
            return thatt.value2 * thatt.value1;
        }
        return 0.f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T c(1, "c");                                             //6
    T d(2, "d");                                             //6
    
    Compare f;                                         //7
    auto* smaller = f.compare(&c, &d);                              //8
    if(smaller != nullptr)
    {
        auto &smallerr = *smaller;
        std::cout << "the smaller one is " << smallerr.name << std::endl;
    }
    else if(c.value == d.value)
        std::cout << "same" <<std::endl;
    else
        std::cout << "nullptr" << std::endl;
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << PrintUpdated::printUpdate(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.uPrintUpdated( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
