#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

// check whether or not the supplied input is a prime. 
// the minimum number it has to deal with is 2. 
bool is_prime(int num) {
	bool is_prime = true;
	int sqrt_num = sqrt(num);
	for (int i = 2; i <= sqrt_num; i++) {
		if (num % i == 0) {
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

// check whether or not i has multiple less than NplusOne. 
bool has_multiple(int i, int NplusOne) {
	if (i * 2 <= NplusOne) {
		return true; 
	}
	else {
		return false; 
	}
}

// prime check and multiple check is working super well. 
int main()
{
	int N; 
	cin >> N; 

	vector<int> numbers; 

	for (int i = 2; i <= N + 1; i++) {
		numbers.push_back(i); 
	}

	vector<int> colors;  

	for (int i : numbers) {
		if (is_prime(i)) {
			// see if i's multiple is in the list. 
			if (has_multiple(i, N + 1)) {
				colors.push_back(2); 
			}
			// prime who is along in the list. 
			else {
				colors.push_back(1); 
			}
		}
		else {
			// none primes. 
			colors.push_back(1); 
		}
	}

	// below is the wrong way for calculating amt_of_color. 
	bool one_used = false; 
	bool two_used = false; 
	for (int i : colors) {
		if (i == 1) {
			one_used = true; 
		}
		if (i == 2) {
			two_used = true; 
		}
		if (one_used && two_used) {
			break; 
		}
	}
	int amt_of_color = 0; 
	if (one_used) {
		amt_of_color++; 
	}
	if (two_used) {
		amt_of_color++; 
	}

	cout << amt_of_color << endl;
	for (int i : colors) {
		cout << i << " "; 
	}
	cout << endl;  

	return 0; 
}
