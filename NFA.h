//
// Created by eduarddumitrescul on 3/11/23.
//

#ifndef LFA_FINITE_AUTO_NFA_H
#define LFA_FINITE_AUTO_NFA_H

#include <unordered_map>
#include <vector>


class NFA {
    int startingState;
    std::unordered_map<int, std::vector <int>> transitions[256];
    std::unordered_map<int, bool> isFinal;

public:
    NFA(int startingState=0);

    void addTransition(int source, char letter, int destination) ;

    void readFromFile(const std::string& inputFilename);

    bool checkWord(const std::string &word);
};


#endif //LFA_FINITE_AUTO_NFA_H
