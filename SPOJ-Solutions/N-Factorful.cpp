#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std; 

// this method works good. 
bool is_prime(int num) {
    // 0 and 1 is not prime. 
    if (num == 0 || num == 1) {
        return false; 
    }
    bool is_prime = true; 
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            is_prime = false; 
            break; 
        }
    }
    return is_prime; 
}

int main() {
    int amt; 
    cin >> amt; 

    for (int i = 0; i < amt; i++) {
        int a; 
        int b; 
        int n; 
        cin >> a; 
        cin >> b; 
        cin >> n; 

        set<int> up_to_b; 
        for (int i = 1; i <= b; i++) {
            up_to_b.insert(i); 
        }

        vector<int> counters; 
        for (int i = a; i <= b; i++) {
            counters.push_back(0); 
        }

        for (int i = 2; i <= sqrt(b); i++) {
            if (is_prime(i)) {
                for (int x = 1; x <= b / i; x++) {
                    up_to_b.erase(x * i); 
                    if (x * i >= a) {
                        counters[x * i - a]++; 
                    }
                }
            }
        }

        for (int i : up_to_b) {
            if (i > sqrt(b)) {
                for (int m = 1; m <= b / i; m++) {
                    if (m * i >= a) {
                        counters[m * i - a]++; 
                    }
                }
            }
        }

        int amt = 0; 
        for (int i : counters) {
            if (i == n) {
                amt++; 
            }
        }
        cout << amt << endl; 
    }
}

