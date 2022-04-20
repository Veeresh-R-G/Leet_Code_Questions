​Approach 1 : 
using vector and then storing the inOrder and then traversing

Problem:Space Complexity : O(n) : n --> Number of nodes in the tree.<br>
<br /><br />

Approach - 2:
Optimised 
Space Complexity : O(h) : where h is the height of the tree : h-> log<sub>2</sub>(n)<br/>
Use <strong>STACK<strong/>
  
1. Declare as Private / Public member
2. Now for the given root push all root->left in the stack
3. HasNext()<br/>
    If(stack is empty())<br /> 
        &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;return false;<br/>
    else<br />
        &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;return true<br />
4.Next()<br/>
   &nbsp;&nbsp;&nbsp; stor the top of the stack and pop
  then call function tot push all the (node->right)
  return the val of current popped node
