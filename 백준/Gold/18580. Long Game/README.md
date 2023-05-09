# [Gold I] Long Game - 18580 

[문제 링크](https://www.acmicpc.net/problem/18580) 

### 성능 요약

메모리: 2412 KB, 시간: 16 ms

### 분류

게임 이론

### 문제 설명

<p>Alice and Bob play a long game with a permutation p = (p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>n</sub>) of n integers from 1 to n. The permutation is written on a single strip. Alice makes her turn first, then the players take alternating turns. The player who is unable to make a move loses.</p>

<p>In the i-th turn, the player chooses one of the i strips, denote its length by m ≥ 2. Then he or she chooses an integer k (1 ≤ k < m) and cuts the chosen strip into two new strips with their lengths k and m − k. Here k means the index of an element of the chosen strip which becomes the last element of the first cut part, so the (k + 1)-th element goes to the beginning of the second part. But the following condition must hold after the cut: there should be at least one strip among all remaining strips whose elements form at least one inversion (that is, a pair of indices i, j such that i < j and p<sub>i</sub> > p<sub>j</sub>). If this condition is not met, a move is considered illegal and cannot be made. Note that the order of elements on newly formed strips does not change, and the players are not allowed to reverse or swap elements of any strip.</p>

<p>Given a permutation p of n integers, determine who wins if both players play optimally.</p>

### 입력 

 <p>The first line contains a single integer n (2 ≤ n ≤ 10<sup>5</sup>), the length of the permutation.</p>

<p>The second line contains n space-separated integers p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>n</sub> (1 ≤ p<sub>i</sub> ≤ n, all p<sub>i</sub> are distinct): the permutation itself.</p>

### 출력 

 <p>Print a single word “Alice” if the first player wins, or “Bob” otherwise.</p>

