// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <numeric>

typedef std::vector<int> Vec;
typedef int (*funcptr)(Vec,int);


void (*measure_time)(funcptr, Vec, int) = [](funcptr func, Vec vec, int N){
    
    auto start_timer = std::chrono::high_resolution_clock::now();
    
    std::cout<<"the missing bitch is "<<func(vec, N) <<std::endl;
    
    auto end_timer = std::chrono::high_resolution_clock::now();
    
    
    auto elapsed = end_timer - start_timer;
    
    std::cout<<"time took this function was "<< std::chrono::duration_cast<
    std::chrono::milliseconds>(elapsed).count()<<std::endl;
    
    
    std::cout<<"\n\n";
};

int find_missing_with_hashmaps(Vec vec, int N){
    
    if (vec.size() == 0) return 0;
    
    std::unordered_set<int> myset(vec.begin(), vec.end());
    
    
    for (int i = 0 ; i < N ; i++){
        if (myset.find(i) == myset.end()) {
            return i;
        }
    }
    
    std::cout<<"nothing is missed in this array"<<std::endl;
    return 0;
    
}


int find_missing_with_sort(Vec vec, int N){
    
    
    Vec alias_vec = vec;
    
    
    std::sort(alias_vec.begin(), alias_vec.end(), [](int a, int b ){
        return a < b;
    });
    
    
    for (int i = 0 ; i < alias_vec.size() ; i++){
        if (alias_vec[i] != i) return i;
    }
    
    
    return 0;
    
    
}


int main() {
    

    
    int N = 10000000;
    
    
    Vec vec(N);
    
    
    std::iota(vec.begin(), vec.end(), 0 );

    
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, N-1);
    
    
    for (int i = 0 ; i < 100 ; i++){
        int a = distrib(gen);
        int b = distrib(gen);
        
        std::swap(vec[a], vec[b]);
    }
    
    
    int lucky_index = distrib(gen);
    
    
    std::cout<<"removing the index "<<lucky_index<<std::endl;
    
    
    std::cout<<"\n\n\n\n";
    
    vec.erase(vec.begin() + lucky_index);
    
    
    
    measure_time(find_missing_with_hashmaps, vec, N);
    measure_time(find_missing_with_sort, vec, N);
    
        


    


    return 0;
}
