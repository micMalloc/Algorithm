//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//
#include <iostream>
#include <string>
#include <memory.h>
#define BUFSIZE 101
#define CATEGORY 4
using namespace std;

int classification(char c) {
    if ('a' <= c && c <= 'z') return 0;
    else if ('A' <= c && c <= 'Z') return 1;
    else if ('0' <= c && c <= '9') return 2;
    else if (c == ' ') return 3;
    else return 4;
}

int main (int argc, char* argv[]) {
    string str;
    int cnt[4];
    int idx;

    while (getline(cin, str)) {
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 0; i < str.size(); ++ i) {
            idx = classification(str[i]);
            
            switch (idx) {
                case 0:
                    cnt[idx] ++;
                    break;
                case 1:
                    cnt[idx] ++;
                    break;
                case 2:
                    cnt[idx] ++;
                    break;
                case 3:
                    cnt[idx] ++;
                    break;
                default:
                    break;
            }
        }
        
        for (int i = 0; i < CATEGORY; ++ i) {
            printf("%d ", cnt[i]);
        } printf("\n");
    }
    
    return 0;
}
