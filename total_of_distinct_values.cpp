#include <limits.h>
#include <vector>

int solution(std::vector<int> &A) {
    
    if (A.empty()) return 0;

    int N = A.size();
    int min_el = INT_MAX;
    int max_el = INT_MIN;

    // Finding minimum and maximum element in one pass
    for (int i = 0; i < N; i++) {
        min_el = std::min(A[i], min_el);
        max_el = std::max(A[i], max_el);
    }

    int range = max_el - min_el + 1;
    std::vector<int> counts(range, 0);

    // Counting the occurrences of each element
    for (int i = 0; i < N; i++) {
        counts[A[i] - min_el]++;
    }

    int dc = 0;
    // Finding the first distinct element
    for (int i = 0; i < range; i++) {
        if (counts[i]){
            dc++;
        }
    }

    return dc;  // If no distinct element found
}
