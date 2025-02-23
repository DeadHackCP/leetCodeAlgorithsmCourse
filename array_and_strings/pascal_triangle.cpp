#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    if (numRows == 0) return {};
    if (numRows == 1) return {{1}};
    if (numRows == 2) return {{1},{1,1}};
    vector<vector<int>> triangle = {{1}, {1,1}};
    for (size_t k = 2; k < numRows; k++)
    {
      vector<int> row(k+1);
      row[0] = 1;
      row[k] = 1;
      for (size_t i = 1; i < k; i++)
      {
        row[i] = triangle[k-1][i-1] + triangle[k-1][i];
      }
      triangle.push_back(row);
    }
    return triangle;
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
void test(int numRows, const vector<vector<int>>& expected)
{
  Solution sol;
  vector<vector<int>> result = sol.generate(numRows);
  if (result == expected)
  {
    cout << "Test passed." << endl;
  }
  else
  {
    cout << "Test failed. Expected" << endl;
    for (const auto& row : expected)
    {
      printVector(row);
      cout << endl;
    }
    cout << "but got" << endl;
    for (const auto& row : result)
    {
      printVector(row);
      cout << endl;
    }
  }
}

int main()
{
  // Test case 1: numRows = 0
  test(0, {});

  // Test case 2: numRows = 1 
  test(1, {{1}});

  // Test case 3: numRows = 2
  test(2, {{1}, {1,1}});

  // Test case 4: numRows = 3
  test(3, {{1}, {1,1}, {1,2,1}});

  // Test case 5: numRows = 4
  test(4, {{1}, {1,1}, {1,2,1}, {1,3,3,1}});

  // Test case 6: numRows = 5
  test(5, {{1}, {1,1}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1}});

  return 0;
}
