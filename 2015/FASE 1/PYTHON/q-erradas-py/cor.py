def distance_to_zero(x, y, grid):
    n = len(grid)
    distances = [[float('inf')] * n for _ in range(n)]
    distances[x][y] = 0
    
    queue = [(x, y)]
    while queue:
        i, j = queue.pop(0)
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ni, nj = i + dx, j + dy
            if 0 <= ni < n and 0 <= nj < n and distances[ni][nj] == float('inf'):
                distances[ni][nj] = distances[i][j] + 1
                queue.append((ni, nj))
                
    return min(distances[x][y], 9)

def color_grid(N, grid):
    colored_grid = [[0] * N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if grid[i][j] == '*':
                colored_grid[i][j] = str(distance_to_zero(i, j, grid))
            else:
                colored_grid[i][j] = grid[i][j]
    
    return colored_grid

def main():
    N = int(input().strip())
    grid = [list(input().strip()) for _ in range(N)]
    
    colored_grid = color_grid(N, grid)
    
    for row in colored_grid:
        print(''.join(row))

if __name__ == "__main__":
    main()
