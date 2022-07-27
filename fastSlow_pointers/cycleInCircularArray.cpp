using namespace std;

#include <iostream>
#include <vector>

class CircularArrayLoop {
 public:
  static bool loopExists(const vector<int> &arr) {
  
  
  
  }
};

int main(int argc, char *argv[]) {
  cout << CircularArrayLoop::loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 2, -1, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 1, -1, -2}) << endl;
}