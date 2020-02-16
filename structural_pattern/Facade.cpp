#include <iostream>
#include <string>

using namespace std;

#define print(info) cout << info << endl;

class Alarm
{
public:
    void  alarmOn() { print("[Alarm On] and house is secured") };
    void alarmOff() { print("[Alarm Off] and house is not secured") };
};

class AC
{
public:
    void  acOn() { print("[AC is On]") };
    void acOff() { print("[AC is Off]") };
};

class TV
{
public:
    void  tvOn() { print("[TV is On]") };
    void tvOff() { print("[TV is Off]") };
};

class HouseFacade
{
private:
    Alarm alarm;
    AC    ac;
    TV    tv;
public:
    HouseFacade() {}
    void goToWork() {
        ac.acOn();
        alarm.alarmOn();
        tv.tvOff();
    }

    void comeHome() {
        alarm.alarmOff();
        ac.acOn();
        tv.tvOn();
    }
};

int main()
{
    HouseFacade hf;

    hf.goToWork();
    print("");
    hf.comeHome();
}
