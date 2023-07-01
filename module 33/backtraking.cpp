#include<bits/stdc++.h>
using namespace std;

/*
backtrack(state){
    if(solution-found(state){
        - add state to answer
        - return
       }
       for all valid candidates:
        - add candidate to state
        - backtrack(state)
        - remove candidate from state
}


*/

int n;
vector<vector<int>>ans;

bool solution_found(int id, vector<int>state){
    if(id == n){
        return true;
    }
    return false;
}

vector<int> get_candidate(vector<int> state){
    map<int, int> take;
    for(int x: state){
        take[x] = 1;
    }
    vector<int>candidates;
    for(int i = 1; i<=n; i++){
        if(take.count(i)== 0){
            candidates.push_back(i);
        }
    }
    return candidates;
}

void backtrack(int id, vector<int> state){
    //  base case handling
    if(solution_found(id, state)){
        ans.push_back(state);
        return;
    }

    // loop over the candidate
    vector<int>candidates = get_candidate(state);
    for(int candidate: candidates){
        // add candidate from state
        state[id] = candidate;
        // backtrack(state)
        backtrack(id+1, state);
        // remove candidate from state
        state[id] = 0;
    }



}



int main(){

cin>>n;
vector<int> initial_state;


backtrack(0, initial_state);

for(vector<int> permutation: ans){
    for(int x:permutation){
        cout<< x <<" ";
    }
    cout<<endl;
}

 return 0;
}
