
#include <iostream>
#include <limits>
#include <cmath>

using namespace std; 

bool is_prime(int num) {
	bool is_prime = true; 
	int sqrt_num = sqrt(num); 
	for (int i = 2; i <= sqrt_num + 1; i++) {
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
		int num;
		cin >> num;

		// if the number is even, just output the middle value. 
		if (num % 2 == 0) {
			cout << num / 2 << " " << num / 2 << endl;
			continue;
		}

		// if the number is prime; just output the value of 1 and N-1
		if (is_prime(num)) {
			cout << 1 << " " << num - 1 << endl;
			continue;
		}

		// else, search from the middle outward. 
		int start = num / 2 + 1;

		while (start < num) {
			int a = num - start;
			int b = start;

			if (b % a == 0) {
				cout << a << " " << b << endl;
				break;
			}
			start++;
		}
	}
	return 0;

}
