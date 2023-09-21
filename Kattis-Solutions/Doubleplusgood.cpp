
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std; 

typedef long long ll; 

int main()
{
	vector<ll> numbers; 
	
	set<ll> distinct_results; 

	ll number; 
	while (cin >> number) {
		numbers.push_back(number); 
	}

	for (int i = 0; i < (1 << (numbers.size() - 1)); i++) {

		ll total = 0; 
		
		// starting with the first digit. 
		ll curr = numbers[0]; 

		for (int j = 0; j <= numbers.size() - 2; j++) {
			if (i & (1 << j)) {
				// it is an append here. 
				string t = to_string(curr) + to_string(numbers[j + 1]);
				ll i = stoll(t);
				curr = i; 
			}
			else {
				// it is a normal plus; 
				// meaning that the number before that 'plus' may be added to total. 
				total += curr; 
				curr = numbers[j + 1]; 
			}
		}
		total += curr; 
		distinct_results.insert(total); 
	}

	cout << distinct_results.size(); 
}

