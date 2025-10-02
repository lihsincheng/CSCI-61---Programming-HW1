# CSCI-61---Programming-HW1
Another way to store collection of items is in a keyed bag. In this type of container, whenever an item is added, the programmer using the keyed bag also provides an integer called the key. Each item added to the keyed bag must have a unique key; two items cannot have the same key. When the programmer wants to remove an item from a keyed bag, the key of the item must be specified, rather than the item itself. You are to implement the KeyedBag class using a vector of pair. Your implementation should be a template class that depends on the data types of the keys and the data type of the underlying data. The class interface should have the following:
A function to add an item.
A function to remove an item.
A boolean function to determine whether the bag has an item with a specific key.
A function to display all the items in the bag.

Design and implement a class that stores a gift list for your friends and relatives. You will need a container of containers to hold a list of persons, each of which has a list of possible gift ideas. Choose the optimal STL container for this problem, noting that no duplicates should be permitted. Develop a test program, which allows options to add, remove, and list persons and their gift list.

Given a list of playing cards, implement a boolean function to tell whether the cards are all unique. To simplify the problem, let's assume that the cards are represented by a pair of two char's. The first and second char in the pair are the rank ('2', '3', ... , 'J', 'Q', 'K', and 'A') and the suite ( 'H', 'D', 'C', and 'S'), respectively.

Given a list of playing cards, implement a function to print out the cards in ascending order. Let's assume the card's data structure is as specified in problem 3. Also, state your assumption on the ordering of the suite as a comment in the code. 