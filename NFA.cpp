//
// Created by eduarddumitrescul on 3/11/23.
//

#include <string>
#include <fstream>
#include <unordered_set>
#include "NFA.h"

NFA::NFA(int startingState) {
    this->startingState = startingState;
}

void NFA::addTransition(int source, char letter, int destination) {
    this->transitions[letter][source].push_back(destination);
}

void NFA::readFromFile(const std::string &inputFilename) {
    std::ifstream fin(inputFilename);

    int states, transCount, wordsCount, finalStates;
    fin >> states >> this->startingState;
    fin >> finalStates;
    while(finalStates --) {
        int fState;
        fin >> fState;
        this->isFinal[fState] = true;
    }
    fin >> transCount;
    while(transCount--) {
        char letter;
        int src, dest;
        fin >> src >> letter >> dest;
        this->addTransition(src, letter, dest);
    }

}

bool NFA::checkWord(const std::string &word) {
    std::unordered_set <int> currentStates = {this->startingState};
    for(char letter: word) {
        std::unordered_set <int> nextStates;
        for(int state: currentStates){
            for(int next: transitions[letter][state])
                nextStates.insert(next);
        }
        currentStates = nextStates;
    }
    for(int state: currentStates) {
        if(isFinal[state]) {
            return true;
        }
    }
    return false;
}
