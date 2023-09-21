#include <iostream>

// solution is passing; and solution is as inspired by my mates. 
// written by Michael Sun; inspired by mates. 

using namespace std; 

typedef unsigned long long ull;

// table and set table is working well. 
ull table[51][51]; 

void set_table() {
    table[0][0] = 1; 
    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            if (j == 0) {
                table[i][j] = 1; 
            }
            else {
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j]; 
            }
        }
    }
}

void solve() {
    int th; 
    int num; 
    cin >> th; 
    cin >> num; 
    
    // guaranteed to be a perfect division; since num itself is even. 
    int amt_2_at_max = num / 2; 

    // not guaranteed to be a perfect division; if have remainder; just take the floor as by default. 
    int amt_pair_2_at_max = amt_2_at_max / 2; 

    // amt of pair of 2 at minimum. 
    // note that 'pair' just ensure even amount of 2. 
    int amt_pair_2_at_min; 
    if (amt_2_at_max % 3 == 0) {
        amt_pair_2_at_min = amt_2_at_max / 3; 
    }
    else {
        amt_pair_2_at_min = amt_2_at_max / 3 + 1; 
    }

    ull sum = 0; 
    for (int i = amt_pair_2_at_min; i <= amt_pair_2_at_max; i++) {
        ull pair_of_ones = amt_2_at_max - (2 * i); 
        ull half_choice = table[pair_of_ones + i][i]; 
        ull full_choice = half_choice * half_choice; 
        sum += full_choice; 
    }
    cout << th << " " << sum << endl; 
}

int main()
{
    set_table();

    int amt; 
    cin >> amt; 

    while (amt--) {
        solve(); 
    }
    return 0; 
}

