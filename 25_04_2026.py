from bisect import bisect_left

class Solution:
    def maxDistance(self, side: int, points: list[list[int]], k: int) -> int:
        unrolled = []
        for x, y in points:
            if y == 0:
                dist = x
            elif x == side:
                dist = side + y
            elif y == side:
                dist = 2 * side + (side - x)
            else:
                dist = 3 * side + (side - y)
            unrolled.append(dist)
        
        unrolled.sort()
        n = len(unrolled)
        total_perimeter = 4 * side

        def can_place(min_dist):
            for i in range(n):
                if unrolled[i] > unrolled[0] + min_dist:
                    break
                
                count = 1
                last_pos = unrolled[i]
                first_pos = unrolled[i]
                curr = i
                
                possible = True
                for _ in range(k - 1):
                    target = last_pos + min_dist
                    idx = bisect_left(unrolled, target, lo=curr + 1)
                    
                    if idx == n:
                        possible = False
                        break
                    
                    last_pos = unrolled[idx]
                    curr = idx
                
                if possible and (total_perimeter - (last_pos - first_pos)) >= min_dist:
                    return True
            return False

        low = 1
        high = total_perimeter // k
        ans = 0
        
        while low <= high:
            mid = (low + high) // 2
            if can_place(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
                
        return ans
