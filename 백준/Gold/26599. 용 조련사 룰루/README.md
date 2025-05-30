# [Gold I] 용 조련사 룰루 - 26599 

[문제 링크](https://www.acmicpc.net/problem/26599) 

### 성능 요약

메모리: 17652 KB, 시간: 404 ms

### 분류

애드 혹, 해 구성하기, 정렬

### 제출 일자

2025년 4월 14일 08:59:43

### 문제 설명

<p>룰루는 '소환사의 협곡'에서 $N$ 마리의 용을 돌보는 용 조련사다. 용은 힘이라는 고유한 수치를 가지며 $i$번 용의 힘은 $P_{i}$다. 용의 힘은 서로 다르다.</p>

<p>어느 날 룰루는 용들이 반복되는 하루 속에서 지루함을 느끼고 있다는 걸 깨달았다. 그래서 모든 용들과 함께 '칼바람 나락'으로 소풍을 가려고 한다.</p>

<p>룰루는 한 번에 최대 한 마리의 용을 '소환사의 협곡'에서 '칼바람 나락'으로만 옮길 수 있다. 단, 용을 옮길 때에는 다음과 같은 주의사항이 있다.</p>

<p style="text-align: center;"><em>어떤 용 한 마리가 같은 장소에 있는 다른 모든 용에 비해 힘이 $M$보다 더 크다면 다른 용들을 학살하기 시작한다! </em></p>

<p>용들끼리 사이좋게 지내길 바라는 룰루를 위해 위와 같은 상황이 일어나지 않도록 '소환사의 협곡'에서 '칼바람 나락'으로 옮겨야 하는 용의 순서를 알려주도록 하자!</p>

### 입력 

 <p>첫째 줄에 $N$과 $M$이 공백을 사이에 두고 주어진다. $(1 \leq N \leq 1\,000\,000;$ $1 \leq M \leq 10^{9})$</p>

<p>둘째 줄에 용의 힘 $P_{i}$가 번호 순으로 공백을 사이에 두고 주어진다. $(1 \leq P_{i} \leq 10^{9})$</p>

<p>용을 한 마리도 옮기지 않은 상태에서 학살이 일어나는 경우는 주어지지 않으며 입력은 모두 정수로 주어진다.</p>

### 출력 

 <p>첫째 줄에 용들을 평화롭게 '소환사의 협곡'에서 '칼바람 나락'으로 옮길 수 있는 방법이 존재하면 <code>YES</code>, 없다면 <code>NO</code>를 출력한다.</p>

<p>옮길 수 있는 방법이 존재한다면 둘째 줄에 옮겨야 하는 순서대로 용의 번호를 공백을 사이에 두고 출력한다. 그러한 방법이 여러 개라면 아무거나 출력한다.</p>

