/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    //recursive
    Node* connect(Node* root) {
        if (!root)
            return root;
        if (root->left)
            root->left->next = root->right;
        if (root->right)
            root->right->next = root->next ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }

    //iterative
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node *head = root, *cur = NULL;
        while(head->left)
        {
            cur = head;
            while(cur)
            {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            head = head->left;
        }
        return root;
    }
};