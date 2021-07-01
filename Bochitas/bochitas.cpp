/*Integrantes:
    -Eleazar Vasquez
    -Manuel Jaramillo
    -Patricio Canales
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    int caso = 1;

    while (n!=0 && q!=0){
        int bochitas[n] = {};
    
        for(int i=0; i<n; ++i){
            cin>>bochitas[i];
        }
        std::vector<int> vectorbochitas (bochitas, bochitas+n);
        std::sort (vectorbochitas.begin(), vectorbochitas.end());

        std::vector<int>::iterator low;

        cout << "CASE# " << caso << ":\n";
        for(int j=0; j<q; ++j){
            int x;
            cin>>x;

            //busqueda
            low=std::lower_bound (vectorbochitas.begin(), vectorbochitas.end(), x);
            if (*low == x) {
                cout << x << " found at " << low-vectorbochitas.begin()+1 << "\n";
            }
            else{
                cout << x << " not found\n";
            }
        }
        caso++;
        cin>>n>>q;
    } 
    return 0;
}