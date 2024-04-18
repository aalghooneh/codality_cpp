// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>
int solution(vector<int> &A) {
    // Implement your solution here

    std::set<int> myset(A.begin(), A.end());

    int i = 1;
    while (1){
        if (myset.find(i) == myset.end()){
            return i;
        }
        i++;
    }
    return i;
}
