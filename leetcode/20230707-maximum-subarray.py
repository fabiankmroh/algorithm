class Solution:
    def maxSubArray(self, nums):
        for i in range(len(nums)):
            nums[i] = max(nums[i], nums[i] + nums[i - 1])

        return max(nums)
    
