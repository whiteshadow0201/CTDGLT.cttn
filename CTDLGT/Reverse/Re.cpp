#include <bits/stdc++.h>
using namespace std;

string decode(string ciphertext)
{
    int n = ciphertext.length();
    for (int d = 1; d <=n; d++)
    {
        if (n % d == 0)
        {
            reverse(ciphertext.begin(), ciphertext.begin() + d);
        }
    }
    return ciphertext;
}
int main()
{
    string ciphertext;
    cin>> ciphertext;
    string plaintext = decode(ciphertext);
    cout << plaintext ;
    return 0;
}
