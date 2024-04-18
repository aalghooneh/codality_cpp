int solution(vector<int> &A) {
    int N = A.size();
    long long countWest = 0;
    long long passingCars = 0;

    // Count cars traveling west from right to left
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] == 1) {
            countWest++; // Increment count of west-traveling cars
        } else if (A[i] == 0) {
            passingCars += countWest; // Calculate passing cars
            if (passingCars > 1000000000) { // Check for overflow condition
                return -1;
            }
        }
    }
    
    return passingCars;
}
