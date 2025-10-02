#include "card_utils.h"
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// Check uniqueness 
bool checkCardUniqueness(const vector<pair<char, char>> & cards){
    //set auto removes dups, only unique cards are stored
    set<pair<char, char>> unique_cards(cards.begin(), cards.end());
    return unique_cards.size() == cards.size();
}

// Comparator for sorting
bool cardCompare(const pair<char, char>& a, const pair<char, char>& b) {
    string ranks = "23456789TJQKA"; // T = ten, 2 --> lowest, A --> highest
    string suits = "CDHS"; // club < diamond < hearts < spades
    
    int rankA = ranks.find(a.first); //get rank position
    int rankB = ranks.find(b.first);
    
    
    if (rankA != rankB) return rankA < rankB; //lower rank comes first
    return suits.find(a.second) < suits.find(b.second); // lower suits comes first
}

// Sort function
void sortCards(vector<pair<char, char>> & cards){
    sort(cards.begin(), cards.end(), cardCompare);
}

// Print function
void printCards(const vector<pair<char, char>> & cards){
    for (const auto & card : cards) {
        cout << card.first << card.second << ' ';
    }
    cout << endl;
}