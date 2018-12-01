#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
int floor(int N, int K, int str[]) {
	if (N < 0)
		return -1;
	if (str[N] > K)
		floor(N - 1, K, str);
	else
		return str[N];

}
int ceiling(int SRT, int N, int K, int str[]) {
	if (SRT > N)
		return -1;
	if (str[SRT] < K)
		ceiling(SRT + 1, N, K, str);
	else
		return str[SRT];	
}
int main() {
	int N, K;
	int f, c;
	int buffer[MAX];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &buffer[i]);
	}
	scanf("%d", &K);
	f = floor(N-1, K, buffer);
	c = ceiling(0, N-1, K, buffer);
	
	printf("%d\n%d\n", f, c);
}