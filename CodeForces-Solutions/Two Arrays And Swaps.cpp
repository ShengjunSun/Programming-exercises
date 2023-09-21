
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    int num_cases; 
    cin >> num_cases; 
    
    for (int i = 0; i < num_cases; i++) {
        int length;
        int amt_swaps;
        cin >> length;
        cin >> amt_swaps;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < length; i++) {
            int entry;
            cin >> entry;
            a.push_back(entry);
        }
        for (int i = 0; i < length; i++) {
            int entry; 
            cin >> entry; 
            b.push_back(entry); 
        }
        // sort a from small to big
        sort(a.begin(), a.end()); 
        // sort b from big to small
        sort(b.begin(), b.end(), greater<int>()); 
        
        int index = 0; 
        for (int i = 1; i <= amt_swaps; i++) {
            if (b[index] > a[index]) {
                // if that specific element from b is greater than the corresponding element from a; 
                // perform the swap; set that element in a into the element from b. 
                a[index] = b[index]; 
            }
            // if not; remain that element from a; do no change. 
            // meanwhile; index++; since at the next chance of swap; we want to look at the next element. 
            // rather than the current one we've already spent a swap (if applies) on. 
            index++; 
        }
        int answer = 0; 
        for (int i : a) {
            answer += i; 
        }
        cout << answer << endl; 
    }
    return 0; 
}

