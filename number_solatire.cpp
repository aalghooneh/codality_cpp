
int solution(vector<int> &A) {
    // Implement your solution here

    int N = A.size();
    int K = 6;

    std::vector<int> dp(N, 0);

    dp[0] = A[0];
    for (int i = 1 ; i < N ; i++){
        int max_pos = dp[i-1];
        for (int j = 1 ; j <= K ; j++){
            
            if (i-j >= 0)
                max_pos = std::max(dp[i-j], max_pos);
            else
                break;
        }
        dp[i] = A[i] + max_pos;
    }

    return dp[N-1];
}
