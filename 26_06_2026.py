class Solution:
    def countMajoritySubarrays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        bit = [0] * (2 * n + 2)
        
        def update(idx: int, val: int):
            while idx < len(bit):
                bit[idx] += val
                idx += idx & -idx
                
        def query(idx: int) -> int:
            total = 0
            while idx > 0:
                total += bit[idx]
                idx -= idx & -idx
            return total
        
        prefix_sum = 0
        result = 0
        
        update(0 + n + 1, 1)
        
        for num in nums:
            if num == target:
                prefix_sum += 1
            else:
                prefix_sum -= 1
                
            result += query(prefix_sum + n)
            update(prefix_sum + n + 1, 1)
            
        return result
