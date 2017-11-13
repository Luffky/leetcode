//
//  main.cpp
//  3.Longest Substring Without Repeating Characters
//
//  Created by 伏开宇 on 2017/8/3.
//  Copyright © 2017年 伏开宇. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string s = "345dv021deaqwb";
    int* a = new int[127];
    int most = 0;
    for (int i = 0; i < 127; i++){
        a[i] = -1;
    }
    int start = 0;
    int length = s.length();
    int j;
    for (j = 0; j < length; j++){
        if(a[s[j]] != -1){
            most = max(most, j - start);
            for(int k = start; k < a[s[j]]; k++){
                a[s[k]] = -1;
            }
            start = a[s[j]] + 1;
            a[s[j]] = j;
        }
        else{
            a[s[j]] = j;
        }
    }
    most = max(most, j - start);
    cout<<most<<endl;
    return 0;
}
