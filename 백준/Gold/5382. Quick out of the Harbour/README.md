# [Gold III] Quick out of the Harbour - 5382 

[문제 링크](https://www.acmicpc.net/problem/5382) 

### 성능 요약

메모리: 3284 KB, 시간: 272 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 11월 6일 10:46:46

### 문제 설명

<p>Captain Clearbeard decided to go to the harbour for a few days so his crew could inspect and repair the ship. Now, a few days later, the pirates are getting landsick<sup>1</sup>. Before all of the pirates become too sick to row the boat out of the harbour, captain Clearbeard decided to leave the harbour as quickly as possible.</p>

<p>Unfortunately the harbour isn’t just a straight path to open sea. To protect the city from evil pirates, the entrance of the harbour is a kind of maze with drawbridges in it. Every bridge takes some time to open, so it could be faster to take a detour. Your task is to help captain Clearbeard find the fastest way out to open sea.</p>

<p>The pirates will row as fast as one minute per grid cell on the map. The ship can move only horizontally or vertically on the map. Making a 90 degree turn does not take any extra time.</p>

<p><sup>1</sup>Pirates get landsick when they don’t get enough of the ships’ rocking motion. That’s why pirates often try to simulate that motion by drinking rum.</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with three integers, h, w (3 ≤ h, w ≤ 500), and d (0 ≤ d ≤ 50), the height and width of the map and the delay for opening a bridge.</li>
	<li>h lines with w characters: the description of the map. The map is described using the following characters:
	<ul>
		<li>‘S’, the starting position of the ship.</li>
		<li>‘.’, water.</li>
		<li>‘#’, land.</li>
		<li>‘@’, a drawbridge.</li>
	</ul>
	</li>
</ul>

<p>Each harbour is completely surrounded with land, with exception of the single entrance.</p>

### 출력 

 <p>For every test case in the input, the output should contain one integer on a single line: the travelling time of the fastest route to open sea. There is always a route to open sea. Note that the open sea is not shown on the map, so you need to move outside of the map to reach open sea.</p>

