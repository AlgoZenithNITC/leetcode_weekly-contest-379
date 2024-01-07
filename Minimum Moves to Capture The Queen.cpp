class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        // rook can capture the queen in any case with in 2 moves
        
        int maxMoves = 2;
        
        // if row or column of queen is same as of rook then answer will be 1
        // but also check that bishop is now in between them
        
        // same row
        if( a == e )
        {
            if( c == e)
            {
                // means bishop is in same row
                // now check if bishop is not in a column which is between d and f

                if( d > b && d > f || d < b && d < f)
                {
                    maxMoves = 1;
                    
                }
            }
            else
            {   
                // bishop is in different row then simply attack
                maxMoves = 1;
            }
        }

        // same column

        if( b == f )
        {
            if( d == f)
            {
                // means bishop is in same column
                // now check if bishop is not in a row which is between b and f

                if( c > a && c > e || c < a && c < e)
                {
                    maxMoves = 1;
                }
            }
            else
            {
                maxMoves = 1;
            }
        }

        // bishop and queen in same diagonal
        
        if( c + d == e + f)
        {

            if( c + d == a + b)
            {
                // it means rook is also in same diagonal
                // then it should not be in between bishop and queen

                if( a < c && a < e || a > c && a > e)
                {
                    maxMoves = 1;
                }
            }
            else
            {
                
                // if rook is not in same diagonal then we can capture directly
                maxMoves = 1;
            }
        }
        
        // bishop and queen in same anti diagonal
        
        if( c - d == e - f)
        {
            if( c - d == a - b)
            {
                // it means rook is in same anti diagonal
                
                if( a < c && a < e || a > c && a > e)
                {
                    maxMoves = 1;
                }
            }
            else
            {   
                 // if rook is not in same diagonal then we can capture directly
                maxMoves = 1;
            }
        }

        return maxMoves;
    }
};
