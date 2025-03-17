#include "ladder.h"
#include <iostream>
#include <queue>
#include <set>
#include <vector>


bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_adjacent(const string& word1, const string& word2);

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push([begin_word])
    set<string> visited;
    visited.insert(begin_word)

    while(!ladder_queue.empty()){
        ladder = ladder_queue.top();
        ladder_queue.pop();
        last_word = ladder.back();

        for(string word : word_list){
            if(is_adjacent(last_word, word)){
                if(!visited[word]){
                    visited.insert(word);
                    new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    vector<string> empty;
    return empty
}