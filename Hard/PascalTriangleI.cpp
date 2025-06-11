/**
 * Given row number r and column number c. Print the element at position (r, c) 
 * in Pascal’s triangle.
 * 
 * Example 1:
 * Input Format: N = 5, r = 5, c = 3
 * Result: 6
 * Explanation: There are 5 rows in the output matrix. 
 * Each row is formed using the logic of Pascal’s triangle.
 * 
 * Example 2:
 * Input Format: N = 1, r = 1, c = 1
 * Result: 1
 * Explanation: The output matrix has only 1 row.
 */

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    for(int i=0;i<r;i++) {
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

int main() {
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;

    int r,c;
    cout << "Enter the position : ";
    cin >> r >> c;

    int pos = nCr(r-1,c-1);

    cout << "The element at " << r << ", " << c << " is : " << pos << endl;
    return 0;
}