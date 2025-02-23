#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> result;
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse from left to right along the top row
            for (int j = left; j <= right; ++j)
                result.push_back(matrix[top][j]);
            ++top; // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            --right; // Move the right boundary left

            // Traverse from right to left along the bottom row (if any rows remain)
            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                    result.push_back(matrix[bottom][j]);
                --bottom; // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if any columns remain)
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                ++left; // Move the left boundary right
            }
        }

        return result;
    }
};

void printVector(const vector<int> &vec)
{
  cout << "[";
  for (size_t i = 0; i < vec.size(); ++i)
  {
    cout << vec[i];
    if (i != vec.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << "]";
}

void test(vector<vector<int>> mat, vector<int> expected)
{
  Solution sol;
  vector<int> result = sol.spiralOrder(mat);
  if (result == expected)
  {
    cout << "Test passed." << endl;
  }
  else
  {
    cout << "Test failed. Expected ";
    printVector(expected);
    cout << " but got ";
    printVector(result);
    cout << endl;
  }
}

int main()
{
  // Test case 1: Empty matrix
  test({}, {});

  // Test case 2: Single element matrix
  test({{1}}, {1});

  // Test case 3: Single row matrix
  test({{1, 2, 3}}, {1, 2, 3});

  // Test case 4: Single column matrix
  test({{1},
        {2},
        {3}},
       {1, 2, 3});

  // Test case 5: 2x2 matrix
  test({{1, 2},
        {3, 4}},
       {1, 2, 4, 3});

  // Test case 6: 3x3 matrix
  test({{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}},
       {1, 2, 3, 6, 9, 8, 7, 4, 5});

  // // Test case 7: 3x4 matrix
  test({{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}},
       {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7});

  // // Test case 8: 4x3 matrix
  test({{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}},
       {1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8});

  // Test case 9: Custom matrix
  test({{2, 5},
        {8, 4},
        {0, -1}},
       {2, 5, 4, -1, 0, 8});
  // return 0;
}
