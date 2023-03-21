#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, // number of bulbs in the warehouse
        k; // number of bulbs needed

    // read n, k
    cin >> n >> k;

    long *bulbArr = new long[n]; // bulb array
    
    // read the array
    for (int i = 0; i < n; i++) {
        cin >> bulbArr[i];
    }

    // sort the array
    sort(bulbArr, bulbArr + n);

    // Pick 'bulbArr[0]'...
    cout << bulbArr[0] << ' ';
    int installed = 1; // 1 bulb installed
    if (k == 1) { // only need 1 bulb :>
        // free up memory...
        delete[] bulbArr;
        // ...and end the program
        return 0;
    }

    // ...then pick each other color 1 bulb...
    long prevColor = bulbArr[0]; // previous color
    for (int i = 1; i < n; i++) {
        if (bulbArr[i] == prevColor) {
            continue;
        }
        cout << bulbArr[i] << ' ';
        if ((++installed) == k) { // enough bulbs
            // free up memory and end the program as well
            delete[] bulbArr;
            return 0;
        }
        prevColor = bulbArr[i];
        bulbArr[i] = -1; // mark bulb i as chosen
    }

    // ...finally pick whatever color :D
    for (int i = 1; i < n; i++) {
        if (bulbArr[i] == -1) { // bulb has already been chosen
            continue;
        }
        cout << bulbArr[i] << ' ';
        if ((++installed) == k) { // enough bulbs
            delete[] bulbArr;
            return 0;
        }
    }
    
    delete[] bulbArr;
    return 0;
}