// PROBLEM : Find the number of islands

// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
// Output: 4
// Explanation:
// The image below shows all the 4 islands in the grid.
 
// Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
// Output: 2
// Expanation:
// The image below shows 2 islands in the grid.
 
// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] = {'L', 'W'}

// SOLUTION :-

class Solution {
  public:
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m){
        visited[x][y] = true;
        
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        
        for(int dir =0; dir< 8; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 0 && ny >=0 && nx < n && ny < m && grid[nx][ny] =='L' && !visited[nx][ny]){
                dfs(nx, ny, grid, visited, n, m);
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        
        for(int i = 0; i<n ; i++){
            for(int j =0; j<m;j++){
                if(grid[i][j] == 'L' && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited, n, m);
                }
            }
        }
        return count;
    }
};
