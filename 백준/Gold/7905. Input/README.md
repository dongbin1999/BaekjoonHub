# [Gold V] Input - 7905 

[문제 링크](https://www.acmicpc.net/problem/7905) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 많은 조건 분기, 기하학, 구현, 수학

### 제출 일자

2024년 6월 19일 23:05:00

### 문제 설명

<p>In a recent programming contest, one of the problems was about tiling floors with rectangular tiles. The input specification reads like this:</p>

<blockquote>
<p>The input contains several floors. The first line of the input gives the number of floors.</p>

<p>Each floor is described in several lines. The first line contains two positive integers: the length and width of the floor, in millimeters. A floor is at most 40 000 mm long or wide. The next line contains a single number: the number t of tiles (1 t 100). The following t lines each contain the description of a tile. A tile is given as four integers:</p>

<p>xl yl xh yh</p>

<p>where (xl, yl) are the coordinates of the lower left corner of the tile, and (xh, yh) are the coordinates of the upper rightmost corner of the tile. A tile always has a positive area. The order of the coordinates of the floor and those of the tile coincide, of course.</p>

<p>You may assume that the tiles are mutually disjoint, and cover the floor, the whole floor, and nothing but the floor.</p>
</blockquote>

<p>The last line of this specification raised some problems. Not for the contestants, but for the judges. Some of the test cases consist of many tiles. How can we be sure that our input file meets this condition? What we need is a checking program that verifies this condition.</p>

<p>Given an input file in the above format, find out for each floor whether the tiles</p>

<ol>
	<li>are disjoint,</li>
	<li>do not lie outside the floor,</li>
	<li>do cover the floor.</li>
</ol>

### 입력 

 <p>The input contains several floors. The first line of the input gives the number of floors. Each floor is described in several lines. The first line contains two positive integers: the length and width of the floor, in millimeters. A floor is at most 40 000 mm long or wide. The next line contains a single number: the number t of tiles (1 ≤ t ≤ 100). The following t lines each contain the description of a tile. A tile is given as four integers:</p>

<p>xl yl xh yh</p>

<p>where (xl, yl) are the coordinates of the lower left corner of the tile, and (xh, yh) are the coordinates of the upper rightmost corner of the tile. A tile always has a positive area. The order of the coordinates of the floor and those of the tile coincide, of course.</p>

### 출력 

 <p>For each floor the output contains a single line, containing one of the following words:</p>

<ul>
	<li><code>NONDISJOINT</code> if overlapping tiles occur;</li>
	<li><code>NONCONTAINED</code> if no overlapping tiles occur, but some tiles go outside the floor;</li>
	<li><code>NONCOVERING</code> if no overlapping tiles occur, and no tiles go outside the floor, but some parts of the floor are not covered;</li>
	<li><code>OK</code> if none of these is true.</li>
</ul>

