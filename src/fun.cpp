// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>

unsigned int faStr1(const char *str) {
    enum States { findWord, correctWord, incorrectWord } state = findWord;
    int count = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        switch (state) {
        case findWord:
            if ('0' <= str[i] && str[i] <= '9') {
                state = incorrectWord;
            } else if (str[i] != ' ') {
                state = correctWord;
            }
            break;
        case correctWord:
            if (str[i] == ' ') {
                count++;
                state = findWord;
            } else if ('0' <= str[i] && str[i] <= '9') {
                state = incorrectWord;
            }
            break;
        case incorrectWord:
            if (str[i] == ' ')
                state = findWord;
            break;
        }
    }
    if (state == correctWord)
        count++;

    return count;
}

unsigned int faStr2(const char *str) {
    enum States { findWord, correctWord, incorrectWord } state = findWord;
    int count = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        switch (state) {
        case findWord:
            if ('A' <= str[i] && str[i] <= 'Z') {
                state = correctWord;
            } else {
                state = incorrectWord;
            }
            break;
        case correctWord:
            if (str[i] == ' ') {
                count++;
                state = findWord;
            } else if ('z' < str[i] || str[i] < 'a') {
                state = incorrectWord;
            }
            break;
        case incorrectWord:
            if (str[i] == ' ')
                state = findWord;
            break;
        }
    }
    if (state == correctWord)
        count++;

    return count;
}

unsigned int faStr3(const char *str) {
    enum States { findWord, checkWord } state = findWord;
    int wordsCount = 0, sumLength = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        switch (state) {
        case findWord:
            if (str[i] != ' ') {
                sumLength++;
                state = checkWord;
            }
            break;
        case checkWord:
            if (str[i] == ' ') {
                wordsCount++;
                state = findWord;
            } else {
                sumLength++;
            }
            break;
        }
    }
    if (state == checkWord)
        wordsCount++;

    return round(static_cast<double>(sumLength) / wordsCount);
}
