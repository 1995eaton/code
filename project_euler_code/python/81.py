import sys

def path_sum(path):
    path = [e[:] for e in path]
    size = len(path)
    for i in range(size - 2, -1, -1):
        path[i][size - 1] += path[i + 1][size - 1]
        path[size - 1][i] += path[size - 1][i + 1]
    for n in range(size - 2, -1, -1):
        path[n][n] += min(path[n + 1][n], path[n][n + 1])
        for i in range(n - 1, -1, -1):
            path[i][n] += min(path[i + 1][n], path[i][n + 1])
            path[n][i] += min(path[n + 1][i], path[n][i + 1])
    return path[0][0]

rows = list(filter(None, sys.stdin.readlines()))
rows = [list(map(int, e.split(','))) for e in rows]

print(path_sum(rows))
