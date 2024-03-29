# [Diamond V] 감성 테트리스 - 16856 

[문제 링크](https://www.acmicpc.net/problem/16856) 

### 성능 요약

메모리: 24092 KB, 시간: 116 ms

### 분류

이분 탐색, 자료 구조, 구현, 희소 배열

### 문제 설명

<p>디디는 1 X 4 'ㅡ'자, 4 X 1 'ㅣ'자 모양 블럭으로만 진행되는 테트리스를 하고 있다. 이 테트리스는 어떤 블럭의 떨어질 위치를 정하면 그 위치에서 수직방향으로 떨어지며, 수평방향으로 움직이거나 블럭을 회전시킬 수 없다. 또한 떨어지는 블럭의 아랫면이, 다른 블럭의 윗면 혹은 바닥과 1칸이라도 맞닿는다면, 이 블럭은 떨어지는 것을 멈추고 맞닿는 면 위에 쌓이게 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/66bdf674-ba61-4841-992a-986b536c36ef/-/preview/" style="width: 800px; height: 202px;"></p>

<p>'이 블럭이 떨어지면 그 밑에 있는 블럭들은 많이 아프겠ㄷr...' 테트리스를 감성으로 하는 디디는 어떤 블럭이 떨어질 때 하중을 받는 블럭의 개수를 구하려고 한다. 떨어지는 블럭의 아랫면과 면을 공유하는 블럭은 하중을 받으며, 하중을 받은 블럭들의 아랫면과 면을 공유하는 블럭들 또한 하중을 받게 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/01552d51-5532-45aa-9dc0-45affd7a5bd7/-/preview/" style="height: 122px; width: 600px;"></p>

<p style="text-align: center;"><빨간색 블럭은 이번에 떨어뜨린 블럭이며, 노란색 블럭은 이때 하중을 받는 블럭이다.></p>

<p>착한 leejseo는 감성이 풍부한 디디를 위해, 디디가 블럭을 떨어뜨릴 때마다 그 블럭의 하중을 받는 블럭의 개수를 구하는 프로그램을 작성하려고 한다. leejseo를 따라서 디디를 도와주자.</p>

### 입력 

 <p>첫째 줄에 디디가 떨어뜨린 블럭의 개수 <em>Q</em>(1 ≤ <em>Q</em> ≤ 10<sup>5</sup>)가 주어진다.<br>
둘째 줄부터 <em>Q</em>개의 각 줄에는 디디가 떨어뜨린 블럭에 대한 정보가 주어진다.<br>
각 줄은 아래 2개 중 하나의 형식을 가지고 있다.</p>

<ul>
	<li>1 <em>a</em> : 블럭의 왼쪽 끝 칸이 위치 <em>a</em>에 위치하게 'ㅡ'자 모양의 블럭을 떨어뜨린다.</li>
	<li>2 <em>a</em> : 위치 <em>a</em>에 'ㅣ'자 모양의 블럭을 떨어뜨린다.</li>
</ul>

<p>단, <em>a</em>는 항상 정수이며 블럭의 어떤 부분도 위치 1 ~ 400,000를 벗어나지 않는다.</p>

### 출력 

 <p><em>Q</em>개의 각 줄에 디디가 블럭을 떨어뜨릴 때마다 그 블럭의 하중을 받는 블럭의 개수를 출력하라.</p>

