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
    Node* connect(Node* root) {
        Node *cur = root;
        while (cur)
        {
            Node *nextHead = NULL;
            Node *prevNode = NULL;
            while (cur)
            {
                if (!nextHead)
                    nextHead = cur->left ? cur->left : cur->right;
                if (cur->left)
                {
                    if (prevNode)
                        prevNode->next = cur->left;
                    prevNode = cur->left;
                }
                if (cur->right)
                {
                    if (prevNode)
                        prevNode->next = cur->right;
                    prevNode = cur->right;
                }
                cur = cur->next;
            }
            cur = nextHead;
        }
        return root;
    }
};