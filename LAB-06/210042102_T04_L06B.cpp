#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;


class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};


TreeNode *buildTree(vector<int> &levelOrder)
{
    if (levelOrder.empty() || levelOrder[0] == -1)
    {
        return nullptr;
    }

    int index = 0;
    TreeNode *root = new TreeNode(levelOrder[index++]);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty() && index < levelOrder.size())
    {
        TreeNode *current = q.front();
        q.pop();

        int leftVal = levelOrder[index++];
        if (leftVal != -1)
        {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        if (index < levelOrder.size())
        {
            int rightVal = levelOrder[index++];
            if (rightVal != -1)
            {
                current->right = new TreeNode(rightVal);
                q.push(current->right);
            }
        }
    }

    return root;
}

bool isSymmetric(TreeNode* leftSubtree, TreeNode* rightSubtree)
{
    if (leftSubtree == nullptr && rightSubtree == nullptr)
    {
        return true;
    }

    if (leftSubtree == nullptr || rightSubtree == nullptr)
    {
        return false;
    }


    return (leftSubtree->val == rightSubtree->val) &&
           isSymmetric(leftSubtree->left, rightSubtree->right) &&
           isSymmetric(leftSubtree->right, rightSubtree->left);
}

int main()
{
    int n;
    cin >> n;

    vector<int> levelOrder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> levelOrder[i];
    }

    TreeNode *root = buildTree(levelOrder);

    bool isSymmetricTree = isSymmetric(root, root);

    if (isSymmetricTree)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
