fro
    # Prim's algorithm
    def prim_mst(self):
        min_heap = []
        visited = [False] * self.V
        mst_cost = 0
        
        heapq.heappush(min_heap, (0, 0))  # (weight, vertex)
        
        while min_heap:
            weight, vertex = heapq.heappop(min_heap)
            
            if visited[vertex]:
                continue
            
            mst_cost += weight
            visited[vertex] = True
            
            for neighbor, edge_weight in self.graph[vertex]:
                if not visited[neighbor]:
                    heapq.heappush(min_heap, (edge_weight, neighbor))
        
        return mst_cost
    
    # Kruskal's algorithm
    def kruskal_mst(self):
        parent = [-1] * self.V
        
        def find(x):
            if parent[x] == -1:
                return x
            parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            parent[x] = y
        
        edges = []
        mst_cost = 0
        
        for u in range(self.V):
            for v, w in self.graph[u]:
                edges.append((w, u, v))
        
        edges.sort()
        
        for edge in edges:
            weight, u, v = edge
            
            u_set = find(u)
            v_set = find(v)
            
            if u_set != v_set:
                mst_cost += weight
                union(u_set, v_set)
        
        return mst_cost
