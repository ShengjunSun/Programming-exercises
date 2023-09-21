
#include <iostream>
#include <vector>

using namespace std; 

typedef long long ll; 

int main()
{
    int num_cases;
    cin >> num_cases;

    for (int i = 0; i < num_cases; i++) {
        int amt_of_stacks; 
        cin >> amt_of_stacks; 

        vector<ll> blocks; 
        for (int i = 0; i < amt_of_stacks; i++) {
            ll entry; 
            cin >> entry; 
            blocks.push_back(entry); 
        }

        int counter = 0; 
        bool passing = true; 
        for (int i = 0; i <= amt_of_stacks - 2; i++) {
            if (blocks[i] > counter) {
                ll difference = blocks[i] - counter; 
                blocks[i] = counter; 
                blocks[i + 1] += difference; 
            }
            if (blocks[i + 1] <= blocks[i]) {
                passing = false; 
                break; 
            }
            counter++; 
        }
        if (passing) {
            cout << "YES" << endl; 
        }
        else {
            cout << "NO" << endl; 
        }
    }
    return 0; 
}
