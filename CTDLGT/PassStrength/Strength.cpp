#include <iostream>
#include <string>

using namespace std;

int main() {
    // the constant values in the problem
    const int BASE_SCORE = 40;
    const int BONUS_EXCESS = 3;
    const int BONUS_UPPER = 4;
    const int BONUS_NUMBER = 5;
    const int BONUS_SYMBOL = 5;

    // read the password
    string password;
    getline(cin, password);

    // calculate other variables in the formula

    int passwordLength = password.length(); // length of the password
    // password which has less than 8 characters is invalid
    if (passwordLength < 8) {
        cout << "KhongHopLe";
        return 0;
    }
    int numberExcess = passwordLength - 8; // difference between 'passwordLength' and 8
    int numberUpper = 0; // number of uppercase letters
    int numberNumber = 0; // number of digits
    int numberSymbol = 0; // number of special charaters
    int bonusFlatNumber = -35; // the password only contains digits
    int bonusFlatLower = -15; // the password only contains lowercase letters
    int bonusCombo = 0; // calculated based on the different types of character
    // now loop through each character the password
    for (char c: password) {
        switch (c) {
            // if the character is a special character
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '^':
            case '&':
            case '*':
            case '?':
            case '_':
            case '~':
                bonusFlatLower = bonusFlatNumber = 0;
                numberSymbol++;
                continue;
        }
        // if the character is a digit
        if (c >= '0' && c <= '9') {
            numberNumber++;
            bonusFlatLower = 0;
            continue;
        }
        // if the character is an uppercase letter
        if (c >= 'A' && c <= 'Z') {
            numberUpper++;
            bonusFlatLower = bonusFlatNumber = 0;
            continue;
        }
        // if the character is a lowercase letter
        if (c >= 'a' && c <= 'z') {
            bonusFlatNumber = 0;
            continue;
        }
        // the remaining case is that the character is invalid
        cout << "KhongHopLe";
        return 0;
    }
    // calculate 'bonusCombo'
    int differentSet = (numberUpper != 0) + (numberSymbol != 0) + (numberNumber != 0); // number of different sets
    if (differentSet == 3) {
        bonusCombo = 25;
    }
    if (differentSet == 2) {
        bonusCombo = 15;
    }
    
    // calculate score
    int score = BASE_SCORE + (numberExcess * BONUS_EXCESS) + (numberUpper * BONUS_UPPER) + (numberSymbol * BONUS_SYMBOL)
                + (numberNumber * BONUS_NUMBER) + bonusCombo + bonusFlatLower + bonusFlatNumber;

    // evaluate password strength
    if (score < 50) {
        cout << "Yeu";
    }
    else if (score < 75) {
        cout << "Vua";
    }
    else if (score < 100) {
        cout << "Manh";
    }
    else {
        cout << "RatManh";
    }

    return 0;
}