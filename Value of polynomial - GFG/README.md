# Value of polynomial
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a polynomial represented as <strong>poly[]</strong>&nbsp;of size <strong>n</strong> and a value <strong>x</strong>, compute value of the polynomial for given <strong>x</strong>.&nbsp; The result should be computed <strong>under modulo 10<sup>9</sup>+7.</strong>&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 4, x = 3
poly = {2, -6, 2, -1}
<strong>Output:</strong> 5
<strong>Explaination:</strong> Output is value of 2x<sup>3</sup> - 6x<sup>2</sup> + 
2x - 1 for x = 3.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 4, x = 2
poly = {1, 2, 0, 4}
<strong>Output: </strong>20
<strong>Explaination:</strong> Output is value of x<sup>3</sup> + 2x<sup>2</sup> + 4 
for x = 2.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>value()</strong> which takes n, poly&nbsp;and x as input parameters and returns the value of the polynomial modulo 10<sup>9</sup>&nbsp;+ 7.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n&nbsp;≤ 2000<br>
-1000 ≤ poly[i] ≤ 1000<br>
1 ≤ x ≤ 1000&nbsp;</span></p>
</div>