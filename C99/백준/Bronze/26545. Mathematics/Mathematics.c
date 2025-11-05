#include<stdio.h>
int main() {
	int n, d;
	scanf("%d", &n);

	int ans = 0;
	while (n--) {
		scanf("%d", &d);
		ans += d;
	}
	printf("%d", ans);
}