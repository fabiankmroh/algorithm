class Solution:
    def generateParenthesis(self, n):
        self.ans = []
        self.generateParenthesis('', n, n)

        return self.ans
    
    def main(self, p_string, left, right):
        if left > 0:
            self.main(p_string + '(', left - 1, right)
        if left < right:
            self.main(p_string + ')', left, right - 1)
        if right == 0:
            self.ans.append(p_string)
