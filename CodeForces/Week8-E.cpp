#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int num_of_cases;
    cin >> num_of_cases;

    for (int i = 0; i < num_of_cases; i++) {
        int n; 
        int coins; 
        cin >> n; 
        cin >> coins; 

        vector<int> costs; 

        for (int i = 1; i <= n; i++) {
            int cost; 
            cin >> cost; 
            costs.push_back(cost); 
        }

        int steps = 1; 

        vector<int> needed_coins; 

        for (int i : costs) {
            int needed_coin = i + steps; 
            needed_coins.push_back(needed_coin); 
            steps++; 
        }

        sort(needed_coins.begin(), needed_coins.end()); 

        int accumulator = 0; 
        int amounts = 0; 

        for (int i : needed_coins) {
            accumulator += i; 
            if (accumulator <= coins) {
                amounts++; 
            }
            else {
                break; 
            }
        }

        cout << amounts << endl; 
    }

    return 0; 
}

