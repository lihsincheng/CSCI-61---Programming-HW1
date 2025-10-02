#ifndef CARD_UTILS_H
#define CARD_UTILS_H

#include <vector>
#include <utility>

bool checkCardUniqueness(const std::vector<std::pair<char, char>> & cards);
void sortCards(std::vector<std::pair<char, char>> & cards);
void printCards(const std::vector<std::pair<char, char>> & cards);

#endif