# [Gold III] Blackboard Reconstruction - 20354 

[문제 링크](https://www.acmicpc.net/problem/20354) 

### 성능 요약

메모리: 80236 KB, 시간: 68 ms

### 분류

해 구성하기, 다이나믹 프로그래밍, 그래프 이론, 배낭 문제

### 제출 일자

2025년 5월 5일 13:08:58

### 문제 설명

<p>Harry is a mathematician who likes to play with graphs. He has drawn a weighted undirected graph on the blackboard, and computed that the length of the shortest path between two nodes is s. Unfortunately he has to leave the room, therefore he quickly writes down s and the weights of all edges on a piece of paper, and he wipes the blackboard. Then it dawns on him: this information is not enough to reconstruct his beautiful graph!</p>

<p>Write a program that constructs some graph matching the information that Harry wrote down.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers s and e (1 ≤ s ≤ 10<sup>4</sup>, 1 ≤ e ≤ 1 000), the length of the shortest path and the number of edges;</li>
	<li>e lines, each with an integer w (0 ≤ w ≤ 10<sup>4</sup>), the length of an edge.</li>
</ul>

### 출력 

 <p>Output a graph consisting of a number of 1-indexed nodes and exactly e edges, such that the edge lengths correspond to the lengths in the input, and the length of the shortest path between nodes 1 and 2 is s. The graph must be connected, must not contain self-loops and can have at most one edge between each pair of nodes. You may assume that such a graph exists.</p>

<p>The output must consist of:</p>

<ul>
	<li>one line with an integer n (2 ≤ n ≤ e + 1), the number of nodes;</li>
	<li>e lines, each with three integers a, b and w (1 ≤ a, b ≤ n), describing an edge between nodes a and b with length w.</li>
</ul>

<p>If there are multiple correct answers, you may give any of them.</p>

