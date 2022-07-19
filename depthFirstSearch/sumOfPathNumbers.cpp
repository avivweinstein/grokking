using namespace std;

#include <iostream>

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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    return findPathSum(root, 0);
  }

private:
    static int findPathSum(TreeNode* root, int sum){
        if(root == nullptr){
            // cout << "Base case" << endl;
            // cout << "sum: " << sum << endl;
            return 0;
        }

        sum = sum*10 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            return sum;
        }

        return findPathSum(root->left, sum) + findPathSum(root->right, sum);
    }

};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) 
       << endl;
}