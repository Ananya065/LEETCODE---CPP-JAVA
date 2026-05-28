class Solution:
    def stringIndices(self, wordsContainer: list[str], wordsQuery: list[str]) -> list[int]:
        global_best_idx = 0
        min_len = len(wordsContainer[0])
        
        for i in range(1, len(wordsContainer)):
            curr_len = len(wordsContainer[i])
            if curr_len < min_len:
                min_len = curr_len
                global_best_idx = i
        
        trie = {'idx': global_best_idx}
        
        for idx, word in enumerate(wordsContainer):
            curr = trie
            word_len = len(word)
            
            for char in reversed(word):
                if char not in curr:
                    curr[char] = {'idx': idx}
                curr = curr[char]
                
                best_so_far = curr['idx']
                if word_len < len(wordsContainer[best_so_far]):
                    curr['idx'] = idx
                elif word_len == len(wordsContainer[best_so_far]) and idx < best_so_far:
                    curr['idx'] = idx

        ans = []
        for query in wordsQuery:
            curr = trie
            for char in reversed(query):
                if char in curr:
                    curr = curr[char]
                else:
                    break
            ans.append(curr['idx'])
            
        return ans
