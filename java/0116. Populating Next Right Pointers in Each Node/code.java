/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root==null){
            return root;
        }
        
        Node nodestart = root; //start of the previous line
        Node temp = nodestart; //temp node at the end of the new line
        Node newstart;         //start of the new line
        
        //check if it is the last line
        while(nodestart.left!=null){
            newstart = new Node();
            temp = newstart;
            //check it is the end of every line
            while(nodestart!=null){
                temp.next = nodestart.left;
                temp = temp.next;
                temp.next = nodestart.right;
                temp = temp.next;
                nodestart = nodestart.next;
            }           
            nodestart = newstart.next;
        } 
        return root;
    }
}
