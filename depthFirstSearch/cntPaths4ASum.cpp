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
    unordered_map<int, int> m;
    int count = 0;


 public:
  static int countPaths(TreeNode *root, int S) {
    dfs(root, S, 0);
    
    return count;
  }

 private:
  static void dfs(TreeNode* cur, int sum, int currentSum){
    if(cur == nullptr){
        return 0;
    }

    if(currentSum == sum){
        count++;
    }

    if(m.find(sum-currentSum) != m.end()){
        count += m[sum-currentSum]
    }

    for()


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