
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main()
{
    int amt; 
    cin >> amt; 

    for (int i = 0; i < amt; i++) {
        int N; 
        cin >> N; 
        string number; 
        cin >> number; 

        vector<int> digits; 

        // the loop is working as intended. 
        for (char c : number) {
            int digit = c - '0'; 
            digits.push_back(digit); 
        }

        int left = 0; 
        int right = digits.size() - 1; 

        while (true) {
            if (left >= right) {
                break; 
            }
            int start = digits[left]; 
            int end = digits[right]; 
            if (start != end) {
                left++; 
                right--; 
            }
            else {
                break; 
            }
        }

        int length; 
        if (left > right) {
            length = 0; 
        }
        else {
            length = right - left + 1; 
        }

        cout << length << endl;
    }
    return 0; 
}
