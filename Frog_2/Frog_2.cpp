#include <bits/stdc++.h>
using namespace std;


using namespace std;

int main()
{
    int n_stones, n_steps;
    cin >> n_stones >> n_steps;

    vector <int> height(n_stones + 1, 0);
    for(int i = 1; i <= n_stones; i++)
        cin >> height[i];

    const int oo = 1e9;
    vector <int> minimum_cost(n_stones + 1, oo);
    minimum_cost[1] = 0;

    for(int i = 2; i <= n_stones; i++)
    {
        for(int j = i - 1; j >= max(1, i - n_steps); j--)
        {
            minimum_cost[i] = min(minimum_cost[i], minimum_cost[j] + abs(height[i] - height[j]));
        }
    }

    cout << minimum_cost[n_stones];
    return 0;
}