/**
 * Given a matrix, your task is to rotate matrix anti-clockwise by 90 degrees.
 * 
 * Example 1:
 * Input: {{1,2,3},
 *         {4,5,6},
 *         {7,8,9}}
 * Output:
 *      3 6 9 
 *      2 5 8 
 *      1 4 7 
 * Explanation: Rotate the matrix anti-clockwise by 90 degrees and return it.
 * 
 * Example 2:
 * Input:    {{1,2,3,4},   
 *            {5,6,7,8},   
 *            {9,10,11,12},  
 *            {13,14,15,16}}
 * Output:
 *      4 8 12 16 
 *      3 7 11 15 
 *      2 6 10 14 
 *      1 5 9 13 
 * Explanation: Rotate the matrix anti-clockwise by 90 degrees and return it.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void rotateAnticlockwise(vector<vector<int>> &matrix) {
    int n = matrix.size();
    
    //Finding the transpose of the matrix
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reversing the columns of the transposed matrix
   int index = n-1;
   for(int i=0;i<n;i++) {
    for(int j=0;j<n/2;j++) {
        int temp = matrix[j][i];
        matrix[j][i] = matrix[index][i];
        matrix[index][i] = temp;
        index--;
    }
    index = n-1;
   }
}

int main() {
    int n;
    cout << "Enter the size of matrix : ";
    cin >> n;

    vector<vector<int>> matrix;

    cout << "Enter the elements row-wise: " << endl;
    for(int i=0;i<n;i++) {
        vector<int> vec;
        for(int j=0;j<n;j++) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        matrix.push_back(vec);
    }

    rotateAnticlockwise(matrix);

    cout << "The rotated matrix is : " << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix 
 * and the other is for reversing the matrix.
 * 
 * Space Complexity: O(1).
 */