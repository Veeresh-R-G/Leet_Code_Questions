st.push(i);
}
/*  Final Loop to calculate the max Area    */
for(int i = 0 ; i < n ; i++)
{
area = max(area , a[i] * (r_prev[i] - l_prev[i] + 1));
}
return area;
}
​
```
​
**Optimisation - 2**
* Ok Here we are using the fact that stack is being filled in an increasing order
* Space and Time Complexity : O(n) + O(n)
​
```
Code :
stack<int> st;
int area = -10;
int n = h.size();
for(int i = 0 ; i <= n ; i++)
{
while(!st.empty() &&(i == n ||  h[st.top()] >= h[i]))
{
int ind = st.top();
int height = h[ind];
st.pop();
int rs = i;
//after popping so it will be a different value !!!
int ls = st.empty() ? 0 : st.top();