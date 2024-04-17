#include <vector>
#include <algorithm> // For std::max

int solution(vector<int> &A) {
    int n = A.size();

    // Check if the numbers from 1 to n appear exactly once
    std::vector<int> counts(n, 0);

    for (int value : A) {
        if (value < 1 || value > n) {
            return 0; // Value out of the range [1, n]
        }
        counts[value - 1]++;
    }

    // Check if each number from 1 to n appears exactly once
    for (int count : counts) {
        if (count != 1) {
            return 0; // A number does not appear exactly once
        }
    }

    return 1; // A is a valid permutation
}
