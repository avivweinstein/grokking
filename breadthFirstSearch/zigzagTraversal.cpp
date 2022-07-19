using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    // cout << "hello" << endl;
    vector<vector<int>> result;
    bool goingLeftToRight = true;
    vector<int> temp;
    queue<TreeNode*> q;
    TreeNode* current;
    int size = 0;

    q.push(root);

    while(!q.empty()){
        size = q.size();
        for(int i = 0; i < size; i++){
            current = q.front();
            q.pop();
            temp.push_back(current->val);

            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }

        if(!goingLeftToRight){
            reverse(temp.begin(), temp.end());
        }
        
        goingLeftToRight = !goingLeftToRight;
        result.push_back(temp);

        temp.clear();
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}