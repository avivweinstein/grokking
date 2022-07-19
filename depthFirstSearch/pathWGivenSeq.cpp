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
    return dfs(root, sequence, 0);    
  }

  private:
    static bool dfs(TreeNode* root, const vector<int> & s, int seqPos){
        if (root == nullptr){
            // cout << "caught base case" << endl;
            if(seqPos == s.size()){
                return true;
            }
            return false;
        }
        // cout << endl;
        // cout << "NEW LOOP" << endl;
        // cout << "seqPos: " << seqPos << endl;
        // cout << "s[" << seqPos << "]: " << s[seqPos] << endl;
        // cout << "root->val: " << root->val << endl;


        if(root->val == s[seqPos]){
            seqPos++;
            // cout << "value is equal to sequence" << endl;
            return (dfs(root->left, s, seqPos) || dfs(root->right, s, seqPos));
        }


        if(root->left == nullptr && root->right == nullptr && s[seqPos] == root->val){
            return true;
        }
        // cout << "ending loop" << endl;
        //return dfs(root->left, s, seqPos) || dfs(root->right, s, seqPos);
        return false;

    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7}) << endl;
// cout << "SECOND PROBLEM!!!!" << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6}) << endl;
  cout << "Aviv's Test Cases" << endl;
  cout << "115?: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 5}) << endl;
  cout << "111?: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 1}) << endl;
  cout << "101?: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 1}) << endl;
  cout << "1: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 1}) << endl;

}