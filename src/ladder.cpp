#include "ladder.h"
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int distance_helper(string longer, string shorter, int len_long, int len_short){
    int i = 0, j = 0;
    int diff = 0;
    while(i < len_long && j < len_short){
        if(longer[i] != shorter[i]){   //iterate through both
            diff += 1;   //count every difference
            i++;   //longer string moves onto next word
        }
        i++, j++;  //loop increment
    }
    return diff  //return # of differences
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int len1 = str1.length(), len2 = str2.length();
    if(str1 == str2)  //strings are equal
        return true;
    if(abs(len1 - len2) > 1)  //string lengths differ by 2+
        return false;
    
    int diff = 0;
    if(len1 == len2){ //words are same length
        for(int i = 0; i < len1; i++)
            if(str1[i] != str2[i])  //iterate through both
                diff += 1;  //count every difference
    }

    if(len1 != len2){  //words differ by 1 length
        bool str1_longer = len1 > len2;  //find which str longer
        if(str1_longer)  //str1 longer
            diff += distance_helper(str1, str2, len1, len2); //helper calculates distances
        else if(!str1_longer)
            diff += distance_helper(str2, str1, len2, len1);
    }
    return(!diff>1) //more than 1 diff, false
}

bool is_adjacent(const string& word1, const string& word2){
    return(edit_distance_within(word1, word2, 1));
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push(vector<string>{begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for(string word : word_list){
            if(is_adjacent(last_word, word)){
                if(visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}