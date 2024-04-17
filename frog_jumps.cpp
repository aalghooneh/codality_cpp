

#include <iostream>



int calculate_distance(int X, int Y, int D){
    
    int TD = std::abs(X - Y);

    if ( TD == 0){
        return 0;
    }
    
    if (TD < D){
        return 1;
    }
    
    int NJ = TD / D;
    
    
    
    if ( (TD % D) == 0 ){
        return NJ;
    } else {
        return NJ + 1;
    }
    
}



int main(){
    
    std::cout<<calculate_distance(20, 80, 30)<<std::endl;
    return 0;
}
