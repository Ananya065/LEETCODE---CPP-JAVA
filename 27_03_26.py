class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m = len(mat)
        n = len(mat[0])
        
   
        shift = k % n
        if shift == 0:
            return True
            
        for i in range(m):
            original_row = mat[i]
            
            if i % 2 == 0:
           
                shifted_row = original_row[shift:] + original_row[:shift]
            else:
           
                shifted_row = original_row[-shift:] + original_row[:-shift]
            
            if shifted_row != original_row:
                return False
                
        return True
