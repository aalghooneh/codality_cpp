#include <algorithm>
#include <limits.h>

bool canFormTriangle(std::vector<int>& A) {
    int N = A.size();
    if (N < 3) return false;

    // Sort the array
    std::sort(A.begin(), A.end());

    // Check for any triplet using long long to prevent overflow
    for (int i = 0; i < N - 2; ++i) {
        // Use long long to safely perform the addition
        long long a = A[i];
        long long b = A[i + 1];
        long long c = A[i + 2];
        
        if (a + b > c) {
            return true;
        }
    }

    return false;
}

