class Solution:
    def findTheString(self, lcp: list[list[int]]) -> str:
        n = len(lcp)
        word = [None] * n
        char_idx = 0
        
        for i in range(n):
            if word[i] is not None:
                continue
            if char_idx >= 26:
                return ""
            
            curr_char = chr(ord('a') + char_idx)
            char_idx += 1
            
            for j in range(i, n):
                if lcp[i][j] > 0:
                    word[j] = curr_char
        
        if None in word:
            return ""
        
        res = "".join(word)
        
      
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                expected = 0
                if res[i] == res[j]:
                    expected = 1
                    if i + 1 < n and j + 1 < n:
                        expected += lcp[i+1][j+1]
                
                if lcp[i][j] != expected:
                    return ""
                    
        return res
