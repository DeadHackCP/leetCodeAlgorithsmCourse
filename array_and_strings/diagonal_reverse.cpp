#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat)
  {
    vector<int> diagonalTraverse;
    diagonalTraverse.push_back(mat[0][0]);
    vector<int> coordinates = {0, 0};
    bool reach_limit = false;
    for (size_t k = 1; k <= 2 * mat.size() - 2; k++)
    {
      int limit_cycle = !reach_limit ? k : mat.size() - (k - mat.size());
      for (size_t m = 1; m <= limit_cycle; m++)
      {
        if (m == limit_cycle)
        {
          if (k == mat.size())
            reach_limit = !reach_limit;
          if (!reach_limit)
            coordinates[m % 2] = coordinates[m % 2] + 1;
          else
            coordinates[!(m % 2)] = coordinates[!(m % 2)] + 1;

          diagonalTraverse.push_back(mat[coordinates[0]][coordinates[1]]);
        }
        else
        {
          coordinates[0] = coordinates[0] + (k % 2 ? -1 : 1);
          coordinates[1] = coordinates[1] - (k % 2 ? -1 : 1);
          diagonalTraverse.push_back(mat[coordinates[0]][coordinates[1]]);
        }
      }
    }
    return diagonalTraverse;
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