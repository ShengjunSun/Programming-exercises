
#include <iostream>

using namespace std; 

int main()
{
    int num_cases; 
    cin >> num_cases; 

    for (int i = 0; i < num_cases; i++) {
        int length; 
        cin >> length; 
        string word; 
        cin >> word; 

        int index = 0; 
        bool eventh = false; 
        bool passing = true; 

        while (index <= length - 1) {
            if (eventh) {
                if (index == length - 1) {
                    passing = false; 
                    break; 
                }
                string current = word.substr(index, 1); 
                string next = word.substr(index + 1, 1); 
                if (current != next) {
                    passing = false; 
                    break; 
                }
                index++; 
                eventh = false; 
            }
            else {
                eventh = true; 
            }
            index++; 
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