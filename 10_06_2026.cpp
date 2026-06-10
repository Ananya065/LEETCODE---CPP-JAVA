from collections import deque

class Solution:
    def maxTotalValue(self, nums: list[int], k: int) -> int:
        n = len(nums)
        
        def countSubarrays(X: int) -> int:
            count = 0
            max_dq = deque()
            min_dq = deque()
            l = 0
            
            for r in range(n):
                while max_dq and nums[max_dq[-1]] <= nums[r]:
                    max_dq.pop()
                while min_dq and nums[min_dq[-1]] >= nums[r]:
                    min_dq.pop()
                    
                max_dq.append(r)
                min_dq.append(r)
                
                while max_dq and min_dq and (nums[max_dq[0]] - nums[min_dq[0]] >= X):
                    count += (n - r)
                    if max_dq[0] == l:
                        max_dq.popleft()
                    if min_dq[0] == l:
                        min_dq.popleft()
                    l += 1
            return count

        low, high = 0, 10**9
        threshold = 0
        while low <= high:
            mid = (low + high) // 2
            if countSubarrays(mid) >= k:
                threshold = mid
                low = mid + 1
            else:
                high = mid - 1

        target = threshold + 1
        
        max_dq = deque()
        min_dq = deque()
        l = 0
        valid_count = 0
        valid_L = [-1] * n
        
        for r in range(n):
            while max_dq and nums[max_dq[-1]] <= nums[r]:
                max_dq.pop()
            while min_dq and nums[min_dq[-1]] >= nums[r]:
                min_dq.pop()
                
            max_dq.append(r)
            min_dq.append(r)
            
            while max_dq and min_dq and (nums[max_dq[0]] - nums[min_dq[0]] >= target):
                if max_dq[0] == l:
                    max_dq.popleft()
                if min_dq[0] == l:
                    min_dq.popleft()
                l += 1
            
            valid_L[r] = l - 1
            valid_count += l

        pref_valid_L = [0] * (n + 1)
        for i in range(n):
            pref_valid_L[i + 1] = pref_valid_L[i] + valid_L[i]

        left_max = [-1] * n
        right_max = [n] * n
        stk = []
        for i in range(n):
            while stk and nums[stk[-1]] <= nums[i]:
                right_max[stk.pop()] = i
            if stk:
                left_max[i] = stk[-1]
            stk.append(i)
            
        left_min = [-1] * n
        right_min = [n] * n
        stk = []
        for i in range(n):
            while stk and nums[stk[-1]] >= nums[i]:
                right_min[stk.pop()] = i
            if stk:
                left_min[i] = stk[-1]
            stk.append(i)

        total_sum = 0
        
        for i in range(n):
            L_bound = left_max[i] + 1
            R_bound = right_max[i] - 1
            
            if L_bound <= i <= R_bound:
                count_max = 0
                r_start = i
                r_end = R_bound
                
                low_r, high_r = r_start, r_end
                crossover = r_end + 1
                while low_r <= high_r:
                    mid_r = (low_r + high_r) // 2
                    if valid_L[mid_r] >= i:
                        crossover = mid_r
                        high_r = mid_r - 1
                    else:
                        low_r = mid_r + 1
                
                seg1_end = min(crossover - 1, r_end)
                if r_start <= seg1_end:
                    sum_valid_L = pref_valid_L[seg1_end + 1] - pref_valid_L[r_start]
                    count_max += sum_valid_L - (L_bound - 1) * (seg1_end - r_start + 1)
                
                if crossover <= r_end:
                    count_max += (r_end - crossover + 1) * (i - L_bound + 1)
                
                total_sum += count_max * nums[i]

        for i in range(n):
            L_bound = left_min[i] + 1
            R_bound = right_min[i] - 1
            
            if L_bound <= i <= R_bound:
                count_min = 0
                r_start = i
                r_end = R_bound
                
                low_r, high_r = r_start, r_end
                crossover = r_end + 1
                while low_r <= high_r:
                    mid_r = (low_r + high_r) // 2
                    if valid_L[mid_r] >= i:
                        crossover = mid_r
                        high_r = mid_r - 1
                    else:
                        low_r = mid_r + 1
                        
                seg1_end = min(crossover - 1, r_end)
                if r_start <= seg1_end:
                    sum_valid_L = pref_valid_L[seg1_end + 1] - pref_valid_L[r_start]
                    count_min += sum_valid_L - (L_bound - 1) * (seg1_end - r_start + 1)
                        
                if crossover <= r_end:
                    count_min += (r_end - crossover + 1) * (i - L_bound + 1)
                    
                total_sum -= count_min * nums[i]

        if valid_count > k:
            excess = valid_count - k
            total_sum -= excess * target
            valid_count = k
            
        while valid_count < k:
            total_sum += threshold
            valid_count += 1
            
        return total_sum
