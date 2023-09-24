#include <stdio.h>
int stack[10] = { 0 }; // 배열 크기 10인 배열 생성
int top = -1; //스택의 현재 위치

int main(void) {
	int choice = 0;
	int push_num = 0;
	
	while(1) {
		printf("1: push, 2 : pop, 3 : stack status, 0 : exit \n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			if (top < 10) {
				printf("넣을 숫자를 입력해주세요:");
				scanf_s("%d", &push_num);
				push(push_num);
			}
			else {
				printf("스택이 꽉 찼습니다.");
			}
			break;
			
		case 2:
			if (top >= 0) {
				pop();
			}
			else {
				printf("스택이 비었습니다.");
			}
			break;

		case 3: // 현재 스택을 출력하는 케이스
			for (int i = 0; i < top+1; i++) {
				printf("%d ", stack[i]);
				if (i == top) {
					printf("\n");
				}
			}
			break;

		case 0:
			return 0;
		}
	}
}

int push(int push_num) {
	top = top + 1;
	printf("스택의 개수(최대 10): %d\n", top+1); // 현재 스택이 몇까지 쌓였는지 보여줌
	stack[top] = push_num;
}

int pop() {
	stack[top] = 0;
	top--;
	printf("스택의 개수(최대 10): %d\n", top+1); // 현재 스택이 몇까지 쌓였는지 보여줌
}
	