//
//  main.cpp
//  PracticeAlgo
//
//  Created by 이희수 on 2018. 9. 27..
//  Copyright © 2018년 Heesu.lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
    int t;
    int n, m;
    int a, b;
    
    ios::sync_with_stdio(false);
    
    cin >> t;
    while (t --) {
        cin >> n >> m;
        while (m --) {
            cin >> a >> b;
        } printf("%d\n", n - 1);
    }
    
    return 0;
}
