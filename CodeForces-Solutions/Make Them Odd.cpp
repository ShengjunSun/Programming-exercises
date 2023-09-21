
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std; 

int main()
{
    // 'amt' is well collected. 
    int amt; 
    cin >> amt; 
    
    for (int i = 0; i < amt; i++) {

        int N; 
        cin >> N; 
        
        string line; 
        // perform ignore before calling getline; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, line); 
        stringstream ss; 
        ss.str(line); 
        ss.clear(); 

        vector<int> numbers;
        for (int i = 0; i < N; i++) {
            int number;
            ss >> number;
            numbers.push_back(number);
        }
       
        set<int> already_seem; 
        
        for (int number : numbers) {
            // if the number is even: 
            while (number % 2 == 0) {
                already_seem.insert(number); 
                number = number / 2;
            }
        }

        // display the amount of distinct even number we have to face at the process of turning the 
        // entire list into odd only. 
        // if we take clever approach, each distinct number only need to be divided once. 
        cout << already_seem.size() << endl;
    }
}
