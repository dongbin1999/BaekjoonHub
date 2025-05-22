# [Gold IV] Zig Zag Nametag - 11230 

[문제 링크](https://www.acmicpc.net/problem/11230) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 많은 조건 분기, 해 구성하기, 그리디 알고리즘, 문자열

### 제출 일자

2025년 5월 22일 23:51:03

### 문제 설명

<p>When ninjas go to conferences they wear fake nametags. One ninja in particular wants to impress his Sensei. His Sensei chooses a new favorite number every day. The pupil wants to put a name on his nametag that encodes his Sensei’s favorite number! This name will consist of only lower case letters. He assigns a value to each letter, based on its position in the alphabet (e.g. a = 1, b = 2, ..., z = 26). Then, he encodes the Sensei’s number by adding up the absolute values of the differences of every consecutive pair of letters. For example, the string azxb has the value of:</p>

<p style="text-align:center">|a − z| + |z − x| + |x − b| = |1 − 26| + |26 − 24| + |24 − 2| = 49</p>

<p>The name that the ninja will write on his nametag is the shortest string that encodes to his Sensei’s favorite number. If there’s more than one string of the shortest length, he’ll choose the one that comes first alphabetically. Given the Sensei’s favorite number, k, find the string that the ninja should put on his nametag.</p>

### 입력 

 <p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. Each input consists of a single line with a single integer k (1 ≤ k ≤ 1 000 000), which is the Sensei’s favorite number. There will always be a name that encodes to the Sensei’s number.</p>

### 출력 

 <p>Output a single line with a string of lower case letters, which is the name that the ninja should put on the nametag to impress the Sensei.</p>

