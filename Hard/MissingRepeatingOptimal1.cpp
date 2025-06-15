/**
 * You are given a read-only array of N integers with values also in the range 
 * [1, N] both inclusive. Each integer appears exactly once except A which appears 
 * twice and B which is missing. The task is to find the repeating and missing 
 * numbers A and B where A repeats twice and B is missing.
 * 
 * Example 1:
 * Input Format:  array[] = {3,1,2,5,3}
 * Result: {3,4}
 * Explanation: A = 3 , B = 4 
 * Since 3 is appearing twice and 4 is missing
 * 
 * Example 2:
 * Input Format: array[] = {3,1,2,5,4,6,7,5}
 * Result: {5,8)
 * Explanation: A = 5 , B = 8 
 * Since 5 is appearing twice and 8 is missing
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findNumbers(vector<int> &arr) {
    int n = arr.size();
    //S - Sn
    //S2 - S2n
    //sum of first n natural numbers
    long long Sn = (n * (n+1)) / 2; 
    //sum of squares of first n natural numbers
    long long S2n = (n * (n+1) * (2*n+1)) / 6; 

    //Calculating S and S2
    long long S = 0, S2 = 0;
    for(int i=0;i<n;i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    
    //S - Sn = X - Y
    long long val1 = S - Sn;

    //S2 - S2n = X^2 - Y^2
    long long val2 = S2 - S2n;

    //Finding X+Y = (X^2 - Y^2)/(X - Y)
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    //Here, X-Y = val1 and X+Y = val2
    long long X = (val1 + val2) / 2;
    long long Y = X - val1;

    return {(int)X, (int)Y};
}

int main() {
    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> nums = findNumbers(arr);

    cout << "The repeating number is : " << nums[0] << endl;
    cout << "The missing number is : " << nums[1] << endl;

    return 0;
}

/**
 * Time Complexity: O(N), where N = the size of the given array.
 * Reason: We are using only one loop running for N times. So, the time complexity 
 * will be O(N).
 * 
 * Space Complexity: O(1) as we are not using any extra space to solve this problem.
 */