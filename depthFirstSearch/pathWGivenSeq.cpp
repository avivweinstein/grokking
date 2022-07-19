#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    if (root == nullptr) {
      return false;
    }

    return dfs(root, sequence, 0);

  }

private:
    static bool dfs(TreeNode* cur, const vector<int> &seq, int currentLocation){
        if(cur == nullptr){
            return false;
        }

        if(currentLocation >= seq.size() || cur->val != seq[currentLocation]){
            return false;
        }

        if(cur->left == nullptr && cur->right == nullptr && currentLocation == seq.size() - 1){
            return true;
        }

        currentLocation++;
        return dfs(cur->left, seq, currentLocation) || dfs(cur->right, seq, currentLocation);
        
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " 
       << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7}) << endl;
  cout << "Tree has path sequence: " 
       << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6}) << endl;
}