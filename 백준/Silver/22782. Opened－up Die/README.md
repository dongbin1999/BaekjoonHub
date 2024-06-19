# [Silver I] Opened-up Die - 22782 

[문제 링크](https://www.acmicpc.net/problem/22782) 

### 성능 요약

메모리: 2036 KB, 시간: 8 ms

### 분류

백트래킹, 브루트포스 알고리즘

### 제출 일자

2024년 6월 19일 18:21:59

### 문제 설명

<blockquote>
<p>The die is cast.</p>

<p>— Julius Caesar (100 B.C. – 45 B.C.)</p>
</blockquote>

<p>Dice have a very long history. It is not clear when and where dice are originated. It is known, however, that dice have been used in Egypt since the time before the year of 3000 B.C.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3e50eb02-2e13-404a-ace0-83dd1d0b68c6/-/preview/" style="width: 234px; height: 173px;"></p>

<p style="text-align: center;">Figure 1: Picture of dice</p>

<p>Dice are sometimes represented by their nets as shown in Figure 2 when they are depicted on a plane. As you know, there are a number of nets that represent the same dice. In this problem, however, we consider only nets of the same shape as the one shown in Figure 2. For our convenience, we index the faces as shown in Figure 3.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cea79495-81e0-4e80-a20e-e87ecb648ab1/-/preview/" style="width: 234px; height: 173px;"></p>

<p style="text-align: center;">Figure 2: Net of die</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/32c35460-12d0-4e08-8b71-a7b676e8f06a/-/preview/" style="width: 234px; height: 173px;"></p>

<p style="text-align: center;">Figure 3: Indices of faces</p>

<p>One day, Dr. M introduced the concept of the optimum nets of dice. He defined the net with the minimum M-value as optimal. The M-value is given by the sum of differences of the numbers on adjacent faces of the net. For Figure 2, the M-value is |1 − 4| + |2 − 4| + |4 − 5| + |5 − 3| + |4 − 6| = 9. Because Dr. M has a little misunderstanding about dice, the sum of the numbers on the opposite faces is not always seven. Nevertheless, each face has a number from one to six, and no two different faces have the same number.</p>

<p>As a result of his research, he discovered the optimum nets under various conditions. However, unfortunately, part of his nets got unable to read because he had spilt coffee over his notebook by mistake.</p>

<p>Your task is to write a program to recover his nets of dice from their parts.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/151d1929-ddf7-415f-aa74-f18ae477f411/-/preview/" style="width: 234px; height: 173px;"></p>

<p style="text-align: center;">Figure 4: Net given as the sample input; unreadable faces indicated by empty.</p>

### 입력 

 <p>The first line of the input contains one positive integer T indicating the number of test cases. The following T lines contain the test cases.</p>

<p>Each test case consists of only one line that contains six characters, each of which is either a digit from ‘1’ to ‘6’, or a lowercase ‘x’. The i-th character corresponds to the face indexed i in Figure 3. A digit represents the number on the face; a ‘x’ indicates that the number is unreadable, thus must be determined by your program. No test case contains more than one same digit.</p>

### 출력 

 <p>For each test case, output one line containing six digits that denote the optimum net under the condition that numbers on faces given in the input must be unchanged. The i-th digit must represent the number on the face indexed i in Figure 3, as in the input. If there is more than one solution, output any of them.</p>

