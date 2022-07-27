using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

class DistinctIslandsDFS
{
public:
    static int findDistinctIslandsDFS(vector<vector<int>> &m){
        unordered_set<string> set;
        int row = m.size();
        int cols = m[0].size();
        


        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if(m[i][j] == 1){
                    traverseDFS(m, rows, cols, i, j, set);
                }
            }
        }
        
        int numDistinct = set.size();
        return numDistinct;
    }

private:
    static int traverseDFS(vector<vector<int>> &m, int rows, int cols, int x, int y, unordered_set<string> s){

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