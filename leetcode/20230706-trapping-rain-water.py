class Solution:
    wall_stack = []
    def trap(self, height: List[int]) -> int:
        for i in height:
            self.wall_stack.append(i)