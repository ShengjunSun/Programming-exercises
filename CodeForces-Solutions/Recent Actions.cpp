
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int num_of_cases; 
    cin >> num_of_cases; 

    for (int i = 1; i <= num_of_cases; i++) {
        int n; 
        int m; 
        cin >> n; 
        cin >> m; 

        vector<int> original; 
        for (int i = 0; i < n; i++) {
            original.push_back(i); 
        }

        vector<int> moves; 
        for (int i = 0; i < m; i++) {
            int move; 
            cin >> move; 
            moves.push_back(move); 
        }

        vector<int> outputs; 
        for (int i = 1; i <= n; i++) {
            outputs.push_back(-1); 
        }

        vector<bool> duplicate_yn; 
        vector<int> container; 
        for (int i : moves) {
            if (find(container.begin(), container.end(), i) == container.end()) {
                container.push_back(i); 
                duplicate_yn.push_back(false); 
            }
            else {
                duplicate_yn.push_back(true);
            }
        }

        int time = 1; 
        int amt_neg_one = n; 

        for (bool b : duplicate_yn) {
            if (amt_neg_one == 0) {
                break; 
            }
            // if not a duplicate action: 
            if (!b) {
                outputs[original[n - 1]] = time;
                amt_neg_one--;
                n--;  
            }
            // if is duplicate; don't do a thing. 

            // no matter if it is a duplicate or not; time increase by one. 
            time++; 
        }

        for (int i : outputs) {
            cout << i << " "; 
        }

        cout << endl; 
    }

    return 0; 
}

