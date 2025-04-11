// PROBLEM : Flood fill Algorithm

// You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. 
// Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.
// Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. 
// Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

// Examples:

// Input: image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2
// Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]
// Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].

// Input: image[][] = [[1, 1, 1], [1, 1, 0], [1, 0, 1]], sr = 1, sc = 1, newColor = 2
// Output: [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
// Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

// Input: image[][] = [[0, 1, 0], [0, 1, 0]], sr = 0, sc = 1, newColor = 0
// Output: [[0, 0, 0], [0, 0, 0]]
// Explanation: Starting from pixel (0, 1) with value 1, flood fill changes all 4-directionally connected pixels with value 1 to 0, resulting in [[0, 0, 0], [0, 0, 0]]

// Constraints:
// 1 ≤ n ≤ m ≤ 500
// 0 ≤ image[i][j] ≤ 10
// 0 ≤ newColor ≤ 10
// 0 ≤ sr ≤ (n-1)
// 0 ≤ sc ≤ (m-1)

// SOLUTION : 

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor){
        // Code here
        int n = image.size();
        int m = image[0].size();
        
        if(x < 0 || y<0 || x >= n || y >= m || image[x][y] != oldColor){
            return;
        }
        
        image[x][y] = newColor;
        
        dfs(image, x+1, y, oldColor, newColor);
        dfs(image, x-1, y, oldColor, newColor);
        dfs(image, x, y+1, oldColor, newColor);
        dfs(image, x, y-1, oldColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int oldColor = image[sr][sc];
        
        if(oldColor == newColor){
            return image;
        }
        
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};
