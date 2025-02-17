#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int left = 0;
    int right = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
      right = right - nums[i];
      if (right == left)
        return i;
      left = left + nums[i];
    }
    return -1;
  }
};

void test(vector<int> nums, int expected)
{
  Solution sol;
  int result = sol.pivotIndex(nums);
  if (result == expected)
  {
    cout << "Test passed." << endl;
  }
  else
  {
    cout << "Test failed. Expected " << expected << " but got " << result << endl;
  }
}

int main()
{
  test({ 1, 7, 3, 6, 5, 6 }, 3);
  test({1, 2, 3}, -1);
  test({2, 1, -1}, 0);
  test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, -1);
  test({-1, -1, -1, -1, -1, 0}, 2);
  return 0;
}
