/**
 * @file Builder.cpp
 * @author tamtm (tamtm62@wru.com)
 * @brief Builder is a creational design pattern that lets u construct complex 
 *      objects step by step. The pattern allows u to pruduce diffirent types and 
 *      representations of an object using the same construction code
 * 
 *      [?] Pros
 *      - Construct objects step-by-steps, defer construction steps or run step recursively.
 *      - U can reuse the same construction code when building various representations of product
 *      - U can isolate complex contruction code from the business logic of the product
 *      
 *      [?] Cons
 *      - The overall complexity of the code increases since the pattern requires creating multiple new classes 
 * 
 *      [?] Main intent
 *      - This pattern's main intent is to have the minimum number of overloading constructors to support 
 *      the construction of several representations of an object
 * 
 * 
 * @version 0.1
 * @date 2020-02-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>

using namespace std;

#define print(info) cout << info << endl;

/**
 * @brief Class Car
 *      define the intent of building a Car step-by-step
 * 
 */
class Car
{
private:
    string seatStatus;
    string engineStatus;
    string computer;
public:
    void      makeSeat(const string& seat)
    { this->seatStatus = seat; }
    void    makeEngine(const string& engineStatus)
    { this->engineStatus = engineStatus; }
    void  makeComputer(const string& computer)
    { this->computer = computer; }

    void show() {
        print(seatStatus + " --> " + engineStatus + " --> " + computer)
    }
};

/**
 * @brief Abstract class Carbuilder
 *      is the gate to create some representations of Car you want
 * 
 */
class CarBuilder
{
protected:
    Car car;
public:
    virtual ~CarBuilder() {}

    Car get() { return this->car; }

    virtual void buildSeat() = 0;
    virtual void buildEngine() = 0;
    virtual void buildComputer() = 0;
};


class SedanBuilder : public CarBuilder
{
public:
    ~SedanBuilder() {}

    void buildSeat() {
        car.makeSeat("<> Initialize Sedan Seat");
    }
    void buildEngine() {
        car.makeEngine("<> Initialize Sedan Engine");
    }
    void buildComputer() {
        car.makeComputer("<> Initialize Sedan Computer");
    }
};

class SuvBuilder : public CarBuilder
{
    ~SuvBuilder() {}

    void buildSeat() {
        car.makeSeat("<> Initialize Suv Seat");
    }
    void buildEngine() {
        car.makeEngine("<> Initialize Suv Engine");
    }
    void buildComputer() {
        car.makeComputer("<> Initialize Suv Computer");
    }
};


/**
 * @brief Class CarDirector
 *      is where we hide the construction. client code only care about the type of Car
 *      they want and tell the director to manage the process of creating that car. 
 * 
 */
class CarDirector 
{
private:
    CarBuilder *builder;
public:
    CarDirector() : builder() {}

    ~CarDirector() 
    {
        if (this->builder) { delete this->builder; }
    }
    
    void set(CarBuilder *builder)
    {
        if (this->builder) { delete this->builder; }
        this->builder = builder;
    }

    Car get() {
        return builder->get();
    }

    void construct()
    {
        builder->buildSeat();
        builder->buildEngine();
        builder->buildComputer();
    }

};

int main()
{
    CarDirector director;
    director.set(new SedanBuilder());
    director.construct();

    Car s1 = director.get();
    s1.show();

    director.set(new SuvBuilder());
    director.construct();
    
    Car s2 = director.get();
    s2.show();

    return 0;
}