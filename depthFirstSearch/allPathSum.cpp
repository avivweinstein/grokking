using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    findPathsRecursive(root, sum, currentPath, allPaths);
    return allPaths;
  }

 private:
  static void findPathsRecursive(TreeNode *currentNode, int sum, vector<int> &currentPath, vector<vector<int>> &allPaths) {

    if(currentNode == nullptr){
        // currentPath.pop_back();
        // currentPath.clear();
        return;
    }

    currentPath.push_back(currentNode->val);
    sum = sum - currentNode->val;

    if(sum == 0){
        allPaths.push_back(currentPath);
    }
    else{
        findPathsRecursive(currentNode->left, sum, currentPath, allPaths);
        findPathsRecursive(currentNode->right, sum, currentPath, allPaths);
    }
    currentPath.pop_back();

  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}