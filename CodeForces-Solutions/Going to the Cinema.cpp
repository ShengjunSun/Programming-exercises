
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
	int amt; 
	cin >> amt; 

	for (int i = 0; i < amt; i++) {
		int N;
		cin >> N;

		vector<int> wishes;

		for (int i = 0; i < N; i++) {
			int wish;
			cin >> wish;
			wishes.push_back(wish);
		}

		sort(wishes.begin(), wishes.end());

		int index = 0;

		bool next_T_dnt_cnt = false;

		int amt = 0;

		for (int i : wishes) {
			if (i <= index) {
				if (!next_T_dnt_cnt) {
					amt++;
					// this number already qualify. If the next number qualify; does not count. 
					next_T_dnt_cnt = true;
				}
				// if next_T_dnt_cnt is true, then the above if clause will not execute. 
				// As a result, amt stay the same. next_T_dnt_cnt stays true. 
			}
			else {
				// this number does not qualify. Thus, next number will count if qualify. 
				next_T_dnt_cnt = false;
			}
			// be ready for the next run. 
			index++;
		}

		bool start_qualified = false;
		if (wishes[0] <= 0) {
			start_qualified = true;
		}

		if (amt == 1 && !start_qualified) {
			cout << 2 << endl;
		}
		else {
			cout << amt + int(!start_qualified) << endl;
		}
	}
}

