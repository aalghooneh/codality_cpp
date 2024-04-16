

// finding the pairs in a list

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>




void find_pairs_in_list(std::vector<int> vec){
    
    std::set<int> myset(vec.begin(), vec.end());
    std::unordered_map<int, std::vector<int>> found_duplicates;
    
    
    for (int i =0 ; i<vec.size() ; i++){
        
        if (myset.find(vec[i]) != myset.end()){
        
            found_duplicates[vec[i]].push_back(i);
            
        }
    }
    
    for(auto elem : found_duplicates){
        if ( (elem.second.size()&1) != 0 ){
            std::cout<<"this is the lone element "<<elem.first<<std::endl;
        }
    }
    
}


int main(){
    std::vector<int> vec = {1,2,1,2,3,4,5,4,5};
    
    find_pairs_in_list(vec);
    
    
    return 0;
}
