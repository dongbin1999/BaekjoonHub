# [Platinum IV] Brackets - 13291 

[문제 링크](https://www.acmicpc.net/problem/13291) 

### 성능 요약

메모리: 75296 KB, 시간: 76 ms

### 분류

다이나믹 프로그래밍, 수학

### 문제 설명

<p>A bracket sequence consisting of ‘(’ and ‘)’ is defined to be valid as follows:</p>

<ol>
	<li>An empty sequence is valid.</li>
	<li>If X is a valid bracket sequence, then (X) is a valid bracket sequence.</li>
	<li>If X and Y are valid bracket sequences, then the concatenation of X and Y , Z = XY , is a valid bracket sequence.</li>
</ol>

<p>For example, “(())”, “()()”, and “(()())()” are all valid bracket sequences, while “(” and “())” are invalid bracket sequences.</p>

<p>You get a bracket sequence from the professor of length n. However, it might not be valid at the moment. The professor asks you to check if it is possible to make the sequence valid by performing at most one segment inversion operation. That is, you may choose two 1-based indices l and r (1 ≤ l ≤ r ≤ n) and invert each bracket with an index in the closed interval [l, r]. After the inversion, a left bracket ‘(’ becomes a right bracket ‘)’, and a right bracket ‘)’ becomes a left bracket ‘(’.</p>

<p>You can make “())(” valid by inverting the segment [3, 4]. You can make “()))” valid by inverting the segment [3, 3], or alternatively by inverting the segment [2, 2]. However, there does not exist a segment you can invert to make “)))(” valid.</p>

### 입력 

 <p>The input consists of one line containing between 1 and 5 000 brackets.</p>

### 출력 

 <p>Output “possible” if you can make the bracket sequence valid by performing at most one segment inversion, or “impossible” otherwise.</p>

