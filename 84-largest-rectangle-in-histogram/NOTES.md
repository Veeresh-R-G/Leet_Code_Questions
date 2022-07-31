**Brute Force**
* Just check for left prev and right prev
* Area = a[i] * (right - left  - 1)
​
```
Code :
​
int left;
int right;
int n = a.size();
int area = -10;
for(int i = 0 ; i < n ; i++)
{
left = i - 1 ;
while(left > 0 && a[left] >= a[i])
{
left--;
}
right = i + 1 ;
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
​
```
​