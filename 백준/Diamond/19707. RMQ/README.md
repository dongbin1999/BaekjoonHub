# [Diamond V] RMQ - 19707 

[문제 링크](https://www.acmicpc.net/problem/19707) 

### 성능 요약

메모리: 9416 KB, 시간: 120 ms

### 분류

자료 구조, 세그먼트 트리

### 문제 설명

<p>Kraw the Krow has N cows. Each cow wears a tag containing a unique number from 0 to N − 1. The cows are lined up in a row in some unknown order. The positions of the cows are labelled from 0 to N − 1 in order.</p>

<p>For reasons that we will probably never know, Kraw found the need to answer an embarrassingly large number of Range Minimum Queries (RMQs). RMQs are questions of the form, ”What is the smallest tag number of the cows standing at or between positions L and R?”</p>

<p>Kraw is very lazy, so he paid Coco the Code Monkey less than minimum wage to solve the RMQs for him. Coco completed all of them four minutes before the deadline, and Kraw was very pleased.</p>

<p>That was in 2013. Now, Kraw is making a big loss in his Cow Tagging conglomerate and is starting to doubt the authenticity of Coco’s work. For all he knew, Coco could have just randomly generated answers to all the RMQs.</p>

<p>Unfortunately, after so many years, all the cows have dispersed and Coco is suspisciously uncontactable. Help Kraw check if there exists any ordering of cows such that all of Coco’s answers are valid.</p>

### 입력 

 <p>Your program should read the input from standard input. The input consists of:</p>

<ul>
	<li>one line with two integers N (1 ≤ N ≤ 100 000), the number of cows, and Q (1 ≤ Q ≤ 100 000), the number of RMQs;</li>
	<li>Q lines, with the i-th line containing three integers: L<sub>i</sub> and R<sub>i</sub> (0 ≤ L<sub>i</sub> ≤ R<sub>i</sub> < N), the left and right bounds of the i-th RMQ, and A<sub>i</sub> (0 ≤ A<sub>i</sub> < N), Coco’s answer to the RMQ.</li>
</ul>

### 출력 

 <p>Output one line containing N space-separated integers: any possible ordering of cows such that A<sub>i</sub> is the correct answer to the RMQ [L<sub>i</sub>, R<sub>i</sub>] for all i, and no two cows share the same tag number.</p>

<p>If there does not exist any such ordering of cows, fill all N integers with −1.</p>

