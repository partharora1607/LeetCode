/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root)
{
    Node *Node1 = root;
    while (Node1 != NULL && Node1->left != NULL)
    {
        Node *Node2 = Node1; // pointed to leftmost node to traverse
        while (true)
        {
            Node2->left->next = Node2->right;
            if (Node2->next == NULL)
            {
                Node2->right->next = NULL;
                break;
            }
            else
            {
                Node2->right->next = Node2->next->left;
                Node2 = Node2->next;
            }
        }
        Node1 = Node1->left;
    }
    return root;
}
};