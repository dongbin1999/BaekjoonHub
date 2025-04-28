# [Gold II] One-sequence - 8071 

[문제 링크](https://www.acmicpc.net/problem/8071) 

### 성능 요약

메모리: 2152 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기, 수학

### 제출 일자

2025년 4월 28일 20:04:33

### 문제 설명

<p>We say that a sequence of integers is a one-sequence if the difference between any two consecutive numbers in this sequence is 1 or -1 and its first element is 0. More precisely: [a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>] is a one-sequence if:</p>

<ul>
	<li>for any k, such that 1 ≤ k < n: |a<sub>k</sub> - a<sub>k+1</sub>| = 1 and</li>
	<li>a<sub>1</sub> = 0.</li>
</ul>

<p>Write a program that:</p>

<ul>
	<li>reads two integers describing the length of the sequence and the sum of its elements, from the standard input;</li>
	<li>finds a one-sequence of the given length whose elements sum up to the given value or states that such a sequence does not exist;</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is a number n, such that 1 ≤ n ≤ 10,000, which is the number of elements in the sequence. In the second line there is a number S, which is the sum of the elements of the sequence, such that |S| ≤ 50,000,000.</p>

### 출력 

 <p>In the first n lines of the standard output there should be written n integers (one in each line) that are the elements of the sequence (k-th element in the k-th line) whose sum is S or the word <code>NIE</code> (which means “no” in Polish) if such a sequence does not exist.</p>

