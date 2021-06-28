#include <bits/stdc++.h>
using namespace std;


int height_stones[100009];
int minimos[100009];
int n_stones;
 
int solve(int idx) {
 
	if(idx == n_stones - 1)
		return 0;
 
	if(minimos[idx] != -1)
		return minimos[idx];
 
	int ans = solve(idx + 1) + abs(height_stones[idx + 1] - height_stones[idx]);
	if(idx + 2 < n_stones)
		ans = min(ans, solve(idx + 2) + abs(height_stones[idx + 2] - height_stones[idx]));
 
 
	return minimos[idx] = ans;
}
 
 
int main() {
 
	memset(minimos, -1, sizeof(minimos));
	cin>>n_stones;
 
	for(int i = 0; i < n_stones; i++) {
		cin >> height_stones[i];
	}
 
	cout<<solve(0)<<endl;
 
	return 0;
}