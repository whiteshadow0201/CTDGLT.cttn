#include<bits/stdc++.h>
using namespace std;
bool comp(const int a, const int b)
{
    return a > b;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max=-999;
    int i=0;
    int j=n-1;
    sort(a,a+n,comp);
   while(i!=j){
        if(a[i]+a[j]>max&&a[i]+a[j]<=k){
            max=a[i]+a[j];
        } else if(a[i]+a[j]<=max){
            j--;
        } else if(a[i]+a[j]>k){
            i++;
        }
   }
   cout<<max;
}