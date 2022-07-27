public class lc74 {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;
        
        int start = 0;
        int end = row*col-1;
        
        while(start<= end){
            int mid = (start+end)/2;
            int tmp = matrix[mid/col][mid%col];
            if (tmp > target){
                end = mid - 1;
                continue;
            }
            if (tmp < target){
                start = mid + 1;
                continue;
            }
            return true;
        }
        return false;
    }
}

