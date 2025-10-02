#ifndef CARD_UTILS_H
#define CARD_UTILS_H

#include <vector>
#include <utility>

// Check if all cards are unique
bool checkCardUniqueness(const std::vector<std::pair<char, char>> & cards);
//Sort the cards by their rank/suit in ascending order
void sortCards(std::vector<std::pair<char, char>> & cards);
//Display cards
void printCards(const std::vector<std::pair<char, char>> & cards);

#endif