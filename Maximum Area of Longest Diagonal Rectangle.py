class Solution:
    def areaOfMaxDiagonal(self, dimensions):
        maxArea = 0
        Mdia2 = 0
        for r in dimensions:
            w = r[0]
            h = r[1]
            dia2 = w*w + h*h
            if Mdia2 < dia2:
                Mdia2 = dia2
                maxArea = 0
            if dia2 == Mdia2:
                maxArea = max(maxArea, w*h)
        return maxArea
      
