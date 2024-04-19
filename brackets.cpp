#include <unordered_map>
#include <vector>
int solution(string &S) {
    if (S.empty()) return 1;

    std::unordered_map<char, char> mymap;

    mymap = {{'{','}'}, {'(',')'}, {'[',']'}};




    for (auto pair : mymap){
        if (S[0] == pair.second){
            return 0;
        }
    }


    std::vector<int> stack;

    int L = S.length();
    for (int i = 0 ; i<L ; i++){
        if (mymap.find(S[i]) != mymap.end()){
            stack.push_back(S[i]);
        } else if ( (stack.size() == 0) || (mymap[stack.back()] != S[i])){
            return 0;
        } else {
            stack.pop_back();
        }

    }

    return 1 ? stack.size()==0 : 0;
    
