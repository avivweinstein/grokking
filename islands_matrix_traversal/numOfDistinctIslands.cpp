using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class DistinctIslandsDFS
{
public:
    static int findDistinctIslandsDFS(vector<vector<int>> &m){
        unordered_set<string> set;
        int rows = m.size();
        int cols = m[0].size();
        
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if(m[i][j] == 1){
                    string travPath;
                    traverseDFS(m, rows, cols, i, j, travPath, "o");
                    // cout << "travPath: " << travPath << endl;
                    set.insert(travPath);
                }
            }
        }
        
        return set.size();
    }

private:
    static void traverseDFS(vector<vector<int>> &m, int rows, int cols, int x, int y, string &traversalPath, string dir){
        if(x < 0 || x >= rows || y < 0 || y >= cols || m[x][y] == 0){
            return;
        }

        m[x][y] = 0;
        traversalPath += dir;

        traverseDFS(m, rows, cols, x+1, y, traversalPath, "D");
        traverseDFS(m, rows, cols, x-1, y, traversalPath, "U");
        traverseDFS(m, rows, cols, x, y+1, traversalPath, "R");
        traverseDFS(m, rows, cols, x, y-1, traversalPath, "L");

        traversalPath += "B";
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> vec = vector<vector<int>>{
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 1, 0, 1}};
    cout << DistinctIslandsDFS::findDistinctIslandsDFS(vec) << endl;

    vec = vector<vector<int>>{
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}};
    cout << DistinctIslandsDFS::findDistinctIslandsDFS(vec) << endl;

    return 0;
};