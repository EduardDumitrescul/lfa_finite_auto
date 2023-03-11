#include <iostream>
#include <fstream>
#include "DFA.h"
#include "NFA.h"

void testDFA() {
    DFA dfa;
    dfa.readFromFile("../testfiles/dfa.in");
    std::ifstream fin("../testfiles/words.txt");
    int words;
    fin >> words;
    while(words--) {
        std::string word;
        fin >> word;
        std::cout << word << ' ' << dfa.checkWord(word) << '\n';
    }
    fin.close();
}

void testNFA() {
    NFA nfa;
    nfa.readFromFile("../testfiles/nfa.in");
    std::ifstream fin("../testfiles/words.txt");
    int words;
    fin >> words;
    while(words--) {
        std::string word;
        fin >> word;
        std::cout << word << ' ' << nfa.checkWord(word) << '\n';
    }
    fin.close();
}

int main() {
    testDFA();
    testNFA();

    return 0;
}
