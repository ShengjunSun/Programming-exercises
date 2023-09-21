
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

// i : the current index; 
// correct: the target number to find; 
// numbers: the vector of numbers to seek from. 
int find_nearest_corr_idx(int i, int correct, vector<int>& numbers) {
    // cout << "function called" << endl; 
    for (int k = i + 1; k < numbers.size(); k++) {
        if (numbers[k] == correct) {
            return k; 
        }
    }
}

int main()
{
    int amt; 
    cin >> amt; 

    for (int i = 0; i < amt; i++) {
        int amt_n; 
        int amt_p; 
        vector<int> numbers; 
        vector<int> positions; 

        cin >> amt_n; 
        cin >> amt_p; 

        for (int i = 0; i < amt_n; i++) {
            int number; 
            cin >> number; 
            numbers.push_back(number); 
        }
        
        for (int i = 0; i < amt_p; i++) {
            int position; 
            cin >> position; 
            positions.push_back(position); 
        }

        vector<int> numbers_sorted; 
        for (int i : numbers) {
            numbers_sorted.push_back(i); 
        }

        sort(numbers_sorted.begin(), numbers_sorted.end()); 

        bool sortable = true; 

        for (int i = 0; i < numbers.size(); i++) {
            int current = numbers[i]; 
            int correct = numbers_sorted[i]; 

            if (current == correct) {
                // cout << "continue loop; " << endl; 
                continue; 
            }
            else {
                // cout << "else loop; " << endl; 
                int nearest_corr_idx = find_nearest_corr_idx(i, correct, numbers); 
                // cout << "nearest corr idx: " << nearest_corr_idx << endl;
                bool adjustable = true;
                for (int k = i; k < nearest_corr_idx; k++) {
                    if (find(positions.begin(), positions.end(), k + 1) == positions.end()) {
                        adjustable = false; 
                        break; 
                    }
                }
                if (!adjustable) {
                    sortable = false; 
                    break; 
                }
                else {
                    int tmp = numbers[i]; 
                    numbers[i] = numbers[nearest_corr_idx]; 
                    numbers[nearest_corr_idx] = tmp; 
                }
            }
        }

        if (sortable) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
      
    }
}
