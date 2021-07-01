/*Integrantes:
    -Eleazar Vasquez
    -Manuel Jaramillo
    -Patricio Canales
*/
#include <bits/stdc++.h> 
using namespace std; 

int main() { 

    int n; 
    cin >> n; 

    vector<vector<int>> graph(n); 
    int e; cin >> e; 

    int q; cin >> q;

    for(int i = 0; i < e; ++i) { 
        int a,b; 
        cin >> a >> b; 
        graph[a].push_back(b); 
        graph[b].push_back(a); 
    }

    for(int j = 0; j< q; j++){
        int c,d;
        cin >> c >> d;

        int ningunaAmistad = 1;
        for(int i = 0; i<graph[c].size(); i++){
            if (graph[c][i] == d){
                cout << "0\n";
                ningunaAmistad = 0;
            }
            else{
                for(int j=0; j<graph[graph[c][i]].size(); j++){
                    if(graph[graph[c][i]][j] == d){
                        cout << "1\n";
                        ningunaAmistad = 0;
                    }
                }
            }
        }
        if (ningunaAmistad == 1){
            cout << "0\n";
        } 

        
    }
} 