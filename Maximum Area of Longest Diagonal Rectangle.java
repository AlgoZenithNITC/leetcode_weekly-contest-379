import java.util.List;

class Solution {
    public int areaOfMaxDiagonal(List<List<Integer>> dimensions) {
        int maxArea = 0, Mdia2 = 0;
        for (List<Integer> r : dimensions) {
            int w = r.get(0), h = r.get(1), dia2 = w * w + h * h;
            if (Mdia2 < dia2) {
                Mdia2 = dia2;
                maxArea = 0;
            }
            if (dia2 == Mdia2)
                maxArea = Math.max(maxArea, w * h);
        }
        return maxArea;
    }
}
