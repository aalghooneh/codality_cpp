int solution(int X, vector<int> &A) {
    int current_pos = 0;
    int N = A.size();
    
    if (A.size() == 0) return -1;
    if (X==0) return -1;
  
  
    int time_took = -1;
    std::vector<bool> covered(X, false);
    int needed_pos = current_pos + 1;
    
    for (int sec = 0; sec < N; sec++) {
        if (current_pos == X) {
            break;
        }
        int pos = A[sec];
        covered[pos-1] = true;
        while (covered[needed_pos-1]) {
            current_pos++;
            needed_pos = std::min(current_pos + 1, X);
            if (current_pos == X) {
                time_took = sec;
                break;
            }
        }
    }
    return time_took;
}
