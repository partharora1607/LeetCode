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
    if(root == NULL){
        return root;
    }
    queue<Node *> q1;
    q1.push(root);
    q1.push(NULL);
    vector<Node *> res;
    while (!q1.empty())
    {
        Node *front = q1.front();
        q1.pop();
        if (front != NULL)
        {
            res.push_back(front);
            if (front->left)
            {
                q1.push(front->left);
            }
            if (front->right)
            {
                q1.push(front->right);
            }
        }
        else
        {
            for (int i = 0; i < res.size() - 1; i++)
            {
                res[i]->next = res[i + 1];
            }
            res.clear();
            if (!q1.empty())
            {
                q1.push(NULL);
            }
        }
    }
    return root;
}
};