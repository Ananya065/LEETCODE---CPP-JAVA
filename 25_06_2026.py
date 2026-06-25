class Solution:
    def countMajoritySubarrays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        offset = n + 2
        bit = [0] * (2 * n + 5)
        
        def update(idx, val):
            while idx < len(bit):
                bit[idx] += val
                idx += idx & (-idx)
                
        def query(idx):
            s = 0
            while idx > 0:
                s += bit[idx]
                idx -= idx & (-idx)
            return s
            
        count = 0
        prefix = 0
        update(0 + offset, 1)
        
        for num in nums:
            prefix += 1 if num == target else -1
            count += query(prefix + offset - 1)
            update(prefix + offset, 1)
            
        return count
