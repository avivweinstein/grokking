using namespace std;

#include <deque>
#include <iostream>
#include <queue>

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

class ReverseLevelOrderTraversal {
 public:
  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result;
    queue<TreeNode*> q;
    vector<int> temp;
    int size = 0;
    q.push(root);
    TreeNode* current;

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

        result.push_front(temp);
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
  auto result = ReverseLevelOrderTraversal::traverse(root);

  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}