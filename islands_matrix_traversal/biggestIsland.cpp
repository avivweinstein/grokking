using namespace std;

#include <iostream>
#include <vector>

class MaxAreaIsland
{
public:
    static int findMaxAreaIsland(vector<vector<int>> &m){
        int maxSize = 0;
        int currentSize = 0;

        if(m.size() == 0){
            return 0;
        }
        int rows = m.size();
        int cols = m[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(m[i][j] == 1){
                    currentSize = dfs(m, rows, cols, i, j);
                    maxSize = max(maxSize, currentSize);
                }
            }
        }

    return maxSize;  
}
private:
    static int dfs(vector<vector<int>> &m, int rows, int cols, int x, int y){
        if(x < 0 || x >=rows || y < 0 || y >= cols || m[x][y] == 0){
            return 0;
        }
        
        int islandSize = 0;

        m[x][y] = 0;

        islandSize = 1 + dfs(m, rows, cols, x+1, y) + dfs(m, rows, cols, x-1, y) + dfs(m, rows, cols, x, y+1) + dfs(m, rows, cols, x, y-1);
        
        return islandSize;
    }
    
};

int main(int argc, char **argv)
{
    vector<vector<int>> vec = vector<vector<int>>{
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    cout << MaxAreaIsland::findMaxAreaIsland(vec) << endl;

    return 0;
};