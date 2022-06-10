/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution
{
public
    Node connect(Node root)
    {
        Node black = root;
        while (black != null && black.left != null)
        {                     // if next left exists
            Node red = black; // pointed to leftmost node to traverse
            while (true)
            {
                red.left.next = red.right;
                if (red.next == null)
                {
                    red.right.next = null;
                    break;
                }
                else
                {
                    red.right.next = red.next.left;
                    red = red.next;
                }
            }

            black = black.left;
        }
        return root;
    }
}