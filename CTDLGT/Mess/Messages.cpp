#include <iostream>
#include <string>

using namespace std;

// to check if a part of string 'str1'...
// ...from 'begin' to 'end'...
// ...is the beginning of string 'str2'
// 'str2Length' is the length of 'str2'
bool isDuplicate(string str1, string str2, int begin, int end, int str2Length) {
    // if the part of str1 is longer than str2...
    // ...of course that part is not the beginning of str2
    if (end - begin + 1 > str2Length) {
        return false;
    }
    // now check each pair of character respectively
    for (int i = begin, j = 0; i < end + 1; i++, j++) {
        // if there is any difference...
        if (str1[i] != str2[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string firstLetter, secondLetter; // the two letter sent

    // read cipherText
    getline(cin, firstLetter);
    getline(cin, secondLetter);

    int firstLetterLength = firstLetter.length(); // length of the first letter
    int secondLetterLength = secondLetter.length(); // length of the second letter

    // find the "longest" last part of str1 that is the beginning of str2
    int duplicateFound = firstLetterLength; // the first letter of the duplicated part, inittially no duplicate
    for (int i = 0; i < firstLetterLength; i++) {
        if (isDuplicate(firstLetter, secondLetter, i, firstLetterLength - 1, secondLetterLength)) {
            duplicateFound = i;
            break;
        }
    }

    // write the result
    // firstly the length of the document after removing duplicated part
    cout << duplicateFound + secondLetterLength << '\n';
    // then the remaining part of letter 1
    for (int i = 0; i < duplicateFound; i++) {
        cout << firstLetter[i];
    }
    // finally letter 2
    cout << secondLetter;

    return 0;
}