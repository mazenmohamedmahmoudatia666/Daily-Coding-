#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <iostream>
class CustomStack {
    private : 
      stack <int> s;
      int capicity;
     
public:
    CustomStack(int maxSize) {
        capicity = maxSize;
    }

    void push(int x) {
        if(s.size() < capicity){
            s.push(x);
        }
    }
    
    int pop() {
        if(!s.empty() ) {
           int top =  s.top();
            s.pop();
            return top;
        }
        return -1;
    }
    
    void increment(int k, int val) {
    stack<int> tempStack;

    while (!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }

    int i = 0;
    while (!tempStack.empty()) {
        int top = tempStack.top();
        tempStack.pop();
        if (i < k) {
            top += val;
        }
        s.push(top);
        i++;
    }
}
    
};
