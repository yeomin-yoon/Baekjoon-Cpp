#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    vector<vector<bool>> Visited(
        maps.size(),
        vector<bool>(maps[0].size(), false)
        );
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    queue<pair<int,int>> BFSQueue;
    
    vector<vector<int>> Dist(
        maps.size(),
        vector<int>(maps[0].size(), 0)
        );
    
    // 시작 노드
    Visited[0][0] = true;
    Dist[0][0] = 1;
    BFSQueue.push({0,0});
    
    // BFS 탐색 시작
    while (!BFSQueue.empty())
    {
        // BFS 큐 pop 및 캐시
        int y = BFSQueue.front().first;
        int x = BFSQueue.front().second;
        BFSQueue.pop();
        
        // 상하좌우 인접 좌표 검사
        for (int i = 0; i < 4; i++)
        {
            // 현재 좌표 기준, 상하좌우 좌표 검사
            int ny = y + dy[i];
            int nx = x + dx[i];

            
            // 맵 범위 검사
            if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size())
                continue;

            // 벽 검사
            if (maps[ny][nx] == 0)
                continue;

            // 방문 검사
            if (Visited[ny][nx])
                continue;
            
            // 이동 시, 방문 처리 및 거리 계산
            Visited[ny][nx] = true;
            Dist[ny][nx] = Dist[y][x] + 1;
            BFSQueue.push({ny, nx});
        }
    }
    
    int answer = 0;
    
    if (Dist[maps.size() - 1][maps[0].size() - 1] == 0)
    {
        return answer = -1;
    }
    answer = Dist[maps.size() - 1][maps[0].size() - 1];
    
    return answer;
}