/**
 * @file AbstractFactory.cpp
 * @author tamtm62 (tamtm62@wru.vn)
 * @brief Abstract Factory provides an interface for creating families of 
 *      related or dependent object without specifying their concrete classes
 * 
 *      [?] When to use:
 *      - a family of RELATED product object is design to be USED TOGETHER (like GUI component, ...)
 *      - a system should be configured with ONE of MULTIPLE FAMILIES of product
 *      - a system should be INDEPENDENT of how its product are created, composed and represented
 *      - you want to provie a class library of products, and you want to REVEAL just THEIR INTERFACE, 
 *      not their implementations  
 * 
 *      [?] Pros 
 *      - The product u getting from factory are compatible with each other
 *      - Avoid tight coupling between concrete products and client code
 *      - Making code easier to support
 *      - Add new variants of product without breaking existing client code
 * 
 *      [?] Cons  
 *      - Code may become more complicated than it should be, since a lot of 
 *      new interfacces and classes are introduce along the pattern 
 * 
 *      [?] Relations with other pattern
 *      - Many design start by using Factory Method (less complicated and more customizable via subclasses)
 *       and evolve toward Abstract Factory, Prototype or Builder (more flexible but more complicated)
 *      
 *      - Builder focuses on constructing complex object step by step. Abstract Factory specializes 
 *      in creating families of related object. Abstract Factory return return the product immediately, 
 *      where Builder lets you run some additional construction steps before fetching the product
 *      
 *      - Abstract Factory classes are often base on set of Factory Method, but u can also use Prototype 
 *      to compose the methods on these classes.
 *      
 *      - Abstract Factory can serve as alternative to Facade when u only want to hide the way the subsystem 
 *      objects are created from the client.
 * 
 *      - You can use Abstract Factory along with Bridge. This pairing is useful when some abstractions defined 
 *      by Bridge can only work with specific implementations. In this case, Abstract Factory can encapsulate 
 *      these relations and hide the complexity from the client code
 *      
 *      - Abstract Factory, Builder and Prototype can all be implemented as Singleton
 *  
 * @version 0.1
 * @date 2020-02-12
 * 
 */

#include <iostream>
#include <string>

using namespace std;

#define print(info) cout << info << endl; 

/**
 * @brief Abstract-class Button 
 *      and 2 implement of Mac and Win version  
 * 
 */
class Button
{
public:
    virtual ~Button() {};
    virtual void showName() = 0;
};

class MacButton : public Button
{
public:
    ~MacButton() {};
    void showName() { print("<> Initialize Mac button") };
};

class WinButton : public Button
{
public:
    ~WinButton() {};
    void showName() { print("<> Initialize Win button") };
};


/**
 * @brief Abstract-class Checkbox and 
 *      2 implement of Win and Mac version
 * 
 */
class Checkbox
{
public:
    virtual ~Checkbox() {};
    virtual void showName() = 0; 
};

class WinCheckbox : public Checkbox
{
public:
    ~WinCheckbox() {};
    void showName() { print("<> Initialize Win Checkbox") };
};

class MacCheckbox : public Checkbox
{
public:
    ~MacCheckbox() {};
    void showName() { print("<> Initialize Mac Checkbox") };
};


/**
 * @brief Abstract Factory
 * provides an abstract interface 
 * for creating 2 class: Mac and Win GUI
 * 
 */

class AbstractFactory
{
public:
    virtual ~AbstractFactory() {};

    virtual Button*     createButton() = 0;
    virtual Checkbox*   createCheckbox() = 0;
};

class WinGUI: AbstractFactory
{
public:
    ~WinGUI() {};
    
    Button* createButton()      { return new WinButton(); } 
    Checkbox* createCheckbox()  { return new WinCheckbox(); }
};

class MacGUI: AbstractFactory
{
public:
    ~MacGUI() {};
    
    Button* createButton()      { return new MacButton(); };
    Checkbox* createCheckbox()  { return new MacCheckbox(); };
};


int main() 
{
    WinGUI *w   = new WinGUI();
    MacGUI *m   = new MacGUI();

    // Win GUI
    Button      *Wb = w->createButton();
    Checkbox    *Wc = w->createCheckbox();
    Wb->showName();
    Wc->showName();

    // Mac GUI
    Button      *Mb = m->createButton(); 
    Checkbox    *Mc = m->createCheckbox();
    Mb->showName();
    Mc->showName();

    delete Wb,Mb;
    delete w ,m ;

    return 0;
}

