

**Approach - 1 :**

_**Brute:**_

1. Do inorder store result in vector and sort it

2. Again start inorder compare the values now

3. If not equal change the values else if equal continue the traversals

PseudoCode:

Inorder(root)

i <- 0 to vector.size()
Run Inorder --> 
vector[i] != root->Val
  root->val = vector[i]
  
Now Advantage is that we will still maintain the structure of the given tree


