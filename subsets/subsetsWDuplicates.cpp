using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());

    vector<int> empty;
    result.push_back(empty);
    int startIdx = 0;           //this determines if we cover the entir reslt vector, or just the last iterations new additions.
    int endIdx = 0;             //endIdx will keep track of the end of result vector.
                                //WE always go to the end of the result vecotr.

    for(int i = 0; i < nums.size(); i++){
        startIdx = 0;
      // if current and the previous elements are same, create new subsets only from the 
      // subsets added in the previous step
        if(i > 0 && nums[i] == nums[i-1]){
            startIdx = endIdx+1;
        }
        endIdx = result.size();
        //otherwise, we do the same hting that we did in the regular subset problem
        for(int j = startIdx; j < endIdx; j++){
            // create a new subset from the existing subset and add the current element to it
            vector<int> set(result[j]);
            set.push_back(nums[i]);
            result.push_back(set);
        }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}