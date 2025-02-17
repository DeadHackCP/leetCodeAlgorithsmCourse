#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
  int dominantIndex(vector<int> &nums)
  {
    auto largest = max_element(nums.begin(), nums.end());
    int largest_index = distance(nums.begin(), largest);
    int largest_element = nums[largest_index];
    nums[largest_index] = -1;
    auto second_largest = max_element(nums.begin(), nums.end());
    int second_largest_index = distance(nums.begin(), second_largest);
    return largest_element >= 2 * nums[second_largest_index] ? largest_index : -1;
  }
};

void test(vector<int> nums, int expected)
{
  Solution sol;
  int result = sol.dominantIndex(nums);
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
  test({ 3,6,1,0 }, 1);
  test({1,2,3,4}, -1);
  test({1,0}, 0);
  test({0,0,3,2}, -1);
  return 0;
}
