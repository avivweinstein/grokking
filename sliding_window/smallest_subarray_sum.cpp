using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
      int windowStart = 0;
      int windowEnd = 0;
      int minLength = 100000000;
      int windowSum = 0;

      for(; windowEnd < arr.size(); windowEnd++){
          windowSum += arr[windowEnd];

          while(windowSum >= S){
              minLength = min(minLength, windowEnd-windowStart+1);
              windowSum -= arr[windowStart];  // subtract the element going out
              windowStart++;                  // slide the window ahead
          }
      }

      return minLength;
  }
};

int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
}