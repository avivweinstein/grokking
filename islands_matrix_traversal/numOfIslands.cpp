using namespace std;

#include <iostream>
#include <vector>

class NumOfIslandsDFS
{
public:
    static int countIslands(vector<vector<int>> &matrix){
        int res;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if(matrix[i][j]==1){
                    res++;
                    dfs(matrix, i, j);
                }
            }
        }

        return res;
    }

private:
    static void dfs(vector<vector<int>> &matrix, int x, int y){
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()){      //Base case
            return;
        }
        if(matrix[x][y] == 0){              //Do nothing case
            return;
        }

        matrix[x][y] = 0;       //If we are at a 1, then set this square to 0.

        dfs(matrix, x+1, y);
        dfs(matrix, x-1, y);
        dfs(matrix, x, y+1);
        dfs(matrix, x, y-1);

    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> vec = {
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    cout << NumOfIslandsDFS::countIslands(vec) << endl;

    vec = vector<vector<int>>{
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    cout << NumOfIslandsDFS::countIslands(vec) << endl;

    return 0;
};