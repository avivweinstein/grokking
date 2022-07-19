using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
        int xorResult = arr[0];
        for(int i = 1; i < arr.size(); i++){
            xorResult ^= arr[i];
        }
        return xorResult;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}