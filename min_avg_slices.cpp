#include <vector>
#include <limits>

int solution(std::vector<int> &A) {
    int N = A.size();
    if (N < 2) return 0; // Edge case, should not happen per problem statement

    // Step 1: Calculate prefix sums
    std::vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }

    // Step 2: Initialize variables to track the minimum average
    float min_avg = std::numeric_limits<float>::max();
    int min_index = 0;

    // Step 3: Check slices of length 2 and 3
    for (int i = 0; i < N - 1; ++i) {
        // Slice of length 2
        if (i < N - 1) {
            float avg2 = (prefix[i + 2] - prefix[i]) / 2.0;
            if (avg2 < min_avg) {
                min_avg = avg2;
                min_index = i;
            }
            if (avg2 == min_avg) {
                min_avg = avg2;
                min_index = std::min(min_index, i);
            }
        }

        // Slice of length 3
        if (i < N - 2) {
            float avg3 = (prefix[i + 3] - prefix[i]) / 3.0;
            if (avg3 < min_avg) {
                min_avg = avg3;
                min_index = i;
            }
            if (avg3 == min_avg) {
                min_avg = avg3;
                min_index = std::min(min_index, i);
            }
        }
    }

    // Return the start index of the slice with the smallest average
    return min_index;
}
