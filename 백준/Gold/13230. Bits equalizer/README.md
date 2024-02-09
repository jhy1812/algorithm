# [Gold IV] Bits equalizer - 13230 

[문제 링크](https://www.acmicpc.net/problem/13230) 

### 성능 요약

메모리: 19752 KB, 시간: 300 ms

### 분류

그리디 알고리즘, 구현

### 제출 일자

2024년 2월 10일 02:25:45

### 문제 설명

<p>You are given two non­empty strings S and T of equal lengths. S contains the characters ‘0’, ‘1’ and ‘?’, whereas T contains ‘0’ and ‘1’ only. Your task is to convert S into T in minimum number of moves. In each move, you can do one of these changes:</p>

<ol>
	<li>change a ‘0’in S to ‘1’</li>
	<li>change a ‘?’ in S to ‘0’ or ‘1’</li>
	<li>swap any two characters in S</li>
</ol>

<p>As an example, suppose S = “01??00” and T = “001010”. We can transform S into T in 3 moves:</p>

<ul>
	<li>Initially S = “01??00”</li>
	<li>Move 1 – change S[2] to ‘1’. S becomes “011?00”</li>
	<li>Move 2 – change S[3] to ‘0’. S becomes “011000”</li>
	<li>Move 3 – swap S[1] with S[4]. S becomes “001010”</li>
	<li>S is now equal to T.</li>
</ul>

### 입력 

 <p>The first line of input is an integer C (C ≤ 200) that indicates the number of test cases. Each case consists of two lines. The first line is the string S consisting of ‘0’, ‘1’ and ‘?’. The second line is the string T consisting of ‘0’ and ‘1’. The lengths of the strings won’t be larger than 100.</p>

### 출력 

 <p>For each case, output the case number first followed by the minimum number of moves required to convert S into T. If the transition is impossible, output −1 instead. Check the output example for the exact format.</p>

