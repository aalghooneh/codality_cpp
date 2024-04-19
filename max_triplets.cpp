// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // Implement your solution here
    std::sort(A.begin(), A.end());


    int N = A.size();

    return std::max(A[N-1]*A[N-2]*A[N-3], A[0]*A[1]*A[N-1]);
}
