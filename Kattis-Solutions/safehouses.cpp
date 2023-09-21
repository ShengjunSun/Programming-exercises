#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <limits>

using namespace std; 

map<vector<int>, int> entries; 
vector<vector<int>> houses; 
vector<vector<int>> soldiers; 

// calculate the manhattan distance between the start point and the end point. 
int manh_distance(vector<int> start, vector<int> end) {
	int start_x = start[0]; 
	int start_y = start[1]; 
	int end_x = end[0]; 
	int end_y = end[1]; 

	return abs(start_x - end_x) + abs(start_y - end_y); 
}

int main() {
	int dimension; 
	cin >> dimension; 

	for (int i = 1; i <= dimension; i++) {
		string line; 
		cin >> line; 

		stringstream ss; 
		ss.str(line); 
		ss.clear(); 

		char c; 

		for (int k = 1; k <= dimension; k++) {
			ss >> c; 
			if (c == 'H') {
				vector<int> house = { i, k }; 
				houses.push_back(house); 
			}
			if (c == 'S') {
				vector<int> soldier = { i, k }; 
				soldiers.push_back(soldier); 
			}
		}
	}

	for (vector<int>& soldier : soldiers) {
		int optimal_distance = std::numeric_limits<int>::max(); 
		for (vector<int>& house : houses) {
			int curr_distance = manh_distance(soldier, house); 
			if (curr_distance < optimal_distance) {
				optimal_distance = curr_distance; 
			}
		}
		entries.insert(pair<vector<int>, int>(soldier, optimal_distance)); 
	}

	int answer = 0; 

	for (auto& entry : entries) {
		int distance = entry.second;
		if (distance > answer) {
			answer = distance; 
		}
	}

	cout << answer; 

	return 0; 
}


