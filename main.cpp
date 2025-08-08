#include <iostream>
#include <string>
#include<vector>
#include"die.h"

using namespace std;
/*
1.	emailValidator()
Create a program that prompts the user to enter an email address.  The address should be collected as a string.  Use exception handling in an email validator function that checks against the following rules:
1.	Email string should include only one @ sign.
2.	Email string should not begin with @ sign.
3.	Email string should include at least one ‘.’ after the @ sign.
The validator should throw an exception appropriate to the error that occurred.  The main program (or collectEmail function, your preference) should then display an appropriate error message to the user and prompt the user for a new string.
Once the user enters an appropriate Email string, the function/program should print out a message “email address accepted.”
*/


void validateEmail(const string& email) {
    int atCount = 0, atPos = -1;
    for (int i = 0; i < (int)email.size(); ++i) {
        if (email[i] == '@') {
            if (atCount == 0) atPos = i;
            ++atCount;
        }
    }

    if (atCount != 1) throw "Email must contain exactly one '@' sign.";
    if (atPos == 0) throw "Email cannot start with '@'.";

    bool dotAfterAt = false;
    for (int i = atPos + 1; i < (int)email.size(); ++i) {
        if (email[i] == '.') { dotAfterAt = true; break; }
    }
    if (!dotAfterAt) throw "Email must contain a '.' after the '@' sign.";
}

vector<int> findDuplicateBirthday(Die& die, vector<int> rolls) {
    die.roll();
    int result = die.getfaceValue();
    for (int r : rolls) {
        if (r == result) {
            rolls.push_back(result);
            return rolls;
        }
    }
    rolls.push_back(result);
    return findDuplicateBirthday(die, rolls);
}
int main() {

    string email;

    while (true) {
        cout << "Enter your email address: ";
        getline(cin, email);

        try {
            validateEmail(email);
            cout << "Email address accepted.\n";
            break;
        }
        catch (const char* msg) {
            cout << "Error: " << msg << "\nPlease try again.\n";
        }
    }


    int num = 42;
    double pi = 3.14159;
    string text = "Dang imma lowkey miss this class";
    Die myDie(6);

    consoleLog(num);
    consoleLog(pi);
    consoleLog(text);
    consoleLog(myDie);


    Die birthdayDie(365);

    vector<int> rolls;
    rolls = findDuplicateBirthday(birthdayDie, rolls);

    cout << "Lets see who has a twin!:\n";
    for (int r : rolls) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}


