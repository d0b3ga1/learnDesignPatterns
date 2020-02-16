/**
 * @file Singleton.cpp
 * @author tamtm (tamtm62@wru.vn)
 * @brief Singleton is a creational design pattern that lets you ensure that a class 
 *      has only one instance, while providing a global access point to this instance
 * 
 *      [?] Pros:
 *      - U can be sure that a class has only a single instance
 *      - U gain a global access point to that instance
 *      - The singleton object is initialized only when its requested for the first time
 * 
 *      [?] Cons
 *      - The pattern solves 2 problem at the time, violates the Single Responsibility Principle.
 *      - The Singleton pattern can mask bad design, for instance when the components of 
 *      the program know too much about each other.
 *      - Require special treatment in a multithread environtment so that multiple threads 
 *      wont create a singleton object several times.
 *      - May difficult to write unit test. 
 * 
 * @version 0.1
 * @date 2020-02-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
using namespace std;

#define print(info) cout << info << endl;

class Singleton 
{
private:
    Singleton() {};
    static Singleton* thisInstance;
public:
    // the copy constructor and assignment operator
    // are defined as deleted, which means that u cant 
    // make a copy of singleton
    // 
    // Note: u can achieve the same effect by declaring
    // the constructor and the operator as private
    Singleton (Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    
    static Singleton* get()
    {
        if (!thisInstance) { thisInstance = new Singleton(); };
        return thisInstance;
    }

    static void restart()
    {
        if (thisInstance) { delete thisInstance; };
    }

    void tell() {
        print("<> This is Singleton")
    }
};


Singleton* Singleton::thisInstance = nullptr; 

int main()
{
    Singleton::get()->tell();
    Singleton::restart();

    return 0;
}