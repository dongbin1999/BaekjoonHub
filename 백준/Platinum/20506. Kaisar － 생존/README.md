# [Platinum V] Kaisar - 생존 - 20506 

[문제 링크](https://www.acmicpc.net/problem/20506) 

### 성능 요약

메모리: 16612 KB, 시간: 96 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 수학, 트리

### 제출 일자

2023년 12월 22일 15:35:11

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f87417b6-be3b-4490-b7fb-4e2d6968b47c/-/preview/" style="height: 358px; width: 800px;"></p>

<p>준원이(0/5/3)는 생존해있는 카이사(2/7/0)를 찾으러 소환사의 협곡을 수색하고 있다. 협곡은 정점이 N개 있는 트리 모양이고, 정점은 1번 정점에서 N번 정점까지 번호 붙여져 있다. 준원이는 모든 정점 쌍 x, y에 대해 x번 정점과 y번 정점의 LCA를 방문해보고, 방문한 정점의 번호들을 모두 배열에 적어두었다. 여러 번 방문하면 여러 번 적었다.</p>

<p>하지만, 카이사는 없었다.</p>

<p>준원이는 탈주하고, 이 배열을 정렬한 뒤, 배열의 짝수번째 원소들의 합과 홀수번째 원소들의 합을 구하려 한다.</p>

<p><strong>참가자</strong> - 생존</p>

<p><strong>참가자</strong> - 생존</p>

### 입력 

 <p>첫째 줄에는 트리의 정점의 개수 N이 주어진다.</p>

<p>둘째 줄에는, 1번부터 N번까지 각 정점의 부모 정점의 번호를 나타내는 N개의 정수가 차례대로 주어진다. 루트 정점은 부모가 없으므로, 루트 정점의 차례에는 0이 주어진다.</p>

### 출력 

 <p>준원이가 정렬한 배열의 짝수번째 원소들의 합과 홀수번째 원소들의 합을 차례대로 공백을 사이에 두고 출력한다. <strong>출력하는 수가 32비트 정수 자료형의 범위를 넘을 수 있다는 점에 유의하라.</strong></p>

