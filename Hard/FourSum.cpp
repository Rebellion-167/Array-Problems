/**
 * Given an array of N integers, your task is to find unique quads that add up 
 * to give a target value. In short, you need to return an array of all the unique 
 * quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a 
 * given target.
 * 
 * Note:
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * arr[a] + arr[b] + arr[c] + arr[d] == target
 * 
 * Example 1:
 * Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
 * Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Explanation: We have to find unique quadruplets from the array such that 
 * the sum of those elements is equal to the target sum given that is 0. The 
 * result obtained is such that the sum of the quadruplets yields 0.
 * 
 * Example 2:
 * Input Format: arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9
 * Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
 * Explanation: The sum of all the quadruplets is equal to the target i.e. 9.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findQuads(vector<int> &arr, int target) {
    int n = arr.size();
    //sorting the given array to implement our algorithm
    sort(arr.begin(), arr.end());
    vector<vector<int>> quads; //to store the quads

    //Calculating the quadruplets
    for(int i=0;i<n;i++) {
        //Avoiding the duplicates while moving i
        if(i!=0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++) {
            //Avoiding the duplicates while moving j
            if(j!=i+1 && arr[j] == arr[j-1]) continue;
            //2 pointers
            int k = j+1;
            int l = n-1;
            while(k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum==target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    quads.push_back(temp);
                    k++;
                    l--;
                    //Skipping the duplicates
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                } else if(sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return quads;
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

    int target;
    cout << "Enter the target : ";
    cin >> target;

    vector<vector<int>> ans = findQuads(arr,target);

    cout << "The quadruplets are : " << endl;
    for(auto it : ans) {
        for(auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * Time Complexity: O(N^3), where N = size of the array.
 * Reason: Each of the pointers i and j, is running for approximately N times. 
 * And both the pointers k and l combined can run for approximately N times 
 * including the operation of skipping duplicates. So the total time complexity 
 * will be O(N^3). 
 * 
 * Space Complexity: O(no. of quadruplets), This space is only used to store the 
 * answer. We are not using any extra space to solve this problem. So, from that 
 * perspective, space complexity can be written as O(1).
 */