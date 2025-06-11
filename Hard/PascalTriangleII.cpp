/**
 * Given the row number n. Print the n-th row of Pascal’s triangle.
 * 
 * Example 1:
 * Input Format: N = 5
 * 1 4 6 4 1 (for variation 2)
 * Explanation: There are 5 rows in the output matrix. 
 * Each row is formed using the logic of Pascal’s triangle.
 * 
 * Example 2:
 * Input Format: N = 1
 * Result: 1 
 * Explanation: The output matrix has only 1 row.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> printRow(int n) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    
    for(int i=1;i<n;i++) {
        ans = ans * (n-i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

int main() {
    int n;
    cout << "Enter the row number : ";
    cin >> n;

    vector<int> res = printRow(n);

    cout << "The required row is : ";
    for(int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}