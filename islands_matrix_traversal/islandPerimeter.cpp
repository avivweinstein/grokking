using namespace std;

#include <iostream>
#include <vector>

class IslandPerimeterDFS
{
public:
    static int findIslandPerimeter(vector<vector<int>> &m){
        //For every '1' in the matrix, I need to count the number of 0's or edges that each '1' is touching
        //I sum that up to get the perimeter. 
        int rows = m.size();
        int cols = m[0].size();
        int perimeter = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(m[i][j] == 1){
                    perimeter = perimeterCount(m, rows, cols, i, j);
                    return perimeter;
                }
            }
        }
        return -10;
    }
private:
    static int perimeterCount(vector<vector<int>> &m, int rows, int cols, int x, int y){
        
        if(x < 0 || x >= rows || y < 0 || y >= cols || m[x][y] == 0){
            return 1;
        }

        if(m[x][y] == 2){
            return 0;
        }

        m[x][y] = 2;
        
        return perimeterCount(m, rows, cols, x+1, y) +
               perimeterCount(m, rows, cols, x-1, y) +
               perimeterCount(m, rows, cols, x, y+1) +
               perimeterCount(m, rows, cols, x, y-1);
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> vec = vector<vector<int>>{
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    cout << IslandPerimeterDFS::findIslandPerimeter(vec) << endl;

    vec = vector<vector<int>>{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0}};
    cout << IslandPerimeterDFS::findIslandPerimeter(vec) << endl;

    return 0;
};