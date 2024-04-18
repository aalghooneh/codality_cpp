// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

int max_pick(std::vector<int> mushrooms, int k, int m){
    
    int N = mushrooms.size();
    
    // do prefix sum
    std::vector<int> prefix_sum(N+1,0);
    
    for(int i = 1; i <= N ; i++){
        prefix_sum[i] = prefix_sum[i-1] + mushrooms[i-1]; 
    }
    for(auto p : prefix_sum) std::cout<<p<<", ";
    std::cout<<"\n";
    std::cout<<prefix_sum[3]-prefix_sum[0]<<std::endl;
    
    // first moving to the left
    // and then moving to the right
    int total_picks =0;
    for (int j = 0; j <= std::min(m, k) ; j++){
        
        int left_pos = k - j;
        int right_pos = std::min(N-1, std::max(k, k+m-2*j));
        
        total_picks = std::max(total_picks, prefix_sum[right_pos+1] - prefix_sum[left_pos]);
    }
    // first moving to the right and
    // then moving to the left
    for (int j = 0; j <= std::min(N-k-1, m); j++){
        int right_pos = k+j;
        int left_pos = std::max(0, std::min(k, k-m + 2*j));
        total_picks = std::max(total_picks, prefix_sum[right_pos+1] - prefix_sum[left_pos]);
    }
    
    return total_picks;
    
    
}

void test(){
    
    std::vector<int> mushrooms = {2,3,7,5,1,3,9};
    int k = 4;
    int m = 6;
    
    int total_picks = max_pick(mushrooms, k, m);
    
    
    std::cout<<"max picks are: "<<total_picks<<std::endl;
    
}
int main() {
    
    test();

    return 0;
}
