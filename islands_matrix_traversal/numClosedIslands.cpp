using namespace std;

#include <iostream>
#include <vector>

class NoOfClosedIslandsDFS
{
public:
    static int countClosedIslands(vector<vector<int>> &m){
        int numIslands = 0;
        int rows = m.size();
        int cols = m[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(m[i][j] == 1){
                    if(closedIsland(m, rows, cols, i, j)){
                        numIslands++;
                    }
                }
            }
        }
        return numIslands;
    }

private:
 static bool closedIsland(vector<vector<int>> &m, int rows, int cols, int x, int y){
    if(x < 0 || x >= rows || y < 0 || y >= cols){
        return false;
    }

    if(m[x][y] == 0 && !(x < 0 || x >= rows || y < 0 || y >= cols)){
        return true;
    }

    m[x][y] = 0;

    return closedIsland(m, rows, cols, x+1, y)  &&
            closedIsland(m, rows, cols, x-1, y) &&
            closedIsland(m, rows, cols, x, y+1) &&
            closedIsland(m, rows, cols, x+1, y-1);
 }
};

int main(int argc, char **argv)
{
    vector<vector<int>> vec = vector<vector<int>>{
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    cout << NoOfClosedIslandsDFS::countClosedIslands(vec) << endl;

    vec = vector<vector<int>>{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}};
    cout << NoOfClosedIslandsDFS::countClosedIslands(vec) << endl;

    return 0;
};