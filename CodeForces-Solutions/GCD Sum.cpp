
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int find_gcd(long long x, long long y) {
    if (x < y) {
        // swap
        long long tmp = x; 
        x = y; 
        y = tmp; 
    }
    int remainder = x % y; 
    if (remainder != 0) {
        return find_gcd(remainder, y); 
    }
    else {
        return y; 
    }
}

int digit_sum(long long param) {
    string as_str = to_string(param);
    int sum = 0;
    for (char c : as_str) {
        int k = c - '0'; 
        sum = sum + k;
    }
    return sum; 
}

int main() {
    int N; 
    cin >> N; 
    for (int i = 0; i < N; i++) {
        long long k; 
        cin >> k; 
        
        int sum = digit_sum(k); 

        int gcd = find_gcd(k, sum); 

        while (gcd <= 1) {
            k++; 
            gcd = find_gcd(k, digit_sum(k)); 
        }

        cout << k << endl; 
    }

    return 0; 
}

