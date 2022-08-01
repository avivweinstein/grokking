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
   bool res = false;
   res = dfs(root, sequence, 0);
   return res;

  }
 private:
  static bool dfs(TreeNode *root, const vector<int> &seq, int seqIndex){
    if(root == nullptr){
        return false;
    }

    if(seqIndex >= seq.size() || root->val != seq[seqIndex]){
        return false;
    }

    if(root->left == nullptr && root->right == nullptr && seqIndex == seq.size()-1){
        return true;
    }
  
    seqIndex++;

    return dfs(root->left, seq, seqIndex)||dfs(root->right, seq, seqIndex);

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