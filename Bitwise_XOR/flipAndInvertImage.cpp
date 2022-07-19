#include <iostream>
#include <vector>
#include <vector>

using namespace std;

class Solution {
  public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> arr) {
    //   int s = arr[0].size();            //Find the size of the columns in matrix we have

    //   for (int row = 0; row < arr.size(); row++) {          //parse through the rows in the array
    //       for (int col = 0; col < (s + 1) / 2; ++col) {     // for every column,
    //           int tmp = arr[row][col] ^ 1;
    //           arr[row][col] = arr[row][s - 1 - col] ^ 1;
    //           arr[row][s - 1 - col] = tmp;
    //       }
    //   }
    //   return arr;
    // }
        int colSize = arr[0].size() - 1;

        for(int row = 0; row < arr.size(); row++){
            for(int col = 0; (col < (colSize + 2)/2); col++){
                int temp = arr[row][col] ^ 1;
                arr[row][col] = arr[row][colSize - col] ^ 1;
                arr[row][colSize - col] = temp;
            }
        }

        return arr;
    }

    static void print(const vector<vector<int>> arr) {
      for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << "\n";
      }
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  Solution::print(Solution::flipAndInvertImage(arr));
  cout << "\n";

  vector<vector<int>> arr2 = 
           vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
  Solution::print(Solution::flipAndInvertImage(arr2));
}