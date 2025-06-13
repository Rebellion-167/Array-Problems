/**
 * Given an array of intervals, merge all the overlapping intervals and return 
 * an array of non-overlapping intervals.
 * 
 * Example 1: 
 * Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge 
 * them to form [1,6]intervals.
 * 
 * Example 2:
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge 
 * them to form [1,5].
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlaps(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); //Sorting the given array of arrays
    vector<vector<int>> ans; //To store the merged intervals

    for(int i=0;i<n;i++) {
        //if the current interval does not
        //lie in the last interval
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } 
        //if the current interval lies
        //in the last interval
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of intervals : ";
    cin >> n;

    vector<vector<int>> arr;

    cout << "Enter the intervals : " << endl;
    for(int i=0;i<n;i++) {
        vector<int> tempo;
        for(int j=0;j<2;j++) {
            int temp;
            cin >> temp;
            tempo.push_back(temp);
        }
        arr.push_back(tempo);
    }

    vector<vector<int>> ans = mergeOverlaps(arr);

    cout << "The merged intervals are : " << endl;
    for(auto it : ans) {
        for(auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
 * Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after 
 * that, we are just using a single loop that runs for N times. So, the time 
 * complexity will be O(N).
 * 
 * Space Complexity: O(N), as we are using an answer list to store the merged 
 * intervals. Except for the answer array, we are not using any extra space.
 */