#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    string s;
    cin.ignore();
    getline(cin, s);
    int n=s.length();
    for (int i=0;i<n;i++){
        if (s[i]==' ') {
            cout<< ' ';
            continue;
        }
        int t= (k+(int(s[i])-(int)'A'))%26;
        cout<< (char) (t+65);
    }
return 0;
}