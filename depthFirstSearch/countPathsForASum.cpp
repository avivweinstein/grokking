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

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    int numPaths = 0;
    numPaths += dfs(root, S);

    return numPaths;

  }

private:
    int dfs(TreeNode* root, int S){
        if(root == nullptr){
            return 0;
        }

        int val = 0;

        if(root->val == 0){
            val = 1;
        }

        return val + dfs(root->left, S - root->val) + dfs(root->right, S-root->val);

    }
    
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}