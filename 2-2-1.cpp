//
// Created by layne on 18/12/2020.
//

#include <iostream>
#include <cstdio>
#include <cctype>

enum states {
    s0, s1, s2, s3, s4, s5, s6, se
};

using NewState = int;

NewState transit(int CurrentState, int NextChar) {
    if (CurrentState == s0) {
        if (isalpha(NextChar)) {
            return s1;
        } else {
            return se;
        }
    }

    if (CurrentState == s1) {
        if (isalnum(NextChar)) {
            return s2;
        } else {
            return se;
        }
    }

    if (CurrentState == s2) {
        if (isalnum(NextChar)) {
            return s3;
        } else {
            return se;
        }
    }

    if (CurrentState == s3) {
        if (isalnum(NextChar )) {
            return s4;
        } else {
            return se;
        }
    }

    if (CurrentState == s4) {
        if (isalnum(NextChar)) {
            return s5;
        } else {
            return se;
        }
    }

    if (CurrentState == s5) {
        if (isalnum(NextChar)) {
            return s6;
        } else {
            return se;
        }
    }

    if (CurrentState== s6) return se;

    return se;
}

int main() {
    int CurrentState = s0;
    int NextChar = std::getchar();

    while(NextChar != EOF) {
        CurrentState = transit(CurrentState, NextChar);
        if(CurrentState == se) {
            std::cout << std::endl;
            std::cout << "failed" << std::endl;
            return -1;
        }
        NextChar = std::getchar();
    }

    std::cout << std::endl;
    std::cout << "success" << std::endl;
    return 0;
}