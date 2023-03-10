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

void DFA::runFromFile(const std::string& inputFilename, const std::string& outputFilename) {
    int states, transCount, wordsCount, finalStates;
    std::ifstream fin(inputFilename);
    std::ofstream fout(outputFilename);
    fin >> states >> startingState;
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
    fin >> wordsCount;
    while(wordsCount--) {
        std::string word;
        fin >> word;
        fout << word << ' ' << this->checkWord(word) << '\n';
    }
}
