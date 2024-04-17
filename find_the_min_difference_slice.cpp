#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

int min_diff(std::vector<int> vec){
    
    int N = vec.size();
    int min_diff  =  std::numeric_limits<int>::max();
    int P = 0;
    
    std::vector<int> sum_vec_left(N);
    sum_vec_left[0]=vec[0];
    
    for (int i = 1 ; i < N ; i++){
        sum_vec_left[i] = sum_vec_left[i-1] + vec[i];
    }
    
    std::vector<int> sum_vec_right(N);
    sum_vec_right[N-1] = vec[N-1];
    
    for (int j = N - 2; j >=0 ; j--){
        sum_vec_right[j] = sum_vec_right[j+1] + vec[j];
    }
    
    for (int p = 0 ; p < N ; p++){
        
        int temp_diff = std::abs( sum_vec_left[p] - sum_vec_right[p+1]);
        
        if (temp_diff <= min_diff){
            min_diff = temp_diff;
            P = p;
        }
    }


    return P;
}


int main(){
    std::vector<int> vec = {10,20,30,40,50,149};
    
    std::cout<<min_diff(vec);
}

