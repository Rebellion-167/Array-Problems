/**
 * Given an array of integers arr[] and an integer target.
 * Return indices of the two numbers such that their sum is equal to the target. 
 * Otherwise, we will return {-1, -1}.
 * 
 * Note: You are not allowed to use the same element twice. Example: If the target 
 * is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
 * 
 * Example 1:
 * Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
 * Result: [1, 3]
 * Explanation: arr[1] + arr[3] = 14. So, the answer is [1, 3]
 * 
 * Example 2:
 * Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
 * Result: [-1, -1]
 * Explanation: There exist no such two numbers whose sum is equal to the target.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSumPointer(int n, vector<int> &arr, int target)
{
    //Storing value and original index
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++)
        v.push_back({arr[i], i});
    
    sort(v.begin(), v.end()); //sorting the original array by value
    int left = 0, right = n-1;
    pair<int, int> p;
    while(left < right)
    {
        int sum = v[left].first + v[right].first;
        if(sum == target)
            return {v[left].second, v[right].second};
        else if(sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int target;
    cout << "Enter the target : ";
    cin >> target;

    pair<int, int> p = twoSumPointer(n,arr,target);

    cout << "The pair is : [" << p.first << "," << p.second << "]" <<endl;

    return 0;
}

/**
 * Time Complexity: O(N log N) where N=size of the array
 * Space Complexity : O(N)
 */