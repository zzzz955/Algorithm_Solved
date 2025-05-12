class Pair {
    public int x;
    public int y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    int[][] lst = new int[101][11];
    Pair[] pairs = new Pair[101];
    
    public int solution(int n, int w, int num) {
        boolean R = false;
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i) {
            lst[x][y] = i;
            pairs[i] = new Pair(x, y);
            if (!R) {
                if (y + 1 >= w) {
                    R = true;
                    x++;
                }
                else y++;
            }
            else {
                if (y - 1 < 0) {
                    R = false;
                    x++;
                }
                else y--;
            }
        }
        
        int answer = 0;
        int targetX = pairs[num].x;
        int targetY = pairs[num].y;
        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 11; ++j) {
                System.out.print(lst[i][j] + " ");
            }
            System.out.println();
        }
        
        System.out.println(targetX);
        for (int i = targetX; i < 101; ++i) {
            if (lst[i][targetY] > 0) {
                System.out.print(lst[i][targetY] + " ");
                answer++;
            }
            else break;
        }
        
        return answer;
    }
}