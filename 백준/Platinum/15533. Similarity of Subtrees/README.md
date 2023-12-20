# [Platinum V] Similarity of Subtrees - 15533 

[문제 링크](https://www.acmicpc.net/problem/15533) 

### 성능 요약

메모리: 19868 KB, 시간: 80 ms

### 분류

해싱

### 제출 일자

2023년 12월 20일 16:09:38

### 문제 설명

<p>Define the depth of a node in a rooted tree by applying the following rules recursively:</p>

<ul>
	<li>The depth of a root node is 0.</li>
	<li>The depths of child nodes whose parents are with depth d are d + 1.</li>
</ul>

<p>Let S(T, d) be the number of nodes of T with depth d. Two rooted trees T and T ′ are similar if and only if S(T, d) equals S(T ′ , d) for all non-negative integer d.</p>

<p>You are given a rooted tree T with N nodes. The nodes of T are numbered from 1 to N. Node 1 is the root node of T. Let T<sub>i</sub> be the rooted subtree of T whose root is node i. Your task is to write a program which calculates the number of pairs (i, j) such that T<sub>i</sub> and T<sub>j</sub> are similar and i < j.</p>

### 입력 

 <p>The input consists of a single test case.</p>

<pre>N
a<sub>1</sub> b<sub>1</sub>
…
a<sub>N−1</sub> b<sub>N−1</sub></pre>

<p>The first line contains an integer N (1 ≤ N ≤ 100,000), which is the number of nodes in a tree. The following N − 1 lines give information of branches: the i-th line of them contains a<sub>i</sub> and b<sub>i</sub>, which indicates that a node a<sub>i</sub> is a parent of a node b<sub>i</sub>. (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ N, a<sub>i</sub> ≠ b<sub>i</sub>) The root node is numbered by 1. It is guaranteed that a given graph is a rooted tree, i.e. there is exactly one parent for each node except the node 1, and the graph is connected.</p>

### 출력 

 <p>Print the number of the pairs (x, y) of the nodes such that the subtree with the root x and the subtree with the root y are similar and x < y.</p>

