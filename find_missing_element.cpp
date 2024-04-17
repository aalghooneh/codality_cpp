// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


#include <set>
int solution(vector<int> &A) {
    // Implement your solution here
    if (A.size() == 0) return 1;

    std::set<int> myset(A.begin(), A.end());
    int N = A.size();
    
    int found = 0;
    for (int i = 1; i<=(N+1) ; i++ ){

        if (myset.find(i) == myset.end()){
            found = i;
            break;
        }

    }

    return found;
}
