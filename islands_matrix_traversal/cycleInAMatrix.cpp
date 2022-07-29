using namespace std;

#include <iostream>
#include <vector>

class IslandCycleDFS
{
public:
    static bool hasCycle(vector<vector<char>> &m){
        int rows = m.size();
        int cols = m[0].size();
        vector<vector<int>> visited (rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j]){
                    if(containsCycleDFS(m, rows, cols, i, j, m[i][j], visited, -1, -1)){
                        return true;
                    }
                }
            }
        }

        return false;

    }
private:
    static bool containsCycleDFS(vector<vector<char>> &m, int rows, int cols, int x, int y, char target, vector<vector<int>> &v, int prevX, int prevY){
        if(x < 0 || x >= rows || y < 0 || y >= cols || m[x][y] != target){
            return false;
        }

        if(v[x][y] == 1){
            return true;
        }

        v[x][y] = 1;

        if((x+1 != prevX && containsCycleDFS(m, rows, cols, x+1, y, target, v, x, y)) ||
                (x-1 != prevX && containsCycleDFS(m, rows, cols, x-1, y, target, v, x, y)) ||
                (y+1 != prevY &&containsCycleDFS(m, rows, cols, x, y+1, target, v, x, y)) ||
                (y-1 != prevY && containsCycleDFS(m, rows, cols, x, y-1, target, v, x, y))){
                    return true;
                }

        return false;
    }
};

int main(int argc, char **argv)
{
    vector<vector<char>> vec = vector<vector<char>>{
        {'a', 'a', 'a', 'a'},
        {'b', 'a', 'c', 'a'},
        {'b', 'a', 'c', 'a'},
        {'b', 'a', 'a', 'a'}};
    cout << IslandCycleDFS::hasCycle(vec) << endl;

    vec = vector<vector<char>>{
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'a', 'a'},
        {'a', 'a', 'a', 'c'}};
    cout << IslandCycleDFS::hasCycle(vec) << endl;

    vec = vector<vector<char>>{
        {'a', 'b', 'e', 'b'},
        {'b', 'b', 'b', 'b'},
        {'b', 'c', 'c', 'd'},
        {'c', 'c', 'd', 'd'}};
    cout << IslandCycleDFS::hasCycle(vec) << endl;
    return 0;
};