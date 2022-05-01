/* 트리 순회 */
#include <iostream>
using namespace std;

struct Tree
{
    char data;
    Tree *left;
    Tree *right;
};
Tree *tree;

void preorder(Tree *node)
{
    if (node)
    {
        cout << node->data;
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Tree *node)
{
    if (node)
    {
        inorder(node->left);
        cout << node->data;
        inorder(node->right);
    }
}

void postorder(Tree *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    char data, left, right;
    tree = (Tree *)malloc(sizeof(Tree) * n);

    for (int i = 0; i < n; i++)
    {
        cin >> data >> left >> right;
        tree[data - 'A'].data = data;

        if (left == '.')
            tree[data - 'A'].left = NULL;
        else
            tree[data - 'A'].left = &tree[left - 'A'];
        if (right == '.')
            tree[data - 'A'].right = NULL;
        else
            tree[data - 'A'].right = &tree[right - 'A'];
    }

    preorder(&tree[0]);
    cout << "\n";
    inorder(&tree[0]);
    cout << "\n";
    postorder(&tree[0]);
    cout << "\n";
}