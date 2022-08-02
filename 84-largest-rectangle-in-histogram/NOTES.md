while(right < n - 1 && a[right] >= a[i])
{
right++;
}
area = max(area , a[i] * (right - left - 1));
}
return area;
```
​
**Optimisation - 1**
* Use stack approach for finding the Next smaller and Prev smaller element ashte!!
```
Code :
int area = -10;
stack<int> st;
int n = a.size();
vector<int> l_prev(n , -1);
vector<int> r_prev(n , -1);
/* For Finding Prev Smaller element */
for(int i = 0 ; i < n ; i++)
{
while(!st.empty() && a[st.top()] >= a[i])
{
st.pop();
}
if(st.empty()) l_prev[i] = 0;
else l_prev[i] = st.top() + 1;
st.push(i);
}
/* Emptying the stack...hehe xD */
while(st.empty() == false)
{
st.pop();
}