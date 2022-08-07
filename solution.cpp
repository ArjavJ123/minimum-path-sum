class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r= grid.size(), c=grid[0].size();
        vector<vector<int>> t(r, vector<int>(c));
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++ ) {
                    if(i ==0 && j==0) {
                        t[i][j] = grid[0][0];
                    }
                    else if(i==0) {
                        t[i][j] = t[i][j-1] +grid[i][j];
                    }
                    else if(j==0) {
                        t[i][j] = t[i-1][j] + grid[i][j];
                    }
                    else {
                        t[i][j] = min(t[i-1][j] + grid[i][j], t[i][j-1] +grid[i][j]);
                    }
                }
            }
        return t[r-1][c-1];
    }
};
