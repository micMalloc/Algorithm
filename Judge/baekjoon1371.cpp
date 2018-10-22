//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//

#include <cstdio>

int main (int argc, char* argv[]) {
    int cnt[26];
    char str[5001];
    int max;
    
    while (fgets(str, sizeof(str), stdin)) {
        for (int i = 0; str[i] != '\0'; ++ i) {
            if ('a' <= str[i] && str[i] <= 'z') {
                cnt[str[i] - 'a'] ++;
            }
        }
    }
    
    max = 0;
    for (int i = 0; i < 26; ++ i) {
        if (max < cnt[i]) {
            max = cnt[i];
        }
    }
    
    for (int i = 0; i < 26; ++ i) {
        if (cnt[i] == max) {
            printf("%c", 'a' + i);
        }
    }
    
    return 0;
}
