import heapq

def dijkstra(distance, adj, K):
    heap = []
    heapq.heappush(heap, [1 , 0])
    while(heap):
        node, weight = heapq.heappop(heap)
        for n, w in adj[node]:
            if weight + w > distance[n]: continue
            distance[n] = weight + w
            heapq.heappush(heap, [n, weight + w])

    return len([i for i in distance if i <= K])

def solution(N, road, K):
    adj = [[] for _ in range(N+1)]
    
    INF = int(1e9)
    distance = [INF] * (N+1)
    distance[1] = 0

    for v, u, dist in road:
        adj[v].append([u, dist])
        adj[u].append([v, dist])
    
    return dijkstra(distance, adj, K)


print(solution(5, [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]], 3))
