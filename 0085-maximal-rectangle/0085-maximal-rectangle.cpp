class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(); 
        int n = matrix[0].size();

        vector<int> left(n,0);
        vector<int> right(n,n);
        vector<int> height(n,0);

        int ans = 0;

        for(int i=0;i<m; i++){
            // Update height
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    height[j]++;
                else
                    height[j]=0;
            }
            // update left boundary
            int curLeft=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    left[j]=max(left[j],curLeft);
                else{
                    left[j]=0;
                    curLeft=j+1;
                }
            }
            // update right boundary 
            int curRight=n;
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1')
                    right[j]=min(right[j],curRight);
                else{
                    right[j]=n;
                    curRight=j;
                }
            }
            // calculate area
            for(int j=0;j<n;j++)
            ans=max(ans,(right[j]-left[j])*height[j]);
        }
        return ans;
    }
};