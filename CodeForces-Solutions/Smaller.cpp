
#include <iostream>

using namespace std; 

bool contain_bplus(string s) {
    for (char c : s) {
        if (c != 'a') {
            return true;
        }
    }
    return false;
}

long long find_size(string s) {
    long long accumulator = 0; 
    for (char c : s) {
        if (c != '\0') {
            accumulator = accumulator + 1; 
        }
    }
    return accumulator; 
}

int main() {
    int num_cases; 
    cin >> num_cases; 

    for (int i = 0; i < num_cases; i++) {
        string s = "a"; 
        string t = "a"; 
        long long s_length = 1; 
        long long t_length = 1; 
        int num_operations;
        cin >> num_operations; 

        bool s_morethan_a = false; 
        bool t_guaranteed = false; 

        for (int i = 0; i < num_operations; i++) {
            int type; 
            cin >> type; 
            int k; 
            cin >> k; 
            string extra; 
            cin >> extra; 

            if (t_guaranteed) {
                cout << "YES" << endl; 
                continue; 
            }

            if (type == 1) {

                s_length = s_length + find_size(extra) * k;

                if (contain_bplus(extra)) {
                    s_morethan_a = true; 
                }
                if (s_morethan_a) {
                    cout << "NO" << endl; 
                }
                else {
                    if (t_length > s_length) {
                        cout << "YES" << endl; 
                    }
                    else {
                        cout << "NO" << endl; 
                    }
                }
            }
            else {
                // type == 2

                t_length = t_length + find_size(extra) * k;

                if (contain_bplus(extra)) {
                    t_guaranteed = true; 
                    cout << "YES" << endl;
                }
                else {
                    if (s_morethan_a) {
                        cout << "NO" << endl; 
                    }
                    else {
                        if (t_length > s_length) {
                            cout << "YES" << endl;
                        }
                        else {
                            cout << "NO" << endl; 
                        }
                    }
                }
            }
        }
    }
    return 0; 
}
