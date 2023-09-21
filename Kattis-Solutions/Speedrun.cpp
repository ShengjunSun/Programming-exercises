#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

bool increasing_end(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main()
{
	int m; 
	int n; 
	cin >> m; 
	cin >> n; 

	vector<pair<int, int>> tasks; 

	while (n--) {
		int task_start; 
		int task_end; 
		cin >> task_start; 
		cin >> task_end; 
		tasks.push_back({ task_start, task_end }); 
	}

	sort(tasks.begin(), tasks.end(), increasing_end); 

	int curr_end_time = 0; 

	int amt = 0; 

	for (auto task : tasks) {
		if (task.first >= curr_end_time) {
			amt++; 
			curr_end_time = task.second; 
		}
	}

	if (amt >= m) {
		cout << "YES" << endl; 
	}
	else {
		cout << "NO" << endl; 
	}

	return 0; 
}

