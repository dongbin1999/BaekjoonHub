# [Silver I] Airport Walkways (Small) - 12483 

[문제 링크](https://www.acmicpc.net/problem/12483) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 그리디 알고리즘, 구현

### 제출 일자

2024년 6월 28일 14:08:18

### 문제 설명

<p>You're in an airport, standing at point 0. A corridor of length <strong>X</strong> leads to the gate, where your plane is about to leave. There are moving walkways in the corridor, each moving with some speed <strong>w<sub>i</sub></strong>. When you walk or run on one of those, you move with speed (your speed + <strong>w<sub>i</sub></strong>). The walkways do not change their position; they just make you move faster. The walkways do not overlap: at any given point of the corridor there is at most one walkway, but one walkway can begin at the point where another ends.</p>

<p>Your normal walking speed is <strong>S</strong>. You are worried that you might not catch your plane, though, so you can run a bit - you can run with speed <strong>R</strong> for at most <strong>t</strong> seconds in total. You do not have to run for <strong>t</strong> consecutive seconds: you can split these <strong>t</strong> seconds into any number of intervals, or even not use some part of them.</p>

<p>How long does it take you to get to the gate, assuming you choose when to walk and when to run in order to reach it as soon as possible?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. Each test case begins with a line containing five integers: <strong>X</strong> (the length of the corridor, in meters), <strong>S</strong>(your walking speed, in meters per second), <strong>R</strong> (your running speed, in meters per second), <strong>t</strong> (the maximum time you can run, in seconds) and <strong>N</strong> (the number of walkways).</p>

<p>Each of the next <strong>N</strong> lines contains three integers: <strong>B<sub>i</sub></strong>, <strong>E<sub>i</sub></strong> and <strong>w<sub>i</sub></strong> - the beginning and end of the walkway (in meters from your starting point) and the speed of the walkway (in meters per second).</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 40.</li>
	<li>1 ≤ <strong>S</strong> < <strong>R</strong> ≤ 100.</li>
	<li>1 ≤ <strong>w<sub>i</sub></strong> ≤ 100.</li>
	<li>0 ≤ <strong>B<sub>i</sub></strong> < <strong>E<sub>i</sub></strong> ≤ <strong>X</strong>.</li>
	<li><strong>E<sub>i</sub></strong> ≤ <strong>B<sub>i+1</sub></strong>.</li>
	<li>1 ≤ <strong>t</strong> ≤ 100.</li>
	<li>1 ≤ <strong>X</strong> ≤ 100.</li>
	<li>1 ≤ <strong>N</strong> ≤ 20.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the time (in seconds) you need to reach point <strong>X</strong> if you walk and run optimally. Answers with relative or absolute error of at most 10<sup>-6</sup> will be accepted.</p>

