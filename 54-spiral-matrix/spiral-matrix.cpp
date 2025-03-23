class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int top = 0;
        int left = 0;
        vector<int> res;
        bool flag = false;

        while (top <= bottom && left <= right) {
            // top row left -> right
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // right col top-> bottom
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // bottom row right -> left
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                // remaining left col bottom -> top
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};