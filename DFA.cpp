//
// Created by eduarddumitrescul on 3/10/23.
//

#include <fstream>
#include "DFA.h"

DFA::DFA(int startingState) {
    this->startingState = startingState;
}

void DFA::addTransition(int source, char letter, int destination) {
    transitions[letter][source] = destination;
}

bool DFA::checkWord(const std::string &word) {
    int currentState = this->startingState;
    for(char letter: word) {
        if(transitions[letter].find(currentState) == transitions[letter].end()) {
            return false;
        }
        currentState = transitions[letter][currentState];
    }
    return this->isFinal[currentState];
}

void DFA::readFromFile(const std::string& inputFilename) {
    int states, transCount, wordsCount, finalStates;
    std::ifstream fin(inputFilename);
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
