#define cpp
#ifdef cpp
//cpp
#include<iostream>
#include<chrono>    //timer module
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
int main() {
    //timer generates interrupt after specific time period
    //2 types: specific and variable
    chrono::milliseconds duration(5) ; //interrupt after 5 milliseconds
    auto start=chrono::high_resolution_clock::now();
    auto end=start+duration;
    while(chrono::high_resolution_clock::now()<end){
        cout<<"running\n";
    }
    cout<<"Interrupt....";
    
    return 0;
}

#else
//c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main() {
    
    return 0;
}
#endif