# [Platinum IV] Paintball - 11180 

[문제 링크](https://www.acmicpc.net/problem/11180) 

### 성능 요약

메모리: 2184 KB, 시간: 0 ms

### 분류

이분 매칭

### 제출 일자

2025년 10월 19일 22:13:58

### 문제 설명

<p>Marek and his schoolmates have just finished their studies at the university. They wanted to celebrate it with a game of paintball. After an hour of playing a very strange thing happened – everyone had exactly one bullet left. Marek, being a very curious person, wanted to know whether it’s possible that everyone will be hit exactly once provided nobody moves.</p>

<p>You are given a description of the situation during a paintball game when every player has only one bullet. The description of the game consists of pairs of players who can see each other. If a player can see another player, he can fire at him. Your task is to find a target for each player such that everyone will be hit.</p>

### 입력 

 <p>The first line of input contains two space separated integers N and M, satisfying 2 ≤ N ≤ 1 000 and 0 ≤ M ≤ 5 000, where N is the number of players. Players are numbered 1, 2, . . . , N. M lines follow, each line containing two space separated integers A and B (1 ≤ A < B ≤ N), denoting that players A and B can see each other. Each pair of players appears at most once in the input.</p>

### 출력 

 <p>If there is no assignment of targets such that everyone will be hit, output Impossible. Otherwise output N lines. The i-th line should contain the number of the target of the i-th player. If there is more than one solution, output any one.</p>

