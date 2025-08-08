#include "die.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Die::Die() : numOfSides(6), faceValue(1) {
    srand(static_cast<unsigned>(time(nullptr)));
    roll();
}

Die::Die(int numSides) : numOfSides(numSides), faceValue(1) {
    srand(static_cast<unsigned>(time(nullptr)));
    roll();
}

void Die::setfaceValue(int v) {
    faceValue = v;
}

int Die::getfaceValue() const {
    return faceValue;
}

int Die::getSides() const {
    return numOfSides;
}

void Die::roll() {
    faceValue = (rand() % numOfSides) + 1;
}

string Die::describeDie() const {
    return "A " + to_string(numOfSides) + "-sided die showing " + to_string(faceValue);
}

ostream& operator<<(ostream& os, const Die& die) {
    os << die.describeDie();
    return os;
}
