/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Example 1:

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```
Example 2:

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```
Example 3:

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

```
 
Constraints:

- 1 <= nums.length <= 1000
- -10^6 <= nums[i] <= 10^6

Algorithm:
```
every number in the array is replaced by sum of the numbers to the left and the number at the position. So, when iterating over the array at index i, arr[i] = arr[i-1] + arr[i]. arr[i-1] has sum of all values till i-1 index and so on.
```
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i]  + nums[i-1];
        }
        return nums;
    }
};

int main(){
    Solution obj;
    vector<int> v1{1,2,3,4};
    vector<int> v2{1,1,1,1,1};
    vector<int> v3{3,1,2,10,1};

    vector<int> o1 = obj.runningSum(v1);
    vector<int> o2 = obj.runningSum(v2);
    vector<int> o3 = obj.runningSum(v3);

    for(int i: o1){
        std::cout << i << " ";
    }
    std::cout << "\n";
    for(int i: o2){
        std::cout << i << " ";
    }
    std::cout << "\n";
    for(int i: o3){
        std::cout << i << " ";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/