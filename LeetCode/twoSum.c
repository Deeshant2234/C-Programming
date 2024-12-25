/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int n1;
    int* indexArr = (int*)malloc(2*sizeof(int));
    for(int i =0; i<numsSize; i++)
    {
        n1 = target-nums[i];
        for(int j=0;j<numsSize;j++)
        {
            if(n1==nums[j]){
                indexArr[0]=i;
                indexArr[1]=j;
                return indexArr;
            }
        }
    }
    return NULL;
}

int main()
{
    int arr[] = {3,2,4};
    int size = 3;
    int target = 7;
    int *indexArr = twoSum(arr,size,target);
    printf("%d",indexArr[0]);
    printf("%d",indexArr[2]);
}