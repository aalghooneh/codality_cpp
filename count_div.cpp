// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // Implement your solution here


    if (A > B ) return 0;

    if ( A==B ){
        if (A%K==0){
            return 1;
        } else{
            return 0;
        }
    }

    int m = A % K;

    if ( m == 0){
        return (B-A)/K + 1;
    } else {
        return (B-(A+(K-m)))/K + 1;
    }

    return (B - ( A + (K - A % K) )) / K + 1;

}
