/**
 * @file FactoryMethod.cpp
 * @author tamtm (tamtm62@wru.vn)
 * @brief Factory Method is a creatinal design partern that provides an interfaces for creating object 
 *      in a super class, but allow subclasses to alter the type of objects that will be created.
 * 
 *      [?] Pros:
 *      - Avoid tight coupling between the creator and the concrete products
 *      - Product creation code can be moved in one place, making code easier to support 
 *      - U can add new product into the program without breaking existing client code
 *      
 *      [?] Cons:
 *      - Code may become more complicated since you need to add new subclasses to implement the pattern 
 * 
 *      [?] What is the different between Abstract Factory
 *      - Abctract Factory deals with a family of products ,
 *      the Factory Method is only worried about a single product   
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
 * @brief Abstract-class Button provides same interface
 *      so that the classes can refer to the interface, not the concrete define.
 *      And below is 2 implement of Button type
 */

class Button
{
public:
    virtual ~Button() {};
    virtual void showName() = 0;   
};

class WinButton : public Button
{
    ~WinButton() {};
    void showName() { print("<> This is Win Button") };
};

class MacButton : public Button
{
    ~MacButton() {};
    void showName() { print("<> This is Mac Button") };
};


/**
 * @brief 
 * 
 */
class Dialog
{
public:
    virtual ~Dialog() {};
    virtual Button* createButton() = 0;

    virtual void removeButton(Button *button) = 0;
};

class WinDialog : public Dialog
{
    ~WinDialog() {};
    Button* createButton() { return new WinButton(); }
    void removeButton(Button *button) {
        delete button;
    }
};

class MacDialog : public Dialog
{
    ~MacDialog() {};
    Button* createButton() { return new MacButton(); }
    void removeButton(Button *button) {
        delete button;
    }
};

int main()
{
    // initialize creator
    Dialog *winD = new WinDialog();
    Dialog *macD = new MacDialog();

    // create object
    Button *winB = winD->createButton();
    Button *macB = macD->createButton();   

    winB->showName();
    macB->showName();

    // remove object
    winD->removeButton(winB);
    macD->removeButton(macB);

    return 0;
}