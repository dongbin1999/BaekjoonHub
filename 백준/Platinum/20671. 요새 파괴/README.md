# [Platinum III] 요새 파괴 - 20671 

[문제 링크](https://www.acmicpc.net/problem/20671) 

### 성능 요약

메모리: 9604 KB, 시간: 128 ms

### 분류

이분 탐색, 자료 구조, 분리 집합, 스위핑

### 문제 설명

<p><em>N</em>개의 블럭들이 쌓여 요새를 만든다. 각각의 블럭은 서로 겹치지 않게 <em>H</em>층에서 <em>L</em>칸에서 <em>R</em>칸까지의 구간을 차지한다. 1층의 블럭을 제외한 다른 블럭들은 항상 아래층에 어떤 블럭이 존재한다. 이때 위에 쌓여 있는 블럭은 아래에 있는 블럭의 구간 안에 전부 포함된다. 즉, 임의의 i 번 블럭의 위에 쌓이는 모든 j번 블럭에 대해서 <em>L<sub>i</sub> ≤ L<sub>j</sub> ≤ R<sub>j</sub> ≤ R<sub>i</sub></em>가 성립한다. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0372705b-c2bd-4d22-9cf8-bec21fe70483/-/preview/" style="height: 337px; width: 700px;"></p>

<p>이러한 요새를 파괴하기 위해 미사일 폭격이 <em>K</em>번 이루어졌다. 각 폭격은 위치 <em>X</em>에 위력 <em>P</em>인 미사일이 발사되었고, 요새의 <em>X</em> 위치에 있는 블럭 중 위에서부터 최대 <em>P</em>개의 블럭을 파괴한다. 이때 블럭이 제거되는 과정에서 아래에 깔려 있던 블럭이 제거되는 경우 위에 있는 블럭은 피해 없이 그대로 아래로 내려온다.</p>

<p>다음 그림은 위치 <em>X</em>=5에 위력 <em>P</em>=1인 미사일이 발사되는 모습이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/69de5526-77b6-4a19-a7a0-42399452a783/-/preview/" style="width: 1000px; height: 252px;"><br>
 </p>

<p>폭격된 순서대로 각 폭격에 대하여 파괴된 블럭의 개수를 구하시오.</p>

### 입력 

 <p>첫 줄에 블럭의 개수 <em>N</em>이 주어진다. (1 ≤ <em>N</em> ≤ 100,000)</p>

<p>다음 <em>N</em>줄에 걸쳐 요새를 이루고 있는 블럭의 정보 <em>H</em>, <em>L</em>, <i>R</i>가 주어진다. (1 ≤ <em>H</em> ≤ <em>N, </em>1 ≤ <i>L</i> ≤ <i>R</i> ≤ 1,000,000,000)</p>

<p>다음 줄에 폭격의 횟수 <em>Q</em>가 주어진다. (1 ≤ <em>Q</em> ≤ 100,000)</p>

<p>다음 <em>Q</em>줄에 걸쳐 폭격의 위치 <em>X</em>와 위력 <em>P</em>가 주어진다. (1 ≤ <em>X</em> ≤ 1,000,000,000, 1 ≤ <em>P</em> ≤ <em>N</em>)</p>

### 출력 

 <p>폭격된 순서대로 각 폭격에 대하여 파괴된 블럭의 개수를 출력한다.</p>

