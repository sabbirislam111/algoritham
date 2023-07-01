#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    // Sort the intervals by their start times
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
         return a[0] < b[0];
         });

    // Initialize an empty min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // For each interval in the sorted intervals
    for (auto& interval : intervals) {
        // If the start time of the interval is greater than or equal to the minimum end time in the heap, remove the minimum end time from the heap
        if (!minHeap.empty() && interval[0] >= minHeap.top()) {
            minHeap.pop();
        }

        // Add the end time of the interval to the heap
        minHeap.push(interval[1]);
    }

    // Return the size of the heap as the answer
    return minHeap.size();
}

int main() {
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << minMeetingRooms(intervals1) << endl;

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout  << minMeetingRooms(intervals2) << endl;

    return 0;
}


