
#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    int amt; 
    cin >> amt; 

    for (int i = 0; i < amt; i++) {
        int N; 
        cin >> N; 

        vector<int> numbers; 
        for (int i = 0; i < N; i++) {
            int number; 
            cin >> number; 
            numbers.push_back(number); 
        }

        bool emptiable = true; 

        int start_idx = 2; 

        int counter = 1; 

        for (int i : numbers) {
            bool not_all_factors = false; 
            for (int k = (counter + 1); k >= start_idx; k--) {
                if (i % k != 0) {
                    not_all_factors = true; 
                    break; 
                }
            }
            counter++; 
            if (!not_all_factors) {
                emptiable = false; 
                break;
            }
        }

        if (emptiable) {
            cout << "YES" << endl; 
        }
        else {
            cout << "NO" << endl; 
        }
    }
}
