# https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution:
    def findMedianSortedArrays(nums1, nums2):
        nums = nums1 + nums2
    
        # Sort the concatenated list
        nums.sort()
        
        # Calculate the median
        n = len(nums)
        if n % 2 == 0:
            median = (nums[n//2-1] + nums[n//2]) / 2
        else:
            median = nums[n//2]
        
        return median
        
    def __init__(self):
        nums1 = [int(x) for x in input().split()]
        nums2 = [int(x) for x in input().split()]

        print(Solution.findMedianSortedArrays(nums1, nums2))

Solution()