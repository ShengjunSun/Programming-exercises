
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

struct part {
    int low; 
    int high; 
    int th; 
};

struct actor {
    int low; 
    int high; 
    int k; 
    int th; 
};

// sort the parts by smaller start pitch. 
bool smaller_start(part a, part b) {
    int a_low = a.low; 
    int b_low = b.low; 
    if (a_low < b_low) {
        return true; 
    }
    return false; 
}

// sort the actors by smaller ending pitch. 
bool smaller_end(actor a, actor b) {
    int a_high = a.high; 
    int b_high = b.high; 
    if (a_high < b_high) {
        return true; 
    }
    return false; 
}

int main()
{
    int num_parts; 
    cin >> num_parts; 

    vector<part> parts; 

    for (int i = 1; i <= num_parts; i++) {
        int low; 
        int high; 
        cin >> low; 
        cin >> high;
        parts.push_back({ low, high, i }); 
    }

    int num_actors; 
    cin >> num_actors; 

    vector<actor> actors; 

    for (int i = 1; i <= num_actors; i++) {
        int low; 
        int high; 
        int k; 
        cin >> low; 
        cin >> high; 
        cin >> k; 
        actors.push_back({ low, high, k, i });        
    }

    // sort the parts by smaller starting pitch. 
    sort(parts.begin(), parts.end(), smaller_start); 

    // sort the actors by smaller ending pitch. 
    sort(actors.begin(), actors.end(), smaller_end);
    
    vector<int> output_raw; 
    for (auto& part : parts) {
        bool get_an_actor = false; 
        for (auto& actor : actors) {
            // if the actor's high pitch is at least the part's high pitch
            if (actor.high >= part.high) {
                // if the actor is qualified to be assigned
                if (actor.k > 0) {
                    // check low end: 
                    if (actor.low <= part.low) {
                        // assign the actor to the part. 
                        output_raw.push_back(actor.th); 
                        // the actor gets one less availability. 
                        actor.k--; 
                        // indicate the part is getting an actor. 
                        get_an_actor = true; 
                        // already get an actor; so break from the actor searching for loop. 
                        break; 
                    }
                }
            }
        }
        // quit if the part cannot be assigned an actor. 
        if (!get_an_actor) {
            std::cout << "NO" << endl; 
            return 0; 
        }
    }

    // indicating the part may be assigned an actor. 

    std::cout << "YES" << endl; 

    // be mindful that the output should correspond to the order of parts as inputted. 

    vector<int> output_right(parts.size(), -1); 

    int index_counter = 0; 
    for (auto part : parts) {
        output_right[part.th - 1] = output_raw[index_counter]; 
        index_counter++; 
    }

    for (int i : output_right) {
        std::cout << i << " "; 
    }
}
