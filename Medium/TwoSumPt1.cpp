/**
 * Given an array of integers arr[] and an integer target.
 * 
 *  Return YES if there exist two numbers such that their sum is equal 
 * to the target. Otherwise, return NO.
 * 
 * You are not allowed to use the same element twice. Example: If the target 
 * is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
 * 
 * Example 1:
 * Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
 * Result: YES
 * Explanation: arr[1] + arr[3] = 14. So, the answer is “YES”
 * 
 * Example 2:
 * Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
 * Result: NO
 * Explanation: There exist no such two numbers whose sum is equal to the target.
 */

#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
    {
        int num1 = arr[i];
        int num2 = target - num1;

        if(m.find(num2) != m.end())
        {
            return "YES";
        }
        m[num1] = i;
    }
    return "NO";
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

    string result = twoSum(n, arr, target);

    cout << result << endl;

    return 0;
}