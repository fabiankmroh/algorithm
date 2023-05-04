class Solution:
    def isin(letter, comp_str):
        for i in range(len(comp_str)):
            if comp_str[i] == letter:
                return True
            
        return False

    def lengthOfLongestSubstring(s: str) -> int:
        if s == " " or len(s) == 1:
            return 1
        
        max_conti_arr = '' # Longest Sub-string w/o Repetition
        letter_tmparr = '' 

        for i in range(len(s)-1):
            print(i, s[i])
            # Initialization
            letter_tmparr = s[i]
            # print("Init:", letter_tmparr)

            for j in range(1, len(s)-i):
                # print("j:", j, s[i+j])
                if Solution.isin(s[i+j], letter_tmparr): # Kill Sequence: End of Non-Repetition
                    if len(letter_tmparr) > len(max_conti_arr):
                        max_conti_arr = letter_tmparr
                    break
                else: 
                    # print("False")
                    letter_tmparr += s[i+j]
                    # print("Add:", letter_tmparr)

            # print("-----")

            if len(letter_tmparr) > len(max_conti_arr):
                max_conti_arr = letter_tmparr

        print(max_conti_arr)
        return len(max_conti_arr)
    
    def __init__(self):
        s = input()
        print(Solution.lengthOfLongestSubstring(s))

Solution()