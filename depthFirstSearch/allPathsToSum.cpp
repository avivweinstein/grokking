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

    vector<vector<int>> result;
    vector<int> current;
    findPathRecurse(root, sum, result, current);
    return result;
  }
  
 private:
  static void findPathRecurse(TreeNode* root, int sum, vector<vector<int>> &res,
                              vector<int> &cur){
    if(root == nullptr){
      return;
    }

    cur.push_back(root->val);
    
    if(root->left == nullptr && root->right == nullptr && sum == root->val){
      res.push_back(cur);
    }

    sum = sum - root->val;

    findPathRecurse(root->left, sum, res, cur);
    findPathRecurse(root->right, sum, res, cur);

    cur.pop_back();
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