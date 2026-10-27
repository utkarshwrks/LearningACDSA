class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> matrix(m, string(n,'#'));
        for(int i=0;i<n;i++){
          matrix[0][i]='.';
        }

        for(int j=0;j<m;j++){
            matrix[j][n-1]='.';
        }

        return matrix;
    }
};