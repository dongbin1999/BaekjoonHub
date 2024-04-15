# [Platinum I] Kocke - 30652 

[문제 링크](https://www.acmicpc.net/problem/30652) 

### 성능 요약

메모리: 783584 KB, 시간: 1912 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 4월 15일 17:34:34

### 문제 설명

<p>For his thirteenth birthday, Donald’s parents bought him a brand-new set of Lego cubes. In the set, there are n cubes of equal size, where the i-th cube came in color i. Using these cubes he decided to build a wall.</p>

<p>Donald will build his wall on a row-like Lego base that has k places where cubes can be put in. He puts the cubes in the following way:</p>

<ul>
	<li>First, he puts the cube with color 1 on an arbitrary spot on the base.</li>
	<li>For each cube from 2 to n, he places it in a spot neighboring the previously placed cube. If that spot isn’t empty, he puts the new cube on top of all the others.</li>
</ul>

<p>After he built the wall, Donald wrote on a piece of paper a sequence of length k: on the i-th position in the sequence he wrote the color of the top cube in the i-th place, or 0 if there isn’t a cube in that place.</p>

<p>He immediately asked himself how many different sequences could he have written on the piece of paper. Two sequences are considered different if there exists a position in which they differ. After some time, he has managed to calculate the solution, but he is not sure whether it is correct, so he asks for your help.</p>

### 입력 

 <p>The only line has integers n and k (2 ≤ n, k ≤ 5 000), the number of cubes, and the length of the base.</p>

### 출력 

 <p>In the only line, print the answer to Donald’s question, modulo 10<sup>9</sup> + 7.</p>

