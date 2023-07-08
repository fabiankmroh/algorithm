class Solution {
public:
    int uniquePaths(int m, int n) {
        int map_arr[m][n];
        int i, j;
        for(i = 0; i < m; i++){
            map_arr[i][0] = 1;
        }

        for(j = 0; j < n; j++){
            map_arr[0][j] = 1;
        }

        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                map_arr[i][j] = map_arr[i-1][j] + map_arr[i][j-1];
            }
        }

        return map_arr[m-1][j-1];
    }
};