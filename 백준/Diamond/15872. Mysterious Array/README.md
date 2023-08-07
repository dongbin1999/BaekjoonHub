# [Diamond V] Mysterious Array - 15872 

[문제 링크](https://www.acmicpc.net/problem/15872) 

### 성능 요약

메모리: 27428 KB, 시간: 776 ms

### 분류

자료 구조, 그리디 알고리즘, 세그먼트 트리, 스위핑, 트리를 사용한 집합과 맵

### 문제 설명

<p>There is an array that contains a permutation of the numbers 1, 2, . . . , N (i.e., each number appears exactly once in the array). The elements of the array are 1-indexed.</p>

<p>However, you don’t know the contents of the array. Instead, you are given the results of Q queries of the form “what is the minimum value between positions a and b?”</p>

<p>Your task is to count the number of arrays that match the queries.</p>

### 입력 

 <p>The first input line contains two integers N and Q: the size of the array and the number of queries.</p>

<p>Then there are Q lines that describe the queries. Each line contains three integers a, b, and x (1 ≤ a ≤ b ≤ N and 1 ≤ x ≤ N): the minimum value between positions a and b is x.</p>

<p>Note that the results of the queries might be inconsistent, and it is possible that no array matches them.</p>

### 출력 

 <p>Print one integer: the number of arrays modulo 10<sup>9</sup> + 7.</p>

