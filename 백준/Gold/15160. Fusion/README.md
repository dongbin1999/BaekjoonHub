# [Gold I] Fusion - 15160 

[문제 링크](https://www.acmicpc.net/problem/15160) 

### 성능 요약

메모리: 16972 KB, 시간: 208 ms

### 분류

0-1 너비 우선 탐색, 데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 11월 19일 10:39:59

### 문제 설명

<p>What a time to be alive! Today, the very first cold fusion reactor has just been built and cleared for operation. Of course, when the reactor is started for the first time, nothing happens.</p>

<p>Bewildered physicists pore over their calculations looking for errors. Countless double-checks and triple-checks are made before a trio of engineers discover the problem: two atoms in the reactor have become α-stuck!</p>

<p>The reactor can be thought of as a grid of cells with R rows and C columns. Each cell is either empty, contains a deuterium atom (two of which are α-stuck) or is blocked off by a control rod to prevent runaway reactions. Each cell is adjacent to the four cells to its left, right, top and bottom (cells on the edge of the reactor are adjacent to fewer than four cells).</p>

<p>You can issue fusion instructions to the reactor by specifying two atoms to be fused. Be wary; two atoms can be fused only if they are in adjacent cells or there is a path of adjacent empty cells from one atom to the other. When two atoms are fused, they will produce helium which floats away, effectively removing the two original atoms from the reactor (leaving the cells empty).</p>

<p>In order to fix the problem in the reactor, you will need to fuse the α-stuck atoms with each other. What is the fewest number of instructions you need to give to the reactor in order to fuse the α-stuck atoms?</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15160/1.png" style="height:107px; width:611px"></p>

<p style="text-align:center">Figure F.1: This is the reactor for Sample Input 1. Black squares denote blocked off cells, blue circles denote deuterium atoms and the yellow circles denote the two α-stuck atoms. One optimal sequence of fusions is shown.</p>

<p>Will you and your fellow engineers overcome the final barrier to cold fusion?</p>

### 입력 

 <p>The first line of input contains two integers R (1 ≤ R ≤ 1000), which is the number of rows in the reactor, and C (1 ≤ C ≤ 1000), which is the number of columns in the reactor. The next R lines describe the reactor. Each of these lines is a string with exactly C characters.</p>

<ul>
	<li>‘.’ denotes an empty cell.</li>
	<li>‘#’ denotes a blocked cell.</li>
	<li>‘O’ denotes a cell containing a deuterium atom.</li>
	<li>‘A’ denotes a cell containing an α-stuck atom.</li>
</ul>

<p>There are exactly two ‘A’s in the input.</p>

### 출력 

 <p>Display the minimum number of fusion instructions needed to fuse the α-stuck atoms. If it is not possible to fuse the α-stuck atoms together, display -1 instead.</p>

