

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


/*
* After trying hard, I can't figure out how to do G. Mere array. 
* I was consulting with solutions from online. 
* 
* First, we will establish a new list; including every element from the original list, but sorted. 
* Then, compare each element from the original list with the sorted list. For each comparison: 
* If the two numbers are the same, we don't have to think about moving it. Thus, let it stay where it is. 
* If the two are different, see whetehr the one in the orginal list is divisible by the minumum number of 
* the whole list. 
* - if it is not divisible, then the gcd of that number with any other possible number will never be the 
*   minumum number of the list; since that number is not divisible by the minumum number of the list. 
*   
*   Following that, it can never be moved. It can only stay where it is; thus will fail the whole sorting. 
* 
* - if it is divisible, move on. 
* 
* If after all, all numbers in original list that are unmatched with the corresponding index in sorted list,
* are divisible by the minumum number of the list, we can use the minumum number as an intermediate step for 
* switching the unsorted numbers until everything is sorted. 
*/

int main()
{
    int amt; 
    cin >> amt; 

    for (int i = 0; i < amt; i++) {
        int N; 
        cin >> N; 

        vector<int> numbers; 

        for (int i = 0; i < N; i++) {
            int B; 
            cin >> B; 
            numbers.push_back(B); 
        }

        vector<int> numbers_sorted; 
        for (int i : numbers) {
            numbers_sorted.push_back(i); 
        }
        sort(numbers_sorted.begin(), numbers_sorted.end()); 

        bool flg = 1; 

        int min = numbers_sorted[0]; 

        for (int i = 0; i < N; i++) {
            int current = numbers[i]; 
            int correct = numbers_sorted[i]; 
            if (current == correct) {
                // does not have to concern about the current number. It is in the right place. 
                continue; 
            }
            else {
                // current is not equal to correct. Find whether or not current is divisble by min. 
                // if it is not divisble by min, the gcd of it with any other number will never be min. 
                // Thus, it can never be moved. 
                // since it is in an incorrect location and can never be moved; the program fail. 
                if (current % min != 0) {
                    flg = 0; 
                    break; 
                }
            }
        }

        if (flg) {
            // every number in incorrect spot is divisible by min. Thus, we can use min as an intermediate
            // for switching each of the number in wrong spot into the correct location. Example: 
            // 2 8 4
            // min = 2; we need to switch 8 and 4. gcd(8, 4) = 4; however: 
            // switch 2 with 4; gcd(2, 4) = 2;   
            // 4 8 2
            // switch 2 with 8; gcd(8, 2) = 2; 
            // 4 2 8
            // switch 4 with 2; 
            // 2 4 8
            // done. 
            cout << "YES" << endl; 
        }
        else {
            // a number in wrong location is not divisible by min; thus gcd of it with any other number
            // will never be min; thus  it can never be moved. 
            cout << "NO" << endl; 
        }
    }
}
