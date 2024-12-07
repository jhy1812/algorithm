# [Silver II] Labels - 19658 

[문제 링크](https://www.acmicpc.net/problem/19658) 

### 성능 요약

메모리: 51972 KB, 시간: 556 ms

### 분류

사칙연산, 수학

### 제출 일자

2024년 12월 7일 23:39:05

### 문제 설명

<p>Today is the first day of work for Charles the Courier. He has been tasked with delivering N packages where each package has a (not necessarily unique) label number between 1 and N inclusive. At the end of each day, he is required to report a sequence A of N integers A<sub>1</sub>, . . . , A<sub>N</sub> where A<sub>i</sub> is the label number of the i<sup>th</sup> delivered package.</p>

<p>A mathematician at heart, Charles decides to use delta encoding to save on memory space and records a sequence D of N − 1 integers D<sub>1</sub>, . . . , D<sub>N−1</sub> instead, where D<sub>i</sub> = A<sub>i+1</sub> − A<sub>i</sub>.</p>

<p>After delivering all the packages, Charles realises that he does not know how to recover A from D. Your task today is to help him, or state that it is not possible to uniquely recover A.</p>

### 입력 

 <p>Your program must read from standard input.</p>

<p>The first line contains a single integer N, the total number of packages.</p>

<p>The second line contains N − 1 space-separated integers, D<sub>1</sub>, . . . , D<sub>N−1</sub>. D<sub>i</sub> represents the difference between the label numbers of the (i + 1)<sup>th</sup> and i<sup>th</sup> delivered package.</p>

### 출력 

 <p>Your program must print to standard output.</p>

<p>If it is possible to uniquely recover A from D, your output should contain N space-separated integers, the sequence A.</p>

<p>Otherwise, your output should contain a single integer on a single line, the integer -1.</p>

