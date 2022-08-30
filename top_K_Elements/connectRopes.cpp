using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < ropeLengths.size(); i++){
        minHeap.push(ropeLengths[i]);
    }

    int temp = 0;
    int result = 0;

    while(minHeap.size() > 1){
        temp = minHeap.top();
        minHeap.pop();
        temp += minHeap.top();
        minHeap.pop();
        result += temp;
        minHeap.push(temp);
    }

   return result;

  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}