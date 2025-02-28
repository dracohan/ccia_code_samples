/*
 * Date: 
 * From: 
 * Category: 
 * Description: 
 *   check the main thread exist before hreading
 * Sample: 
 * Purpose: 
 * Test: 
 * Result: 
 * Comments: 
 */

#include <thread>
#include <iostream>
using namespace std;
void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
            std::cout << "i: " << i << std::endl;
        }
    }
};


void oops()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
}

int main()
{
    oops();
}
