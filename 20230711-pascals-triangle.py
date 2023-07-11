class Solution(object):
    def generate(self, numRows):
        ans = [[1]]

        for i in range(1, numRows):
            curr = [1]
            j = 1

            while j < i:
                curr.append(prev[j-1] + prev[j])
                j += 1

            curr.append(1)
            ans.append(curr)
            prev = curr
        return ans