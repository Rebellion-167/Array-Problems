/**
 * You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The 
 * ith event starts at startDayi and ends at endDayi, and if you attend this event, you 
 * will receive a value of valuei. You are also given an integer k which represents the 
 * maximum number of events you can attend.
 * 
 * You can only attend one event at a time. If you choose to attend an event, you must 
 * attend the entire event. Note that the end day is inclusive: that is, you cannot 
 * attend two events where one of them starts and the other ends on the same day.
 * 
 * Return the maximum sum of values that you can receive by attending events.
 * 
 * Examples:
 * 
 * Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
 * Output: 7
 * Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value 
 * of 4 + 3 = 7.
 * 
 * Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
 * Output: 10
 * Explanation: Choose event 2 for a total value of 10.
 * Notice that you cannot attend any other event as they overlap, and that you do not 
 * have to attend k events.
 * 
 * Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
 * Output: 9
 * Explanation: Although the events do not overlap, you can only attend 3 events. Pick 
 * the highest valued three.
 */
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<vector<int>>& events, int target) {
    int low = 0, high = events.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(events[mid][1] < target) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = events.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for(int i=1;i<=n;i++) {
        int prev = binarySearch(events, events[i-1][0]);

        for(int j=1;j<=k;j++) {
            dp[i][j] = max(dp[i-1][j], dp[prev+1][j-1] + events[i-1][2]);
        }
    }

    return dp[n][k];
}

int main() {
    int n;
    cout << "Enter the number of events : ";
    cin >> n;

    vector<vector<int>> events;

    cout << "Enter the details of the events : ";
    for(int i=0;i<n;i++) {
        vector<int> tempo;
        for(int j=0;j<3;j++) {
            int temp;
            cin >> temp;
            tempo.push_back(temp);
        }
        events.push_back(tempo);
    }

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int value = maxValue(events, k);

    cout << value << endl;

    return 0;
}

/**
 * Time Complexity : O(N log N + NK + N log N)
 * Reason : Sorting + DP filling + Binary Search
 * 
 * Space Complexity : O(NK) for the DP table
 */