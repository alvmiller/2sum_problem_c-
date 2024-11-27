#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

// 2Sum problem
// https://www.geeksforgeeks.org/2sum/

using namespace std;

void sum2_brute_force(const vector<int> &arr, int target)
{
    int n = arr.size();
  
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: " << arr[i] << " , " << arr[j] << endl;
                return;
            }
        }
    }
    cout << "No pair found" << endl;
    
    return;
}

void sum2_hashing(const vector<int> &arr, int target)
{
    unordered_set<int> s = {};

    for (int i = 0; i < arr.size(); ++i) {
        int complement = target - arr[i];
        if (s.find(complement) != s.end()) {
            cout << "Pair found: " << arr[i] << " , " << complement << endl;
            return;
        }
        s.insert(arr[i]);
    }
    cout << "No pair found" << endl;
    
    return;
}

void sum2_sort_ptrs(const vector<int> &arr, int target)
{
    vector<int> arr_tmp(arr);
    sort(begin(arr_tmp), end(arr_tmp));
    
    int left = 0;
    int right = arr_tmp.size() - 1;

    while (left < right) {
        int sum = arr_tmp[left] + arr_tmp[right];
        if (sum == target) {
            cout << "Pair found: " << arr_tmp[left] << " , " << arr_tmp[right] << endl;
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    cout << "No pair found" << endl;
    
    return;
}

int main()
{
    vector<int> v = { 1, -2, -3, 4, 3, 8 };
    for_each( v.begin(), v.end(), [](int i) { cout << i << " "; } );
    cout << endl;
    
    sum2_brute_force(v, 0);
    sum2_hashing(v, 0);
    sum2_sort_ptrs(v, 0);
    
    for_each( v.begin(), v.end(), [](int i) { cout << i << " "; } );
    cout << endl;

    return 0;
}
