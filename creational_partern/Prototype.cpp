/**
 * @file Prototype.cpp
 * @author tamtm (tamtm62@wru.vn)
 * @brief Prototype is a creational design pattern that lets u copy existing objects 
 *      without making your code dependent on their classes 
 *      
 *      [?] Pros
 *      - U can clone objects without coupling to their concrete classes
 *      - U can get rid of repeated initialization code in favor of cloning pre-built prototypes
 *      - U can produce complex objects more conviniently.
 *      - U can get an alternative to inheritance when dealing with configuration presets for complex objects
 * 
 *      [?] Cons
 *      - Cloning complex objects that have circular refernces might be very tricky
 * 
 *      [?] Relations with Other Pattern
 *      - Prototype can help when you need to save copyies of Commands (a pattern) into history
 *      - Prototype isnt base on inheritance, so it doesnt have its drawbacks. On the other hand, 
 *      Prototype requires a complicated initialization of cloned object. Factory method is based 
 *      on inheritance but doesnt require an initialization step.
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
 * @brief Abstract-class Shape
 *      declares an interface for cloning itself
 * 
 */
class Shape
{
private:
    double x,y;
    string color;
public:
    virtual ~Shape() {}
    
    virtual Shape* clone() = 0;
    virtual void show() = 0;
};

/**
 * @brief Concrete class Rectangle & Circle 
 *      implement an operation for cloning itself
 * 
 */
class Rectangle : public Shape
{
private:
    double width, height;
public:
    Rectangle() {
        this->width =0;
        this->height=0;
    }
    Rectangle(double width, double height) {
        this->width =width;
        this->height=height;
    }
    Rectangle(Rectangle *thisRectangle) {
        this->width =thisRectangle->width;
        this->height=thisRectangle->height;
    }
    ~Rectangle() {}

    Shape* clone() { return new Rectangle(*this); }
    void show() { print("<> This is a Rectangle: " << width << "#" << height) }
};


class Circle : public Shape
{
private:
    double radius;
public:
    Circle() {
        this->radius = 0;
    }
    Circle(double radius) {
        this->radius = radius;
    }
    Circle(Circle *thisCircle) {
        this->radius = thisCircle->radius;
    }
    ~Circle() {}

    Shape* clone() { return new Circle(*this); }
    void show() { print("<> This is a Circle: " << radius) }
};


int main()
{
    // initialize some sample objects
    Shape *rec = new Rectangle(3, 4);
    Shape *cir = new Circle   (5);

    // show info
    rec->show(); cir->show();

    // perform copy
    Shape *recC = rec->clone();
    Shape *cirC = cir->clone();
    recC->show();
    cirC->show();

    // its copy so their address is different
    print(&rec)
    print(&recC)

    return 0;
}
