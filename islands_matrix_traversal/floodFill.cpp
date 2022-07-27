using namespace std;

#include <iostream>
#include <vector>

class FloodFillDFS
{
public:
    static vector<vector<int>> &floodFill(vector<vector<int>> &m, int x, int y, int newColor){
        int rows = m.size();
        int cols = m[0].size();

        fillDFS(m, rows, cols, x, y, newColor);

        return m;
    }

private:
    static void fillDFS(vector<vector<int>> &m, int rows, int cols, int x, int y, int newColor){
        if(x < 0 || x >= rows || y < 0 || y >= cols || m[x][y] == newColor || m[x][y] == 0){
            return;
        }

        m[x][y] = newColor;
        fillDFS(m,rows,cols, x+1, y, newColor);
        fillDFS(m,rows,cols, x-1, y, newColor);
        fillDFS(m,rows,cols, x, y+1, newColor);
        fillDFS(m,rows,cols, x, y-1, newColor);

        return;
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
    auto res = FloodFillDFS::floodFill(vec, 1, 3, 2);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    vec = vector<vector<int>>{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    res = FloodFillDFS::floodFill(vec, 3, 2, 5);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
};