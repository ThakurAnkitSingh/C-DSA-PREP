#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertAtBST(Node *&root, int val)
{
    if (!root)
    {
        // There is no BST currently
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    {
        // inerting at left bst
        root->left = insertAtBST(root->left, val);
    }
    else
    {
        // inerting at right bst
        root->right = insertAtBST(root->right, val);
    }
    return root;
}

void takeBSTInput(Node *&root)
{
    int data;
    cout << "Taking Input: " << endl;
    cin >> data;
    while (data != -1)
    {
        insertAtBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    // base case
    //  LNR order
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void findMaxDepth(Node *root, int cur, int &max)
{
    // root, curr = 1, max = 0
    if (root == nullptr)
    {
        return;
    }

    if (cur > max)
    {
        max = cur;
    }

    findMaxDepth(root->left, cur + 1, max);
    findMaxDepth(root->right, cur + 1, max);
}

void preorder(Node *root)
{
    // base case
    //  NLR order
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    // base case
    //  LRN order
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *miniVal(Node *root)
{
    if (!root)
        return nullptr; // Handle the case where the tree is empty

    Node *mini = root;

    while (mini->left)
    {
        mini = mini->left;
    }

    return mini;
}

Node *maxiVal(Node *root)
{
    if (!root)
        return nullptr; // Handle the case where the tree is empty

    Node *maxi = root;

    while (maxi->right)
    {
        maxi = maxi->right;
    }

    return maxi;
}

Node *deletionFromBST(Node *&root, int x)
{
    if (!root)
        return NULL;
    if (root->data == x)
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (!root->left && !root->right)
        {
            // get the min value either from left or right->left
            int mini = miniVal(root->right)->data;
            root->data = mini;
            root->right = deletionFromBST(root->right, mini);
            return root;
        }
    }

    if (x < root->data)
    {
        root->left = deletionFromBST(root->left, x);
    }
    else
    {
        root->right = deletionFromBST(root->right, x);
    }
    return root;
}


int main()
{
    // Currently root is NULL means there is no BST tree
    Node *root = NULL;
    takeBSTInput(root);
    // Printing BST
    cout << "Before deletion in BST : " << endl;
    // Deletion in BST
    levelOrderTraversal(root);
    cout << "After Deletion : " << endl;
    deletionFromBST(root, 9);
    levelOrderTraversal(root);

    cout << "Inorder BST" << endl;
    inorder(root);

    cout << "preorder BST" << endl;
    preorder(root);

    cout << "Inorder BST" << endl;
    postorder(root);

    // Depth of the BST
    int max = 0;
    findMaxDepth(root, 1, max);
    cout << "Maximum Depth of BST tree is : " << max << endl;

    // Minimum value in BST
    Node *mini = miniVal(root);
    cout << "Minimum Value in BST: " << mini->data << endl;
    // Maximum value in BST
    Node *maxi = maxiVal(root);
    cout << "Maximum Value in BST: " << maxi->data << endl;

}