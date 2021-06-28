#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  while(cin >> n){
    
    if (n>3000 && n<=0){
      return 0;
    }
    vector <int> vector(n);
    bool jump = true;

    for(int i=0; i<n;i++){
        cin >> vector[i];
    }

    for(int i=0; i<n-1; i++){
      if ((abs(vector[i] - vector[i+1]) >= n) || (abs(vector[i] - vector[i+1]) < 1)) {
        jump = false;
      }
    }
    if (jump == false){
      cout << "Not jolly" << "\n";
    }else{
      cout << "Jolly " << "\n";
    }
  }
  return 0;
}