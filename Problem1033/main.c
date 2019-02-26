#include <stdio.h>

int main() {
	int n, ax, ay, bx, by, cx, cy;
	scanf("%d%d%d%d%d%d%d", &n, &ax, &ay, &bx, &by, &cx, &cy);
	if ((bx - ax)*(cx - ax) >= 0 && (by - ay)*(cy - ay) >= 0) {
		printf("YES \n");
	}
	else {
		printf("NO \n");
	}
    return 0;
}