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

  // tree traversal using 'next' pointer
  virtual void printTree() {
    TreeNode *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current != nullptr) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
    if (root == nullptr) {
      return;
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

            if(!q.empty()){
                current->next = q.front();
            }
            else{
                current->next = nullptr;
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
  ConnectAllSiblings::connect(root);
  root->printTree();
}