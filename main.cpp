#include <iostream>
#include <fstream>
#include "DFA.h"

int main() {
    DFA dfa;
    dfa.runFromFile("../testfiles/dfa.in", "../testfiles/dfa.out");


    return 0;
}
