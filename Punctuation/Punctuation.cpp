#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    
    ll valida_espacios;
    string frase_final,frase;

    getline(cin,frase);

    valida_espacios=0;

    for(ll i=0;i<frase.length();i++)
    {
        if(isalpha(frase[i]))
        {
            frase_final.push_back(frase[i]);
            valida_espacios=0;
        }

        else if(frase[i]==' ' && valida_espacios==0)
        {
            frase_final.push_back(' ');
            valida_espacios=1;
        }

        else if(frase[i]=='.' || frase[i]==':' || frase[i]=='"' || frase[i]=='!' || frase[i]==',' || frase[i]=='?' || frase[i]==';')
        {
            if(valida_espacios==1)
                frase_final.pop_back();

            frase_final.push_back(frase[i]);
            frase_final.push_back(' ');
            valida_espacios=1;
        }
    }

    cout<<frase_final<<"\n";

    cin.clear();
    cin.ignore();
    //cin.get();

    return 0;
}