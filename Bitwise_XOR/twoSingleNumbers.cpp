using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
      vector<int> result;

      int n1XORn2 = 0;
      int num1 = 0;
      int num2 = 0;

      for(int i = 0; i < nums.size(); i++){ //XOR all numbers together to get n1XORn2
          n1XORn2 ^= nums[i];
      }

      cout << "n1XORn2: " << n1XORn2 << endl;

      //Now we need to find the first/rightmost set bit in n1XORn2
      int rightMostSetBit = 1;

      while((rightMostSetBit & n1XORn2) == 0){
        rightMostSetBit = rightMostSetBit << 1;
      }

      cout << "rightMostSetBit: " << rightMostSetBit << endl;

      for(int num : nums){
        if ((num & rightMostSetBit) == 0){
          num1 ^= num;
        }
        else{
          num2 ^= num;
        }
      }

      result.push_back(num1);
      result.push_back(num2);

      return result; 
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}