/**
 * You are given an array arr[] of non-negative numbers. Each number tells you the 
 * maximum number of steps you can jump forward from that position.
 * 
 * For example:
 * 
 * If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
 * If arr[i] = 0, you cannot jump forward from that position.
 * 
 * Your task is to find the minimum number of jumps needed to move from the first 
 * position in the array to the last position.
 * 
 * Note:  Return -1 if you can't reach the end of the array.
 * 
 * Examples : 
 * Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
 * Output: 3 
 * Explanation: First jump from 1st element to 2nd element with value 3. From here we 
 * jump to 5th element with value 9, and from here we will jump to the last. 
 * 
 * Input: arr = [1, 4, 3, 2, 6, 7]
 * Output: 2 
 * Explanation: First we jump from the 1st to 2nd element and then jump to the last 
 * element.
 * 
 * Input: arr = [0, 10, 20]
 * Output: -1
 * Explanation: We cannot go anywhere from the 1st element.
 */

#include <bits/stdc++.h>
using namespace std;

int countJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    if(arr[0] == 0) return -1;

    int jumps = 0;
    int maxReach = 0;
    int lastIndex = 0;

    for(int i=0;i < n- 1;i++) {
        maxReach = max(maxReach, i+arr[i]);
        if (i == lastIndex) {
            jumps++;
            lastIndex = maxReach;
            if (lastIndex >= n - 1) break;
            if (lastIndex == i) return -1; //stuck, can't move forward
        }
    }
    return (lastIndex >= n - 1) ? jumps : -1;
}

int main() {
    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the maximum number of steps for each jump : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int cnt = countJumps(arr);

    cout << cnt << endl;

    return 0;
}

/**
 * Time Complexity : O(n) where n is the length of the string
 * Space Complexity : O(1)
 */