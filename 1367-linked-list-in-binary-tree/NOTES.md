My first solution will only checks if that elements in the list are just present or not in th BT
that is , even if they are present continously or not continously I will return true
​
But conditon is that they should be contingous
```
if(root->val == head->val)
{
return f(head->next , root->right) || f(head->next , root->left)
}
​
//This was taking care of non-continual presense of the elements
else
{
return f(head , root->right) || f(head , root->left);
}
```