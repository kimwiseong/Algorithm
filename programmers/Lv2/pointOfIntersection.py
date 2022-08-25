def getPoint(line1, line2):
    A, B, E = line1
    C, D, F = line2
    if A*D == B*C: return 0.1, 0.1
    return (B*F-E*D)/(A*D-B*C), (E*C-A*F)/(A*D-B*C)

def solution(line):
    points, xv, yv = [], [], []
    for i in range(len(line)):
        for j in range(i+1, len(line)):
            x, y = getPoint(line[i], line[j])
            if x != int(x) or y != int(y): continue
            x, y = int(x), int(y)
            points.append([x, y])
            xv.append(x)
            yv.append(y)

    maxx, minx, maxy, miny = max(xv), min(xv), max(yv), min(yv)
    for i in range(len(points)):
        points[i][0] -= minx
        points[i][1] -= miny
    
    answer = [['.']*(maxx - minx + 1) for _ in range(maxy - miny + 1)]
    for x, y in points:
        answer[y][x] = '*'
    return [''.join(i) for i in answer[::-1]]


print(solution([[2, -1, 4], [-2, -1, 4],[0, -1, 1], [5, -8, -12], [5, 8, 12]]))
print(solution([[0, 1, -1], [1, 0, -1], [1, 0, 1]]))
print(solution([[1, -1, 0], [2, -1, 0]]))
print(solution([[1, -1, 0], [2, -1, 0], [4, -1, 0]]))


# Ax + By + E = 0
# Cx + Dy + F = 0
# x point = (BF-ED)/(AD-BC)
# y point = (EC-AF)/(AD-BC)
