# [Platinum V] False Intelligence - 15172 

[문제 링크](https://www.acmicpc.net/problem/15172) 

### 성능 요약

메모리: 4148 KB, 시간: 2472 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2024년 10월 29일 11:57:51

### 문제 설명

<p>Artificial Intelligence is taking over the world, or at least planning to do so soon. Machines will become so clever they can win all games, answer all your questions and make all decisions for you. Because this sounds quite scary, it has been proposed to give the machines a bit of human touch. This feature will make them pretend to not always know the answer to a question, but to express uncertainty from time to time.</p>

<p>Of course, secretly, the machines will still follow precise rules – those of threevalued logic invented by Jan Łukasiewicz. It adds to the two values F (false) and T (true) of Boolean logic a third value U (uncertain) and extends the logic operators as shown in the first three of the following tables:</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15172/1.png" style="height:101px; width:529px"></p>

<p>For example, F ∨ T = T as in Boolean logic, T ∧ U = U and F → U = T. Some functions cannot be expressed using the three operators AND, OR and IMPLIES. For example, f(x, y) = x → x is the constant T function, but there is no expression g(x, y) in terms of x, y, AND, OR and IMPLIES which is constant F.</p>

<p>Let us add the operator EQUALS shown in the right-most of the above tables. It captures equality of its two arguments by returning T if they are the same and F otherwise. Your task is to determine whether a given function g(x, y) can be expressed in terms of x, y, AND, OR, IMPLIES and EQUALS. This is important so the machines know their own limits.</p>

### 입력 

 <p>The first line of the input contains an integer n (1 ≤ n ≤ 20 000), which is the number of functions you have to consider. This is followed by n function descriptions.</p>

<p>Each function description consists of four lines. The first of these lines is empty. The remaining three lines describe a function g as a table of its values g(x, y). The table has three rows and three columns, corresponding to the values F, U, T of x and y, respectively. Its layout is like that of the tables shown above.</p>

### 출력 

 <p>For each function description in the same order as in the input, display one line containing either definable or undefinable. Display definable if the given function g(x, y) can be expressed in terms of x, y, AND, OR, IMPLIES and EQUALS. Display undefinable if g(x, y) cannot be expressed this way.</p>

