public class Solution200 {
    public int numIslands(char[][] grid) {
        int row = grid.length;
        int cols = grid[0].length;

        int count = 0;
        for (int i  = 0; i < row; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == '1'){
                    mark(grid,i,j,row,cols);
                    count++;
                }
            }
        }

        return count;
    }

    public void mark(char[][] matrix, int x, int y, int r, int c){
        if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != '1') return;

    matrix[x][y] = '2';

    mark(matrix, x + 1, y, r, c); // right
    mark(matrix, x, y + 1, r, c); // top
    mark(matrix, x - 1, y, r, c); // left
    mark(matrix, x, y - 1, r, c); // bot
  }
    
}
