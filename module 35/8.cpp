#include <bits/stdc++.h>
using namespace std;

bool can_attend_all_meetings(vector<vector<int>>& intervals) {
    // Sort the intervals by their start times
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });

    // Initialize end_time to 0
    int end_time = 0;

    // Check for overlaps
    for (vector<int>& interval : intervals) {
        if (interval[0] < end_time) {
            // There is an overlap, so return false
            return false;
        } else {
            // Update end_time
            end_time = interval[1];
        }
    }

    // All meetings can be attended, so return true
    return true;
}

int main() {
    // Example usage
    vector<vector<int>> intervals1 = {{0, 6}, {5, 10}, {15, 20}};
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};

    if(!can_attend_all_meetings(intervals2)){
        cout<<"False"<<endl;
    }
    else{
        cout<<"True"<<endl;
    }


    return 0;
}

