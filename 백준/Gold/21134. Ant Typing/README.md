# [Gold IV] Ant Typing - 21134 

[문제 링크](https://www.acmicpc.net/problem/21134) 

### 성능 요약

메모리: 2272 KB, 시간: 100 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2024년 7월 12일 02:32:59

### 문제 설명

<p>Consider a configurable keyboard where keys can be moved about. An ant is walking on the top row of this keyboard and needs to type a numeric string. The ant starts on the leftmost key of the top row, which contains $9$ keys, some permutation of the digits from $1$ to $9$. On a given second, the ant can perform one of three operations:</p>

<ol>
	<li>Stay on that key. The digit corresponding to that key will be entered.</li>
	<li>Move one key to the left. This can only happen if the ant is not on the leftmost key.</li>
	<li>Move one key to the right. This can only happen if the ant is not on the rightmost key.</li>
</ol>

<p>Compute the minimum number of seconds needed for the ant to type out the given numeric string, over all possible numeric key permutations.</p>

### 입력 

 <p>The single line of input contains a single string $s$ ($1 \le |s| \le 10^5$) consisting only of numeric digit characters from $1$ to $9$. This is the numeric string that the ant needs to type.</p>

### 출력 

 <p>Output a single integer, which is the minimum number of seconds needed for the ant to type out the given numeric string, over all possible numeric key permutations.</p>

