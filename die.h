#ifndef DIE_H
#define DIE_H
#include <string>
#include <iostream> 
using namespace std;

template <typename T>
void consoleLog(T message) {
    cout << message << endl;
}

class Die {
private:
    int numOfSides;
    int faceValue;
public:
    Die();
    Die(int numSides);
    void setfaceValue(int v);
    int getfaceValue() const;
    int getSides() const;
    void roll();
    string describeDie() const;

    friend ostream& operator<<(ostream& os, const Die& die);
};

#endif
