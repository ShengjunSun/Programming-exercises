#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

vector<int> to_binary(int param) {
    vector<int> binary_digits; 
    int remainder; 
    while (param != 0) {
        remainder = param % 2; 
        param = param / 2; 
        binary_digits.push_back(remainder); 
    }
    reverse(binary_digits.begin(), binary_digits.end()); 
    return binary_digits; 
}

// find out how many binary digits are required to represent that decimal. 
int bit_length(int param) {
    vector<int> binary_digits; 
    int remainder; 
    while (param != 0) {
        remainder = param % 2; 
        param = param / 2; 
        binary_digits.push_back(remainder); 
    }
    reverse(binary_digits.begin(), binary_digits.end()); 
    return binary_digits.size(); 
}


int main() {
    int amt; 
    cin >> amt; 
    
    for (int i = 0; i < amt; i++) {
        int N; 
        cin >> N; 

        /*
        * As is inspired by my mate; if N's binary string consist of all ones; 
        * N+1's binary string will have one more digit than N's binary string. 
        * In which only the first digit is a one; all others are zero. 
        * As a result, bitwise AND between N's binary string and N+1's binary string 
        * will be producing all zeros; which evaluate to zero upon conversion into decimal. 
        */

        if ((N + 1) & N) {
            // meaning that N is not consist of all ones. 

            /*
            * If that is the case, note further that: N is having a leading one; and zero(s) following that 
            * leading one. 
            * If we have another binary string reversing the digits of N's binary string,
            * The decimal value of that binary string will be smaller than N. 
            * the bitwise AND will produce all zeros. 
            * the bitwise XOR will produce all ones. Which in decimal represent a number larger than N. 
            * The GCD of the above two numbers is just the larger one. 
            */
            cout << (int)(pow(2, bit_length(N)) - 1) << endl;
        }
        else {
            // meaning that N is consist of all ones. As is inspired by my mates: 

            // we need to decide whether or not N is a prime. 

            /*
            * If it is the case that N is a prime, then just output 1. 
            * Because no matter how we segment N into two pieces, the gcd of those two pieces 
            * will always be one. (note that we can't segment N into 0 and N)  
            */

            /*
            * If it is the case that N is not a prime; find the largest portion of N such that, 
            * N - portion is some multiple of portion. In this case, the gcd will just be portion. 
            * Which means that we want to maximize portion such that portion is a factor of N - portion. 
            */

            // just skip x = 1; since if we select x = 1 as the portion, gcd will be one. 

            int x = 2; 
            // this while loop is for the purpose of finding the smallest divisor, which will lead to the 
            // largest portion. To be specific, N / smallest divisor = largest portion. 
            while (N % x) {
                // if that occur, this will mean that N is a prime. 
                if ((x * x) > N) {
                    // set x to N, so that upon calculating N / x will produce 1. 
                    x = N; 
                    break;
                }
                else {
                    // try the next number. 
                    x++; 
                }
            }
            cout << (N / x) << endl; 
        }
    }
    return 0; 
}

