#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
    {
      if (*it == 9)
        *it = 0;
      else
      {
        *it = *it + 1;
        break;
      }
    }
    if (digits[0] == 0) digits.insert(digits.begin(), 1);
    return digits;
  }
};

void test(vector<int> digits, vector<int> expected)
{
  Solution sol;
  vector<int> result = sol.plusOne(digits);
  if (result == expected)
  {
    cout << "Test passed." << endl;
  }
  else
  {
    cout << "Test failed. Expected ";
    for (int num : expected)
    {
      cout << num << " ";
    }
    cout << "but got ";
    for (int num : result)
    {
      cout << num << " ";
    }
    cout << endl;
  }
}

int main()
{
  test({ 1, 7, 3, 6, 5, 6 }, {1,7,3,6,5,7});
  test({9,9,9}, {1,0,0,0});
  return 0;
}
