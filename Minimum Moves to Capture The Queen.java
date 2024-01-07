public class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int maxMoves = 2;

        if (a == e) {
            if (c == e) {
                if (d > b && d > f || d < b && d < f) {
                    maxMoves = 1;
                }
            } else {
                maxMoves = 1;
            }
        }

        if (b == f) {
            if (d == f) {
                if (c > a && c > e || c < a && c < e) {
                    maxMoves = 1;
                }
            } else {
                maxMoves = 1;
            }
        }

        if (c + d == e + f) {
            if (c + d == a + b) {
                if (a < c && a < e || a > c && a > e) {
                    maxMoves = 1;
                }
            } else {
                maxMoves = 1;
            }
        }

        if (c - d == e - f) {
            if (c - d == a - b) {
                if (a < c && a < e || a > c && a > e) {
                    maxMoves = 1;
                }
            } else {
                maxMoves = 1;
            }
        }
        return maxMoves;
    }
}


