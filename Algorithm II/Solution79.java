public class Solution79 {
    private boolean search(char[][] board, int i, int j, String word, int idx) {
        if (idx == word.length() - 1)
            return true;
        board[i][j] -= 65;
        if (i > 0 && board[i - 1][j] == word.charAt(idx + 1) && search(board, i - 1, j, word, idx + 1))
            return true;
        if (j > 0 && board[i][j - 1] == word.charAt(idx + 1) && search(board, i, j - 1, word, idx + 1))
            return true;
        if (i < board.length - 1 && board[i + 1][j] == word.charAt(idx + 1) && search(board, i + 1, j, word, idx + 1))
            return true;
        if (j < board[0].length - 1 && board[i][j + 1] == word.charAt(idx + 1)
                && search(board, i, j + 1, word, idx + 1))
            return true;
        board[i][j] += 65;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int r = board.length;
        if (r == 0)
            return false;
        int c = board[0].length;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (board[i][j] == word.charAt(0) && search(board, i, j, word, 0))
                    return true;
        return false;
    }

    public static void main(String[] args) {
        Solution79 leetcode = new Solution79();
        char[][] board = { { 'A', 'B', 'C', 'E' },
                { 'S', 'F', 'C', 'S' },
                { 'A', 'D', 'E', 'E' } };
        System.out.println(leetcode.exist(board, "ABCCED"));
       // System.out.println(leetcode.exist(board, "ABCB"));
    }

}

/* https://cscircles.cemc.uwaterloo.ca/java_visualize/#code=public+class+Solution79+%7B%0A++++private+boolean+search(char%5B%5D%5B%5D+board,+int+i,+int+j,+String+word,+int+idx)+%7B%0A++++++++if+(idx+%3D%3D+word.length()+-+1)%0A++++++++++++return+true%3B%0A++++++++board%5Bi%5D%5Bj%5D+-%3D+65%3B%0A++++++++if+(i+%3E+0+%26%26+board%5Bi+-+1%5D%5Bj%5D+%3D%3D+word.charAt(idx+%2B+1)+%26%26+search(board,+i+-+1,+j,+word,+idx+%2B+1))%0A++++++++++++return+true%3B%0A++++++++if+(j+%3E+0+%26%26+board%5Bi%5D%5Bj+-+1%5D+%3D%3D+word.charAt(idx+%2B+1)+%26%26+search(board,+i,+j+-+1,+word,+idx+%2B+1))%0A++++++++++++return+true%3B%0A++++++++if+(i+%3C+board.length+-+1+%26%26+board%5Bi+%2B+1%5D%5Bj%5D+%3D%3D+word.charAt(idx+%2B+1)+%26%26+search(board,+i+%2B+1,+j,+word,+idx+%2B+1))%0A++++++++++++return+true%3B%0A++++++++if+(j+%3C+board%5B0%5D.length+-+1+%26%26+board%5Bi%5D%5Bj+%2B+1%5D+%3D%3D+word.charAt(idx+%2B+1)%0A++++++++++++++++%26%26+search(board,+i,+j+%2B+1,+word,+idx+%2B+1))%0A++++++++++++return+true%3B%0A++++++++board%5Bi%5D%5Bj%5D+%2B%3D+65%3B%0A++++++++return+false%3B%0A++++%7D%0A%0A++++public+boolean+exist(char%5B%5D%5B%5D+board,+String+word)+%7B%0A++++++++int+r+%3D+board.length%3B%0A++++++++if+(r+%3D%3D+0)%0A++++++++++++return+false%3B%0A++++++++int+c+%3D+board%5B0%5D.length%3B%0A++++++++for+(int+i+%3D+0%3B+i+%3C+r%3B+%2B%2Bi)%0A++++++++++++for+(int+j+%3D+0%3B+j+%3C+c%3B+%2B%2Bj)%0A++++++++++++++++if+(board%5Bi%5D%5Bj%5D+%3D%3D+word.charAt(0)+%26%26+search(board,+i,+j,+word,+0))%0A++++++++++++++++++++return+true%3B%0A++++++++return+false%3B%0A++++%7D%0A%0A++++public+static+void+main(String%5B%5D+args)+%7B%0A++++++++Solution79+leetcode+%3D+new+Solution79()%3B%0A++++++++char%5B%5D%5B%5D+board+%3D+%7B+%7B+'A',+'B',+'C',+'E'+%7D,%0A++++++++++++++++%7B+'S',+'F',+'C',+'S'+%7D,%0A++++++++++++++++%7B+'A',+'D',+'E',+'E'+%7D+%7D%3B%0A++++++++System.out.println(leetcode.exist(board,+%22ABCCED%22))%3B%0A+++++++//+System.out.println(leetcode.exist(board,+%22ABCB%22))%3B%0A++++%7D%0A%0A%7D%0A&mode=display&curInstr=34 */