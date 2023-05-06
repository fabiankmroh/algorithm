def longest_palindrome(s):
    if len(s) < 2:
        return s

    start = 0
    max_len = 0

    for i in range(len(s)):
        # Check odd length palindromes
        left = i
        right = i
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if right - left + 1 > max_len:
                max_len = right - left + 1
                start = left
            left -= 1
            right += 1

        # Check even length palindromes
        left = i
        right = i + 1
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if right - left + 1 > max_len:
                max_len = right - left + 1
                start = left
            left -= 1
            right += 1

    return s[start:start + max_len]

# Example usage
string = "cbbd"
print(longest_palindrome(string))  # Output: "bab"
