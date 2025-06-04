/**
 * Given an array arr of integers, find all the elements that occur more than once 
 * in the array. If no element repeats, return an empty array.
 * 
 * Examples:
 * 
 * Input: arr[] = [2, 3, 1, 2, 3]
 * Output: [2, 3] 
 * Explanation: 2 and 3 occur more than once in the given array.
 * 
 *  Input: arr[] = [0, 3, 1, 2] 
 * Output: [] 
 * Explanation: There is no repeating element in the array, so the output is empty.
 * 
 * Input: arr[] = [2]
 * Output: [] 
 * Explanation: There is single element in the array. Therefore output is empty.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();

    //Edge Case : If there is only element, it will return empty
    if(n==1)
        return {};

    //Sorting the array to keep the duplicates together
    sort(nums.begin(), nums.end());

    vector<int> ans; // To store duplicate elements

    //Iterating through the sorted array, finding duplicates and storing it in another storage structure
    for(int i=1;i<n;i++)
    {
        if(nums[i] == nums[i-1])
            ans.push_back(nums[i]);
    }

    return ans;

}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter elements in the array : ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> dup = findDuplicates(arr);

    cout << "The duplicate elements are : ";
    for(int i=0;i<dup.size();i++)
        cout << dup[i] << " ";

    return 0;
}