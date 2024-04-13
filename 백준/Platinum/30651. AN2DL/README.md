# [Platinum III] AN2DL - 30651 

[문제 링크](https://www.acmicpc.net/problem/30651) 

### 성능 요약

메모리: 189524 KB, 시간: 2860 ms

### 분류

자료 구조, 덱, 덱을 이용한 구간 최댓값 트릭, 우선순위 큐

### 제출 일자

2024년 4월 14일 01:55:53

### 문제 설명

<p>While wandering around Building 21, you came across a wall completely covered with numbers, arranged in a table of n rows and m columns. Soon you noticed that there was a frame leaning against the wall large enough to frame r rows and s columns of the table on the wall. And next to the frame you found a pencil and a piece of paper containing an empty table.</p>

<p>You are sad that the table on the piece of paper is empty, so you decided to play around with the frame to fill it.</p>

<p>You leaned the frame against the wall so that the number in the i-th row and j-th column is in the upper left corner, and the borders of the frame are parallel to the edges of the wall. Considering the numbers inside the frame, and since you like large numbers, you have decided to write the largest among them in the i-th row and j-th column of the table on the piece of paper.</p>

<p>You repeated the process for every possible position of the frame on the wall (such that the frame is entirely on the wall, and that there are exactly r × s numbers inside it), making sure that the edges of the frame are parallel to the edges of the wall.</p>

<p>When you were done, the table on the piece of paper was even more beautiful than the one on the wall. What numbers are in the table on the piece of paper?</p>

### 입력 

 <p>The first line contains two integers n and m (1 ≤ n, m ≤ 4 000), the number of rows and columns of the table on the wall.</p>

<p>Each of the following n lines contain m integers a<sub>i,j</sub> (|a<sub>i,j</sub>| ≤ 10 000), where a<sub>i,j</sub> is the number in the i-th row and j-th column of the table on the wall.</p>

<p>The last line contains two integers r and s (1 ≤ r ≤ n, 1 ≤ s ≤ m), the size of the frame.</p>

### 출력 

 <p>Output the numbers written in the table on the piece of paper.</p>

