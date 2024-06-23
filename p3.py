# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))
    result = 0
    def bfs(x,y,bearsize) : 
      from collections import deque
      directions = [(1,0),(0,1),(-1,0),(0,-1)]
      queue = deque([(x,y,0)])
      forest_visited = [[False]*N for _ in range(N)]
      forest_visited[x][y] = True
      honey_positions = []
      min_distance = float('inf')

      while queue :
        kx,ky,distance = queue.popleft()
        for dx, dy in directions :
          nx, ny = kx + dx , ky + dy

          if 0 <= nx < N and 0 <= ny < N and forest_visited[nx][ny] == False :
            if forest[nx][ny] <= bearsize :
              forest_visited[nx][ny] = True
              if 0 < forest[nx][ny] < bearsize :
                if distance + 1 < min_distance :
                  honey_positions = [(nx,ny, distance + 1)]
                  min_distance = distance + 1 
                elif distance + 1 == min_distance :
                  honey_positions.append((nx,ny,distance +1))
              queue.append((nx,ny,distance+1))

      if not honey_positions :
        return None
      honey_positions.sort()
      return honey_positions[0]
    
    while True :
      result = bfs(bear_x,bear_y,bear_size)
      if result is None :
        break

      bear_x,bear_y,distance = result
      time += distance
      honeycomb_count +=1
      forest[bear_x][bear_y] = 0

      if honeycomb_count == bear_size :
        bear_size += 1
        honeycomb_count = 0
    
    return time
    return result

result = problem3(input)
print(result)
assert result == 14
print("정답입니다.")
    
