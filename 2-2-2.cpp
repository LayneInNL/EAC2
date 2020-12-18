//
// Created by layne on 18/12/2020.
//

#include <iostream>
#include <cstdio>
#include <cctype>

enum states {
    s0, s1, s2, se
};

using NewState = int;

NewState transit(int CurrentState, int NextChar) {
    if (CurrentState == s0) {
        if (NextChar == '(') {
            return s1;
        } else {
            return se;
        }
    }

    if (CurrentState == s1) {
        if (NextChar == ')') {
            return s2;
        } else {
            return se;
        }
    }

    if (CurrentState == s2) {
        if (NextChar == '(') {
            return s1;
        } else {
            return se;
        }
    }

    return se;
}

int main() {
    int CurrentState = s0;
    int NextChar = std::getchar();

    while (NextChar != EOF) {
        CurrentState = transit(CurrentState, NextChar);
        if (CurrentState == se) {
            std::cout << std::endl;
            std::cout << "failed" << std::endl;
            return -1;
        }
        NextChar = std::getchar();
    }

    if (CurrentState == s1) {
        std::cout << std::endl;
        std::cout << "failed" << std::endl;
        return -1;

    }

    std::cout << std::endl;
    std::cout << "success" << std::endl;
    return 0;
}