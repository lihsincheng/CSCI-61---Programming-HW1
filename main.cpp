#include "card_utils.h"
#include <iostream>
using namespace std;
// Used CPlusPlus.com for help
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;





int main() {

        vector<pair<char, char>> cards = {
        {'A', 'S'}, {'K', 'H'}, {'2', 'D'}, {'J', 'C'}, {'A', 'S'}  //duplicate test
    };

    cout << "Checking card uniqueness..." << endl;
    if (checkCardUniqueness(cards)) {
        cout << "All cards are unique." << endl;
    } else {
        cout << "There are duplicate cards." << endl;
    }

    cout << endl << "Sorting cards..." << endl;
    sortCards(cards);
    printCards(cards);

    return 0;
}