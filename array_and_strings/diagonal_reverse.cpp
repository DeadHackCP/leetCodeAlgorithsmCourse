#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat)
  {
    if (mat.empty() || mat[0].empty())
      return {}; // Handle edge case

    int m = mat.size();    // Number of rows
    int n = mat[0].size(); // Number of columns
    vector<int> result;

    for (int diag = 0; diag < m + n - 1; ++diag)
    {   
      // Determine the starting point of the current diagonal
      int row = (diag < n) ? 0 : diag - n + 1;
      int col = (diag < n) ? diag : n - 1;

      // Collect elements in the current diagonal
      vector<int> diagonalElements;
      while (row < m && col >= 0)
      {
        diagonalElements.push_back(mat[row][col]);
        ++row;
        --col;
      }

      // Reverse the diagonal if needed (based on its index)
      if (diag % 2 == 0)
        reverse(diagonalElements.begin(), diagonalElements.end());

      // Append the diagonal elements to the result
      result.insert(result.end(), diagonalElements.begin(), diagonalElements.end());
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
  vector<int> result = sol.findDiagonalOrder(mat);
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
  test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 4, 7, 5, 3, 6, 8, 9});
  test({{1, 2}, {3, 4}}, {1, 2, 3, 4});
  test({{1}}, {1});
  test({{1, 2, 3, 4}}, {1, 2, 3, 4});
  test({{1}, {2}, {3}, {4}}, {1, 2, 3, 4});
  return 0;
}