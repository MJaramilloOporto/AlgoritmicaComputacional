#include<bits/stdc++.h>
using namespace std;
int main(){
    int casos,n;
    cin>>casos;

    while(casos--){
        string s;
        cin>>n>>s;
        
        for(int i=0; i<2*n-1; i+=2){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}