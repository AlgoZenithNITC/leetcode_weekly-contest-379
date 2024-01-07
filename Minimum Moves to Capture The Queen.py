class Solution:
    def minMovesToCaptureTheQueen(self, a, b, c, d, e, f):
        maxMoves = 2
        if a == e:
            if c == e:
                if (d > b and d > f) or (d < b and d < f):
                    maxMoves = 1
            else:
                maxMoves = 1
        if b == f:
            if d == f:
                if (c > a and c > e) or (c < a and c < e):
                    maxMoves = 1
            else:
                maxMoves = 1
        if c + d == e + f:
            if c + d == a + b:
                if (a < c and a < e) or (a > c and a > e):
                    maxMoves = 1
            else:
                maxMoves = 1
        if c - d == e - f:
            if c - d == a - b:
                if (a < c and a < e) or (a > c and a > e):
                    maxMoves = 1
            else:
                maxMoves = 1
        return maxMoves


