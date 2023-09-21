#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int calculate(int input) {
	vector<int> binary; 
	int input_cp = input; 
	int remainder; 
	while (input_cp != 0) {
		remainder = input_cp % 2;
		input_cp = input_cp / 2; 
		binary.push_back(remainder);
	}

	// now let's convert the 'binary' back to decimal.
	int length = binary.size(); 
	int power = 0; 
	int answer = 0; 
	for (int i = length - 1; i >= 0; i--) {
		if (binary[i] == 1) {
			answer += pow(2, power); 
		}
		power++; 
	}

	return answer; 
}

int main() {
	int input; 

	cin >> input; 
	cout << calculate(input) << endl; 
}



