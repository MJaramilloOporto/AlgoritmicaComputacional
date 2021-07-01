/*Integrantes:
    -Eleazar Vasquez
    -Manuel Jaramillo
    -Patricio Canales
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n_stones;
  cin >> n_stones;
  vector <int> height_stones(n_stones+1);

  for (int i = 1; i<=n_stones;++i){
    cin >> height_stones[i];

  }
  
  vector <int> minimos(n_stones+1);
  minimos[2] = abs(height_stones[2]-height_stones[1]);
  for (int i = 3; i<=height_stones.size();++i){
    
    minimos[i] = min (minimos[i-1] + abs(height_stones[i-1]-height_stones[i]),             minimos[i-2] + abs(height_stones[i-2]-height_stones[i]));
  }

  cout << minimos[n_stones] << "\n";


  return 0;
}