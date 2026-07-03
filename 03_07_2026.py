from collections import deque

class Solution:
    def findMaxPathScore(self, edges: list[list[int]], online: list[bool], k: int) -> int:
        n = len(online)
        adj = [[] for _ in range(n)]
        in_degree = [0] * n
        unique_costs = set()
        
        for u, v, cost in edges:
            if online[u] and online[v]:
                adj[u].append((v, cost))
                in_degree[v] += 1
                unique_costs.add(cost)
                
        topo_order = []
        q = deque([i for i in range(n) if in_degree[i] == 0 and online[i]])
        
        while q:
            u = q.popleft()
            topo_order.append(u)
            for v, _ in adj[u]:
                in_degree[v] -= 1
                if in_degree[v] == 0:
                    q.append(v)
                    
        sorted_costs = sorted(list(unique_costs))
        
        def check(min_cost_threshold):
            dist = [float('inf')] * n
            dist[0] = 0
            for u in topo_order:
                if dist[u] == float('inf'):
                    continue
                for v, cost in adj[u]:
                    if cost >= min_cost_threshold:
                        if dist[u] + cost < dist[v]:
                            dist[v] = dist[u] + cost
            return dist[n - 1] <= k

        low, high = 0, len(sorted_costs) - 1
        ans = -1
        
        while low <= high:
            mid = (low + high) // 2
            if check(sorted_costs[mid]):
                ans = sorted_costs[mid]
                low = mid + 1
            else:
                high = mid - 1
                
        return ans
