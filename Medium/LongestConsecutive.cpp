/**
 * You are given an array of ‘N’ integers. You need to find the length of the longest 
 * sequence which contains the consecutive elements.
 * 
 * Example 1:
 * Input: [100, 200, 1, 3, 2, 4]
 * Output: 4
 * Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.
 * 
 * Input: [3, 8, 5, 7, 6]
 * Output: 4
 * Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr) {
    int n = arr.size();

    //Base case - If n is zero
    if(n == 0) return 0;
    int longest = 1;

    //Unordered set to store single occurence of elements
    unordered_set<int> st;

    //Storing the array in the set
    for(int i=0;i<n;i++) {
        st.insert(arr[i]);
    }

    //Searching for the first element of the consecutive series
    //and checking whether next exists
    for(auto it : st) {
        if(st.find(it-1) == st.end()) {
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int longest = longestConsecutive(arr);

    cout << "Length of longest consecutive sequence is : " << longest << endl;

    return 0;
}

/**
 * Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
 * Reason: O(N) for putting all the elements into the set data structure. 
 * After that for every starting element, we are finding the consecutive elements. 
 * Though we are using nested loops, the set will be traversed at most twice in 
 * the worst case. So, the time complexity is O(2*N) instead of O(N2).
 * 
 * Space Complexity: O(N), as we are using the set data structure to solve this problem.
 * 
 * Note: The time complexity is computed under the assumption that we are using 
 * unordered_set and it is taking O(1) for the set operations. 
 * 
 * If we consider the worst case the set operations will take O(N) in that case 
 * and the total time complexity will be approximately O(N2). 
 * And if we use the set instead of unordered_set, the time complexity for the 
 * set operations will be O(logN) and the total time complexity will be O(NlogN).
 */