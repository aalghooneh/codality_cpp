int solution(int N) {
    // Implement your solution here

    int gap = 0;
    int max_gap = 0;
    bool counting = false;



    while (N > 0){

        if ((N&1) == 1){
            if (counting){
                max_gap = std::max(max_gap, gap);
                gap = 0;
            } else{
                counting = true;
            }
        } else{
            if (counting){
                gap++;
            }
        }
        N >>=1;

    }

    return max_gap;
}
