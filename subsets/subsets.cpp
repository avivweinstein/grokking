using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {

    //create output 2D vector
    vector<vector<int>> result;
    //begin the output vector with an empty set
    vector<int> emptySet;
    //push it into the output vector
    result.push_back(emptySet);

    //We will have two loops. We will take all exisiting subsets and insert the current number in them to create new subsets
    for(int i = 0; i < nums.size(); i++){
        //n = the size of the current subsets. Our "inner loop"
        int n = result.size();
        for(int j = 0; j < n; j++){
            //initialize yourself off the first item in the result vector
            vector<int> set(result[j]);         //This initializes set with the first row of result.
            //add the new number to what we initialized ourself off of.
            set.push_back(nums[i]);
            //add set back to result.
            result.push_back(set);
        }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}