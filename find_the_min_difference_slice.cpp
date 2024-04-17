#include "math.h"



int solution(vector<int> &A) {
    // Implement your solution here
    

    typedef  std::vector<int> vec;



    
    int N = A.size();
    
    vec sum_left(N);
    vec sum_right(N);

    sum_left[0]= 0;
    sum_right[N-1] = A[N-1];

    for (int i = 1 ; i < N ; ++i){
        sum_left[i] = sum_left[i-1] + A[i-1];
    }
    
    
    for (int i = N-2; i>=0 ; i--){
        sum_right[i] = sum_right[i+1] + A[i];
    }
    

    int min_diff=100000000;
    int min_candid;
    for (int p = 1; p < N ; p++){
        
        min_candid = std::abs( sum_right[p] - sum_left[p]);

        min_diff = std::min(min_diff, min_candid);

    }

    return min_diff;
}
