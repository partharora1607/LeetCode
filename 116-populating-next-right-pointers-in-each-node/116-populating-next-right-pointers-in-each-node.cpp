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
    Node *temp = root;
    while (temp != NULL && temp->left != NULL)
    {
        Node *Node = temp;
        while (true)
        {
            Node->left->next = Node->right;
            if (Node->next == NULL)
            {
                break;
            }
            else
            {
                Node->right->next = Node->next->left;
                Node = Node->next;
            }
        }
        temp = temp->left;
    }
    return root;
}
};