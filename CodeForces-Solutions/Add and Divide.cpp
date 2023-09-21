#include <iostream>
#include <cmath>

using namespace std; 

int main()
{
    int t; 
    cin >> t; 

    while (t--) {
        int a;
        int b;
        cin >> a;
        cin >> b;

        // start with the case that b has no increment at all; 
        // to the case in which b is incremented at least to a_sqrt. 
        // < here; instead of <=; since b is at least 1. 

        int curr_min = 1e9;

        for (int i = 0; i * i <= a; i++) {
            int mul_amt = 0;
            int new_b = b + i;
            // forever not look at the case in which b = 1; since a >= 1 as well. 
            if (new_b == 1) { continue; }
            int c = a;
            while (c) {
                c = c / new_b; 
                mul_amt++;
            }
            curr_min = min(curr_min, (i + mul_amt));
        }

        cout << curr_min << endl;
    }
    
    return 0; 
}

