
vector<int> solution(vector<int> &A, int K) {
    // Implement your solution here
    if (K == 0) return A;
    if (A.size() == 0) return A;
  
    std::vector<int> mysolution;
    K = K % A.size();
    for (int i = 0 ; i < K; i++){
        A.insert(A.begin(), *(A.end()-1));
        A.erase(A.end() - 1);
    }
    
    mysolution = A;
    return mysolution;
}
