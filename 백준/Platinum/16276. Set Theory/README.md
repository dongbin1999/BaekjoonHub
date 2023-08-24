# [Platinum V] Set Theory - 16276 

[문제 링크](https://www.acmicpc.net/problem/16276) 

### 성능 요약

메모리: 2160 KB, 시간: 936 ms

### 분류

해 구성하기

### 문제 설명

<p>Masha and Grisha like studying sets of positive integers.</p>

<p>One day Grisha has written a set A containing n different integers a<sub>i</sub> on a blackboard. Now he asks Masha to create a set B containing n different integers b<sub>j</sub> such that all n<sup>2</sup> integers that can be obtained by summing up a<sub>i</sub> and b<sub>j</sub> for all possible pairs of i and j are different.</p>

<p>Both Masha and Grisha don't like big numbers, so all numbers in A are from 1 to 10<sup>6</sup>, and all numbers in B must also be in the same range.</p>

<p>Help Masha to create the set B that satisfies Grisha's requirement.</p>

### 입력 

 <p>Input data contains multiple test cases. The first line contains an integer t — the number of test cases (1 ≤ t ≤ 100).</p>

<p>Each test case is described in the following way: the first line of the description contains one integer n — the number of elements in A (1 ≤ n ≤ 100).</p>

<p>The second line contains n integers a<sub>i</sub> — the elements of A (1 ≤ a<sub>i</sub> ≤ 10<sup>6</sup>).</p>

### 출력 

 <p>For each test first print the answer:</p>

<ul>
	<li>NO, if Masha's task is impossible to solve, there is no way to create the required set B.</li>
	<li>YES, if there is the way to create the required set. In this case the second line must contain n different positive integers b<sub>j</sub> — elements of B (1 ≤ b<sub>j</sub> ≤ 10<sup>6</sup>). If there are several possible sets, output any of them.</li>
</ul>

