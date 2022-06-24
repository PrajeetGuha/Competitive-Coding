/*
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.

Example 1:

```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

```
Example 2:

```
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```
Example 3:

```
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

```
 

Constraints:

- 1 <= nums.length <= 104
- -1000 <= nums[i] <= 1000
 

Algorithm:

```
Here first we find the sum of the total array. Then we iterate over the array and at each iteration we subtract the number at which the iteration instance is from the total sum and at the end of the iteration we add this number to the left sum. Between the subtraction of the number from total sum and addition to left sum, the number is neither in the total sum(techically the right sum) and the left sum. So, at this instance we check if left sum is equal to right sum or not. We do this at each iteratio and if not found then sed -1 as result.
```
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum = sum + i;
        }
        
        int left_sum = 0;
        for(int i = 0; i < nums.size(); i++ ){
            sum = sum - nums[i];
            if ( left_sum == sum ){
                return i;
            }
            else{
                left_sum = left_sum + nums[i];
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<int> v1{1,7,3,6,5,6};
    vector<int> v2{1,2,3};
    vector<int> v3{2,1,-1};

    int o1 = obj.pivotIndex(v1);
    int o2 = obj.pivotIndex(v2);
    int o3 = obj.pivotIndex(v3);

    std::cout << o1 << " " << o2 << " " << o3 << endl;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/