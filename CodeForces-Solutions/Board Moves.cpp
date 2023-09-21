
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull; 

int main()
{
    int amt_of_cases;
    cin >> amt_of_cases;

    while (amt_of_cases--) {
        int input;
        cin >> input;

        if (input == 1) {
            cout << 0 << endl;
            continue;
        }

        unsigned long long answer = 0;
        int distance = 1;
        for (int i = 3; i <= input; i += 2) {

            unsigned long long increment = (4 * i * (ull) distance - 4 * (ull) distance);
            answer += increment;
            distance++;
        }

        cout << answer << endl;
    }
}
