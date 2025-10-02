#include "card_utils.h"
#include <iostream>
using namespace std;
// Used CPlusPlus.com for help
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

//problem 1
template <typename KeyType, typename ValueType>
class KeyedBag {
private:
    vector<pair<KeyType, ValueType>> data;

public:
    bool add(const KeyType& key, const ValueType& value) {
        if (hasKey(key)) {
            cout << "Error: Key " << key << " already exists." << endl;
            return false;
        }
        data.push_back(make_pair(key, value));
        return true;
    }

    bool remove(const KeyType& key) {
        auto it = find_if(data.begin(), data.end(),
                          [&key](const pair<KeyType, ValueType>& element) {
                              return element.first == key;
                          });
        if (it != data.end()) {
            data.erase(it);
            return true;
        }
        cout << "Error: Key " << key << " not found." << endl;
        return false;
    }

    bool hasKey(const KeyType& key) const {
        return any_of(data.begin(), data.end(),
                      [&key](const pair<KeyType, ValueType>& element) {
                          return element.first == key;
                      });
    }

    void display() const {
        if (data.empty()) {
            cout << "Bag is empty." << endl;
            return;
        }
        cout << "KeyedBag contents:" << endl;
        for (const auto& item : data) {
            cout << "Key: " << item.first << ", Value: " << item.second << endl;
        }
    }
};
// problem 2
class GiftList {
private:
    map<string, set<string>> friends;

public:
    bool addPerson(const string& name) {
        if (friends.find(name) != friends.end()) {
            cout << "Person " << name << " already exists.\n";
            return false;
        }
        friends[name] = set<string>();
        cout << "Added person: " << name << endl;
        return true;
    }

    bool removePerson(const string& name) {
        auto it = friends.find(name);
        if (it == friends.end()) {
            cout << "Person " << name << " not found. " << endl;
            return false;
        }
        friends.erase(it);
        cout << "Removed person: " << name << endl;
        return true;
    }

    bool addGift(const string& name, const string& gift) {
        auto it = friends.find(name);
        if (it == friends.end()) {
            cout << "Person " << name << " not found." << endl;
            return false;
        }
        auto& giftList = it->second;
        if (!giftList.insert(gift).second) {
            cout << "Gift \"" << gift << "\" already exists for " << name << endl;
            return false;
        }
        cout << "Added gift \"" << gift << "\" for " << name << endl;
        return true;
    }

    bool removeGift(const string& name, const string& gift) {
        auto it = friends.find(name);
        if (it == friends.end()) {
            cout << "Person " << name << " not found." << endl;
            return false;
        }
        auto& giftList = it->second;
        if (giftList.erase(gift) == 0) {
            cout << "Gift \"" << gift << "\" not found for " << name << endl;
            return false;
        }
        cout << "Removed gift \"" << gift << "\" from " << name << endl;
        return true;
    }

    void display() const {
        if (friends.empty()) {
            cout << "Gift list is empty." << endl;
            return;
        }
        cout << "\nGift List:" << endl;
        for (const auto& entry : friends) {
            cout << entry.first << ": ";
            if (entry.second.empty()) {
                cout << "[No gifts yet]";
            } else {
                for (const auto& gift : entry.second) {
                    cout << gift << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== STL ASSIGNMENT DEMO ===" << endl;
    
    // Test KeyedBag
    cout << "\n--- Testing KeyedBag ---" << endl;
    KeyedBag<int, string> bag;
    bag.add(1, "Apple");
    bag.add(2, "Banana");
    bag.add(3, "Cherry");
    bag.display();
    bag.remove(2);
    bag.display();
    
    // Test GiftList
    cout << "\n--- Testing GiftList ---" << endl;
    GiftList gl;
    gl.addPerson("Alice");
    gl.addPerson("Bob");
    gl.addGift("Alice", "Book");
    gl.addGift("Alice", "Chocolate");
    gl.display();
    
    // Test Card 
    cout << "\n--- Testing Card Utilities ---" << endl;
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