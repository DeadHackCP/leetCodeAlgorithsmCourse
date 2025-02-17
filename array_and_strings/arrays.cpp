#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    // 1. initialize
    vector<int> v0;
    vector<int> v1(5, 0);
    // 2. make a copy
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);
    // 3. cast an array to a vector
    int a[5] = {0, 1, 2, 3, 4};
    vector<int> v4(a, *(&a + 1));
    // 4. get length
    cout << "The size of v4 is: " << v4.size() << endl;
    // 5. access element
    cout << "The first element in v4 is: " << v4[0] << endl;
    // 6. iterate the vector
    cout << "[Version 1] The contents of v4 are:";
    for (int i = 0; i < v4.size(); ++i) {
        cout << " " << v4[i];
    }
    cout << endl;
    cout << "[Version 2] The contents of v4 are:";
    for (int& item : v4) {
        cout << " " << item;
    }
    cout << endl;
    cout << "[Version 3] The contents of v4 are:";
    for (auto item = v4.begin(); item != v4.end(); ++item) {
        cout << " " << *item;
    }
    cout << endl;
    // 7. modify element
    v4[0] = 5;
    // 8. sort
    sort(v4.begin(), v4.end());
    // 9. add new element at the end of the vector
    v4.push_back(-1);
    // 10. delete the last element
    v4.pop_back();
}