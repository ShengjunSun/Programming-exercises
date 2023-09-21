#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int find_gcd(int x, int y) {
    if (x < y) {
        // swap
        int tmp = x;
        x = y;
        y = tmp;
    }
    // after the 'if' loop above; x must be greater than or equal to y. 
    int remainder = x % y;
    if (remainder != 0) {
        return find_gcd(remainder, y);
    }
    else {
        return y;
    }
}

int main()
{
    int N; 
    cin >> N;

    for (int i = 0; i < N; i++) {
        int amt; 
        cin >> amt; 
        vector<int> numbers; 
        for (int i = 0; i < amt; i++) {
            int token; 
            cin >> token; 
            numbers.push_back(token); 
        }

        sort(numbers.begin(), numbers.end()); 

        // start to perform the calculation. 

        int gcd = find_gcd(numbers[0], numbers[1]); 

        for (int i = 2; i < numbers.size(); i++) {
            gcd = find_gcd(gcd, numbers[i]);
        }

        cout << numbers[numbers.size() - 1] / gcd << endl; 
    }
    
    return 0; 
}

