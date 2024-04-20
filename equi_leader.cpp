#include <algorithm>
#include <limits.h>
int solution(vector<int> &A) {
    // Implement your solution here
    int N = A.size();
    std::vector<int> decoy = A;
    
    std::sort(decoy.begin(), decoy.end());
    int leader;
    int candid = decoy[N/2];
    int count = 0;
    for (int i = 0 ; i < N ; i++){
        if (A[i] == candid ) count++;
    }
    if (count > N/2){
        leader = candid;
    } else {
        // you don't have a leader in the first
        return 0;
    }


    count = 0;
    std::vector<int> pref(N+1,0);
    for (int i = 1 ; i < (N+1) ; i++){
        if (A[i-1]==leader){
            count++;
        }
        pref[i] = count;
    }

    int eq_l = 0;
    for (int e = 0 ; e < N ; e++){
        if ( ((pref[e+1] - pref[0]) > (e+1)/2) && ((pref[N] - pref[e+1]) > (N-1-e)/2) ){

            eq_l++;
        }
    }
    return eq_l;
}
