class Solution:
    wall_stack = []
    def trap(self, height: List[int]) -> int:
        for i in height:
            self.wall_stack.append(i)
            size = len(self.wall_stack)
            
            if i > wall_stack[size]:
                