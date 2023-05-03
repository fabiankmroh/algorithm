# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int):
        result = []

        for i in range(len(nums)-1):
            a = nums[i]
            
            for j in range(len(nums)):
                if j == i:
                    continue

                b = nums[j]

                if a + b == target:
                    result.append(i)
                    result.append(j)
                    return result
