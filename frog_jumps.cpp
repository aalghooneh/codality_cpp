// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    
    if (Y < X) return 0;

    int TD = Y - X;

    int NJ = TD/D;

    if (TD%D != 0){
        return NJ + 1;
    } else{
        return NJ;
    }

}
