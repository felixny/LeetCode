

class lc200 {
    private int row;
    private int col;
    
    public int numIslands(char[][] grid) {
        row = grid.length;
        col = grid[0].length;
        
        int count = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
    
    private void dfs(char[][] grid, int i , int j){
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        dfs(grid,i+1,j);
m         dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
    }

    public static void main(String[] args) {
        lc200 lc200 = new lc200();
        char[][] grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','1'}
        };

        System.out.println(lc200.numIslands(grid));
    }
}