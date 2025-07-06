/**
 * You are given two integer arrays a[] and b[] of equal size. A sum combination is 
 * formed by adding one element from a[] and one from b[], using each index pair 
 * (i, j) at most once. Return the top k maximum sum combinations, sorted in 
 * non-increasing order.
 * 
 * Examples:
 * Input: a[] = [3, 2], b[] = [1, 4], k = 2
 * Output: [7, 6]
 * Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums 
 * are 7 and 6.
 * 
 * Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
 * Output: [10, 9, 9]
 * Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 
 * 4 + 5 = 9
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumCombo(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    sort(arr1.rbegin(), arr1.rend());
    sort(arr2.rbegin(), arr2.rend());
    //Using heap
    priority_queue<pair<int, pair<int, int>>> pq;
    //Pushing the largest pair
    pq.push({arr1[0]+arr2[0], {0, 0}});
    //Using a set to avoid duplicates
    set<pair<int, int>> st;
    st.insert({0, 0});
    vector<int> ans;
    while (ans.size() < k) {
        auto top = pq.top();
        pq.pop();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        ans.push_back(sum);
        if (i + 1 < n && st.find({i+1, j}) == st.end()) {
            pq.push({arr1[i+1] + arr2[j], {i+1, j}});
            st.insert({i+1, j}); 
        } 
        if (j + 1 < n && st.find({i, j+1}) == st.end()) {
            pq.push({arr1[i] + arr2[j+1], {i, j+1}});
            st.insert({i, j+1});
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements in each array: ";
    cin >> n;

    vector<int> arr1;
    vector<int> arr2;

    cout << "Enter the elements in the first array : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr1.push_back(temp);
    }

    cout << "Enter the elements in the second array : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    vector<int> ans = maxSumCombo(arr1, arr2, k);

    for(int i=0;i<k;i++) {
        cout << ans[i] << " ";
    }

    return 0;
}