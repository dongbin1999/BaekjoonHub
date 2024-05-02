# [Platinum III] 뜨끈한 돼지국밥 - 17948 

[문제 링크](https://www.acmicpc.net/problem/17948) 

### 성능 요약

메모리: 197532 KB, 시간: 300 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 5월 2일 11:01:24

### 문제 설명

<p>“국밥 먹을바엔 뜨끈-하고 든든-한 돼지국밥 먹고 말지”</p>

<p>평소 돼지국밥에 대한 애정이 남다른 성우는 국밥의 인기가 치솟고 있는 시대 흐름에 발맞추어 돼지국밥 체인점으로 사업을 시작해보려고 한다. 전국적으로 사업을 넓히기 이전에 성우는 자신이 살고 있는 마을에서 먼저 사업을 시작하려고 한다.</p>

<p>성우가 살고있는 동네는 일직선의 해안도로를 따라 길게 형성되어 있다. 해안도로를 기준으로 한쪽에는 바다가 있고, 다른 한쪽에는 사람들의 거주지가 있다. 사람들의 거주지는 일정한 간격으로 길가를 따라 일렬로 있고, 1번부터 50,000번까지의 자연수를 주소로 사용하고 있다. 임의의 두 거주지 사이의 거리는 두 거주지의 주소값의 차이와 같다.</p>

<p>성우는 사업을 시작하기 전 초기 비용이 얼마나 필요할지 계산했다. 그 결과 사업에 필요한 초기 비용은 체인점 건설비용과 총 배달비의 합과 같다는 결론을 내렸다. 배달비가 얼마 나올지 계산을 정확하게 하기 위해 성우는 마을 사람들을 대상으로 돼지국밥을 시켜 먹을 의향이 있는지 설문조사를 했고, 배달시킬 사람들의 주소를 알게 되었다. 체인점의 수를 K, 체인점 하나를 짓는 비용을 M, 기름값을 C, 배달시킬 사람들의 수를 N, 배달시킬 사람들의 주소정보를 L로 설정하여 식으로 표현하면 아래와 같다.</p>

<p>성우는 사업을 시작하기 전 초기 비용이 얼마나 필요할지 계산했다. 그 결과 사업에 필요한 초기 비용은 체인점 건설비용과 총 배달비의 합과 같다는 결론을 내렸다. 배달비가 얼마 나올지 계산을 정확하게 하기 위해 성우는 마을 사람들을 대상으로 돼지국밥을 시켜 먹을 의향이 있는지 설문조사를 했고, 배달시킬 사람들의 주소를 알게 되었다. 체인점의 수를 K, 체인점 하나를 짓는 비용을 M, 기름값을 C, 배달시킬 사람들의 수를 N, 배달시킬 사람들의 주소 정보를 L로 설정하여 식으로 표현하면 아래와 같다.</p>

<p style="text-align: center;"><img src="data:image/png;base64,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" style="width:204px; height:46px"></p>

<p style="text-align: center;">f(x)=주소가 x인 지점에서 가장 가까운 체인점 까지의 거리</p>

<p>체인점은 1번부터 50000번 사이의 모든 주소에 지을 수 있고, 성우는 지어야 하는 체인점의 수가 주어지면, 그때의 초기비용이 최소가 되도록 체인점의 위치를 배치하는 능력이 있다. 그렇기 때문에, 성우는 초기비용을 최소로 만드는 체인점의 수를 알려고 한다. 성우를 도와 초기 비용의 최솟값과 그때 지어야 하는 체인점의 수를 출력하자.</p>

<p>단, 초기 비용이 같은 경우 지어야 하는 체인점의 수가 더 적은 것을 선택한다.</p>

### 입력 

 <p>첫째 줄에 배달시켜 먹을 사람들의 수 N이 정수로 주어진다. (1 ≤ N ≤ 5,000)</p>

<p>둘째 줄에 배달시켜 먹을 사람들의 주소들이 빈 칸을 기준으로 구분되어 주어진다.</p>

<p>셋째 줄에는 기름값 C와 체인점을 하나 짓는데 드는 금액 M이 자연수로 주어진다.(1 ≤ C ≤ 1,000, 1 ≤ M ≤ 1,000,000)</p>

### 출력 

 <p>초기 비용의 최솟값과, 그때 지어야 하는 체인점의 수를 출력하라.</p>

