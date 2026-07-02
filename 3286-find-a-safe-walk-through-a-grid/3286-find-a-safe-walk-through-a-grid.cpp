class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        // directions: up, down, left, right
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        // visited[i][j] = max health we had when reaching (i,j)
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        queue<tuple<int,int,int>> q; // {row, col, remaining health}
        
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        
        q.push({0, 0, startHealth});
        visited[0][0] = startHealth;
        
        while (!q.empty()) {
            auto [x, y, h] = q.front();
            q.pop();
            
            // reached destination
            if (x == m-1 && y == n-1) return true;
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newHealth = h - grid[nx][ny];
                    
                    // must stay alive
                    if (newHealth <= 0) continue;
                    
                    // only go if better health than before
                    if (visited[nx][ny] >= newHealth) continue;
                    
                    visited[nx][ny] = newHealth;
                    q.push({nx, ny, newHealth});
                }
            }
        }
        
        return false;
    }
};