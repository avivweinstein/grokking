using namespace std;

#include <iostream>
#include <vector>

class MinSizeSubArraySum {
  public:
    static int findMinSubArray(int S, const vector<int>& arr) {
        




    }
  };



int main(int argc, char *argv[])
{
    int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
    cout << "Smallest subarray length: " << result << endl;
    result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
    cout << "Smallest subarray length: " << result << endl;
    result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
    cout << "Smallest subarray length: " << result << endl;
}
