/**
 * Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
 * 
 * Example 1:
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.
 * 
 * Example 2:
 * Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void rotateClockwise(vector<vector<int>> &matrix) {
    int n = matrix.size();

    //Finding the transpose of the matrix
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reversing each row of the matrix
    for(int i=0;i<n;i++) {
        //row is matrix[i]
        reverse(matrix[i].begin(), matrix[i].end());
    }

}

int main() {
    int n;
    cout << "Enter the size of the matrix : ";
    cin >> n;

    vector<vector<int>> matrix;

    cout << "Enter elements in the matrix row-wise : " << endl;
    for(int i=0;i<n;i++) {
        vector<int> vec;
        for(int j=0;j<n;j++) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        matrix.push_back(vec);
    }

    rotateClockwise(matrix);

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