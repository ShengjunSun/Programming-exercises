#include <iostream>
#include <cmath>
#include <string>

using namespace std; 

int calculate(int amt_snappers) {
    int power = 0; 
    int answer = 0; 
    for (int i = 1; i <= amt_snappers; i++) {
        answer = answer + pow(2, power); 
        power++; 
    }
    return answer; 
}


int main()
{
    int amt; 
    cin >> amt; 

    for (int i = 1; i <= amt; i++) {
        int N; 
        int toggle; 
        cin >> N; 
        cin >> toggle; 

        int amt_toggles_needed = calculate(N); 

        // set bootable. 
        bool bootable = false; 
        int k = toggle / amt_toggles_needed; 
        if (k <= amt_toggles_needed) {
            int remainder = toggle % amt_toggles_needed; 
            if (k - remainder == 1) {
                bootable = true; 
            }
        }
        else {
            for (int j = k; j > amt_toggles_needed; j--) {
                int component = j * amt_toggles_needed; 
                int remainder = toggle - component; 
                if (j - remainder == 1) {
                    bootable = true; 
                    break; 
                }
            }
        }

        string result; 
        if (bootable) {
            result = "ON"; 
        }
        else {
            result = "OFF"; 
        }

        cout << "Case #" << to_string(i) << ": " << result << endl; 
    }

    return 0; 
}
