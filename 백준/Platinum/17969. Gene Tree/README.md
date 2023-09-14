# [Platinum II] Gene Tree - 17969 

[문제 링크](https://www.acmicpc.net/problem/17969) 

### 성능 요약

메모리: 12652 KB, 시간: 68 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 문제 설명

<p>A <em>gene tree</em> is a tree showing the evolution of various genes or biological species. A gene tree represents the relatedness of specific genes stored at the leaf nodes without assumption about their ancestry. Leaf nodes represent genes, called <em>taxa</em>, and internal nodes represent putative ancestral taxa. Each edge in the tree is associated with a positive integer, <em>phylogenetic length</em>, which quantifies the evolutionary distance between two nodes of the edge. For example, the left figure below shows a gene tree with six leaf nodes, which approximates the relation among six taxa, and the right one shows a gene tree with four taxa.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b0de84fb-77f8-445e-aaca-2862a4c4c213/-/preview/" style="width: 426px; height: 252px;"></p>

<p style="text-align: center;">Figure B.1: Unrooted gene trees <em>T</em><sub>1</sub> and <em>T</em><sub>2</sub>.</p>

<p>Like the trees <em>T</em><sub>1</sub> and <em>T</em><sub>2</sub> above, gene trees are modeled as unrooted trees where each internal node (non-leaf node) has degree three. A path-length between two leaf nodes is the sum of the phylogenetic lengths of the edges along the unique path between them. In <em>T</em><sub>1</sub>, the path-length between Human and Cow is 2 + 3 = 5 and the path-length between Human and Goldfish is 2 + 4 + 8 + 10 = 24. These lengths indicate that Human is much closer to Cow than to Goldfish genetically. From <em>T</em><sub>2</sub>, we can guess that the primate closest to Human is Chimpanzee.</p>

<p>Researchers are interested in measuring the distance between genes in the tree. A famous distance measure is the sum of squared path-lengths of all unordered leaf pairs. More precisely, such a distance <em>d</em>(<em>T</em>) is defined as follows:</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D451 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-munder space="4"><mjx-row><mjx-base style="padding-left: 2.366em;"><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em;"><mjx-texatom size="s" texclass="ORD"><mjx-mtext class="mjx-n"><mjx-c class="mjx-c75"></mjx-c><mjx-c class="mjx-c6E"></mjx-c><mjx-c class="mjx-c6F"></mjx-c><mjx-c class="mjx-c72"></mjx-c><mjx-c class="mjx-c64"></mjx-c><mjx-c class="mjx-c65"></mjx-c><mjx-c class="mjx-c72"></mjx-c><mjx-c class="mjx-c65"></mjx-c><mjx-c class="mjx-c64"></mjx-c><mjx-c class="mjx-c20"></mjx-c><mjx-c class="mjx-c70"></mjx-c><mjx-c class="mjx-c61"></mjx-c><mjx-c class="mjx-c69"></mjx-c><mjx-c class="mjx-c72"></mjx-c><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-texatom></mjx-under></mjx-row></mjx-munder><mjx-texatom space="2" texclass="ORD"><mjx-msubsup><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45D TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.247em; margin-left: 0px;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-spacer style="margin-top: 0.347em;"></mjx-spacer><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-script></mjx-msubsup></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>d</mi><mo stretchy="false">(</mo><mi>T</mi><mo stretchy="false">)</mo><mo>=</mo><munder><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mtext>unordered pair </mtext><mo stretchy="false">(</mo><mi>u</mi><mo>,</mo><mi>v</mi><mo stretchy="false">)</mo></mrow></munder><mrow data-mjx-texclass="ORD"><msubsup><mi>p</mi><mrow data-mjx-texclass="ORD"><mi>u</mi><mo>,</mo><mi>v</mi></mrow><mn>2</mn></msubsup></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[d(T) = \sum_{\text{unordered pair } (u, v)}{p^2_{u, v}}\]</span> </mjx-container></p>

<p>where <em>p</em><sub><em>u</em>,<em>v</em></sub> is a path-length between two leaf nodes <em>u</em> and <em>v</em> in <em>T</em>. Note that <em>d</em>(<em>T</em>) is the sum of the squared path-lengths <em>p</em><sup>2</sup><sub><em>u</em>,<em>v</em></sub> over all unordered leaf pairs <em>u</em> and <em>v</em> in <em>T</em>. For the gene tree <em>T</em><sub>2</sub> in Figure B.1, there are six paths over all unordered leaf pairs, (Human, Chimpanzee), (Human, Gorilla), (Human, Orangutan), (Chimpanzee, Gorilla), (Chimpanzee, Orangutan), and (Gorilla, Orangutan). The sum of squared path-lengths is 2<sup>2</sup> + 4<sup>2</sup> + 5<sup>2</sup> + 4<sup>2</sup> + 5<sup>2</sup> + 5<sup>2</sup> = 111, so <em>d</em>(<em>T</em><sub>2</sub>) = 111.</p>

<p>Given an unrooted gene tree <em>T</em>, write a program to output <em>d</em>(<em>T</em>).</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (4 ≤ <em>n</em> ≤ 100,000), where <em>n</em> is the number of nodes of the input gene tree <em>T</em>. Then <em>T</em> has <em>n</em> − 1 edges. The nodes of <em>T</em> are numbered from 1 to <em>n</em>. The following <em>n</em> − 1 lines represent <em>n</em> − 1 edges of <em>T</em>, where each line contains three non-negative integers <em>a</em>, <em>b</em>, and <em>l</em> (1 ≤ a ≠ b ≤ <em>n</em>, 1 ≤ <em>l</em> ≤ 50) where two nodes <em>a</em> and <em>b</em> form an edge with phylogenetic length <em>l</em>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain one positive integer <em>d</em>(<em>T</em>).</p>

