#include "ladder.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int i = 0, j = 0;
    int diff = 0;
    while(i < d && j < d-1){
        if(str1[i] != str2[i]){   //iterate through both
            diff += 1;   //count every difference
            i++;   //longer string moves onto next word
        }
        i++, j++;  //loop increment
    }
    return(diff<=1);  //return # of differences
}

bool is_adjacent(const string& word1, const string& word2){
    int len1 = word1.length(), len2 = word2.length();
    if(word1 == word2)  //strings are equal or differ by <=1
        return true;
    
    if(abs(len1 - len2) > 1) //string length differ by 2+
        return false;
    
    bool adjacent = true;
    if(len1 == len2){ //words are same length
        int diff = 0;
        for(int i = 0; i < len1; i++)
            if(word1[i] != word2[i])  //iterate through both
                diff += 1;  //count every difference
        adjacent = diff<=1;
    }

    if(len1 != len2){   //words differ by 1 length
        bool word1_longer = len1 > len2;    //find which str longer
        if(word1_longer)    //word1 longer
            adjacent = edit_distance_within(word1, word2, len1); //helper calculates distances
        else if(!word1_longer)
            adjacent = edit_distance_within(word2, word1, len2);
    }
    return adjacent; //more than 1 diff, false
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
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

void error(string word1, string word2, string msg){
    if(word1 == word2)
        cout << msg << " ";
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    string word;
    while(in >> word)
        word_list.insert(word);
}

void print_word_ladder(const vector<string>& ladder){
    if(ladder.empty())
        cout << "No word ladder found." << endl;
    else{
        cout << "word ladder found: ";
        for(size_t i = 0; i < ladder.size(); i++)
            cout << ladder[i] << " ";
        cout << endl;
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, "words.txt");
    /*
    vector<string> test = generate_word_ladder("cat", "dog", word_list);
    print_word_ladder(test);
    my_assert(test.size() == 4);
    */
    ///*
    //my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    //my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    //my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
    //*/
}

