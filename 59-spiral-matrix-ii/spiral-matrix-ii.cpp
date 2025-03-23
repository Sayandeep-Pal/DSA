class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int bottom = n-1;
        int right = n-1;
        int top = 0;
        int left = 0;
        int count =1;

        while (top <= bottom && left <= right) {
            // top row left -> right
            for (int i = left; i <= right; i++) {
                matrix[top][i] = count;
                count++;
            }
            top++;

            // right col top-> bottom
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = count;
                count++;
            }
            right--;

            if (top <= bottom) {
                // bottom row right -> left
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = count;
                    count++;
                }
                bottom--;
            }

            if (left <= right) {
                // remaining left col bottom -> top
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = count;
                    count++;
                }
                left++;
            }
        }

        return matrix;
    }
};