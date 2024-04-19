int solution(std::vector<int> &A, std::vector<int> &B) {
    const int DOWNSTREAM = 1;
    std::vector<int> stack;
    int survivors = 0;

    for (size_t i = 0; i < A.size(); i++) {
        if (B[i] == DOWNSTREAM) {
            stack.push_back(A[i]);
        } else {
            while (!stack.empty()) {
                if (stack.back() < A[i]) {
                    stack.pop_back();
                } else {
                    break;
                }
            }
            if (stack.empty()) {
                survivors++;  // This upstream fish survives as it's eaten all in its path or there were no fish to eat
            }
        }
    }

    return survivors + stack.size(); // Total survivors are those upstream not eaten + remaining downstream
}
