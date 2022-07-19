using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int left = 0;
    int maxLength = 0;

    unordered_map<char, int> fruitBasket;

    // try to extend the range [windowStart, windowEnd]
    for (int right = 0; right < arr.size(); right++) {
      fruitBasket[arr[right]]++;
      // shrink the sliding window, until we're left with '2' fruits in the frequency map
      while ((int)fruitBasket.size() > 2) {
        fruitBasket[arr[left]]--;       //remove the element from the hash map
        if (fruitBasket[arr[left]] == 0) {  //once we have decermented to 0,
          fruitBasket.erase(arr[left]); //erase the key from the hash map
        }
        left++;  // shrink the window by incremening the left side
      }
      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) 
       << endl;
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) 
       << endl;
}