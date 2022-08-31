def bfs(x, tree):
    visited, queue = [], []
    visited.append(x)
    queue.append(x)
    
    while(queue):
        x = queue.pop(0)
        for v in tree[x]:
            if v in visited: continue
            visited.append(v)
            queue.append(v)
            
    return len(visited)


def solution(n, wires):
    answer = 100
    tree = [[] for _ in range(n+1)]

    for a, b in wires:
        tree[a].append(b)
        tree[b].append(a)
    
    for a, b in wires:
        tree[a].remove(b)
        tree[b].remove(a)
        answer = min(answer, abs(bfs(a, tree) - bfs(b, tree)))
        tree[a].append(b)
        tree[b].append(a)
        
    return answer


print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
print(solution(4, [[1,2],[2,3],[3,4]]))
print(solution(7, [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]))
