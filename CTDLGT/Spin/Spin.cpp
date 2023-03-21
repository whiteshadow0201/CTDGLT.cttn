#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pos first
#define MSSV second
bool cmp(pii a, pii b){
    return a.pos<b.pos;
}



int main() {
    int n, k;
    cin >> n >> k;
    pii hs[n];
    for (int i=0;i<n;i++){
        cin >> hs[i].MSSV;
        hs[i].pos=(i+k)%n;
    }
    sort(hs,hs+n,cmp);
    for (int i=0;i<n;i++)
        cout << hs[i].MSSV << ' ';
return 0;

}