#include <algorithm>
#include <numeric>
int solution(int K, int M, vector<int> &A) {

    int MAX = *std::max_element(A.begin(), A.end());

    int SUM=std::accumulate(A.begin(), A.end(),0);
    auto canpartition = [&](int largest_sum){
        int blocks=1;
        int current_sum = 0;
        for (auto a : A){
            current_sum+=a;
            if (current_sum > largest_sum){
                blocks++;
                current_sum=a;

                if (blocks > K){
                    return false;
                }
            }
        }

        return true;

    };

    int low = MAX;
    int high = SUM;

    while (low < high){
        int mid = (low+high)/2;
        if ( canpartition(mid) ) {
            high = mid;
        } else {
            low = mid+1;
        }
    }

    return low;


}
