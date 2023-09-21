
#include <iostream>
#include <vector>

using namespace std; 

int main()
{
	int amt_of_names; 
	cin >> amt_of_names; 

	vector<pair<string, string>> unsorted_names; 

	for (int i = 0; i < amt_of_names; i++) {
		string first; 
		string last; 
		cin >> first; 
		cin >> last; 
		pair<string, string> name = { first, last }; 
		unsorted_names.push_back(name); 
	}

	vector<int> nth_inputs; 

	for (int i = 0; i < amt_of_names; i++) {
		int nth; 
		cin >> nth; 
		nth_inputs.push_back(nth); 
	}

	vector<pair<string, string>> sorted_names; 

	for (int i : nth_inputs) {
		int index = i - 1; 
		sorted_names.push_back(unsorted_names[index]); 
	}
	
	string prev; 
	if (sorted_names[0].first > sorted_names[0].second) {
		prev = sorted_names[0].second; 
	}
	else {
		prev = sorted_names[0].first; 
	}

	bool passing = true; 
 
	for (int i = 1; i < amt_of_names; i++) {
		string first_name = sorted_names[i].first; 
		string last_name = sorted_names[i].second; 
		string smaller_name; 
		if (first_name > last_name) {
			smaller_name = last_name; 
		}
		else {
			smaller_name = first_name; 
		}
		string larger_name; 
		if (smaller_name == first_name) {
			larger_name = last_name; 
		}
		else {
			larger_name = first_name; 
		}
		if (smaller_name > prev) {
			prev = smaller_name; 
		}
		else { 
			if (larger_name > prev) {
				prev = larger_name; 
			}
			else {
				passing = false; 
				break; 
			}
		}
	}

	if (passing) {
		cout << "YES" << endl; 
	}
	else {
		cout << "NO" << endl; 
	}
   
	return 0; 
}
