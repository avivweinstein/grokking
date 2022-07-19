using namespace std;

#include <iostream>
#include <queue>
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

class RightViewTree {
 public:
  static vector<TreeNode *> traverse(TreeNode *root) {
    vector<TreeNode *> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode*> q;
    TreeNode* current = nullptr;
    int size = 0;
    q.push(root);
    while(!q.empty()){
        size = q.size();
        for(int i = 0; i < size; i++){
            current = q.front();
            q.pop();

            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }
        result.push_back(current);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->left->left->left = new TreeNode(3);
  vector<TreeNode *> result = RightViewTree::traverse(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}