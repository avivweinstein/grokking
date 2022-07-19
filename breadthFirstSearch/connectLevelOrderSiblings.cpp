using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // level order traversal using 'next' pointer
  virtual void printLevelOrder() {
    TreeNode *nextLevelRoot = this;
    while (nextLevelRoot != nullptr) {
      TreeNode *current = nextLevelRoot;
      nextLevelRoot = nullptr;
      while (current != nullptr) {
        cout << current->val << " ";
        if (nextLevelRoot == nullptr) {
          if (current->left != nullptr) {
            nextLevelRoot = current->left;
          } else if (current->right != nullptr) {
            nextLevelRoot = current->right;
          }
        }
        current = current->next;
      }
      cout << endl;
    }
  }
};

class ConnectLevelOrderSiblings {
 public:
  static void connect(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    queue<TreeNode*> q;
    TreeNode* current;
    int size = 0;
    q.push(root);

    while(!q.empty()){
        size = q.size();

        for(int i = 0; i < size; i++){
            current = q.front();
            q.pop();

            if(i + 1 >= size){
                current->next = nullptr;
            }
            else{
                current->next = q.front();
            }

            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ConnectLevelOrderSiblings::connect(root);
  cout << "Level order traversal using 'next' pointer: " << endl;
  root->printLevelOrder();
}