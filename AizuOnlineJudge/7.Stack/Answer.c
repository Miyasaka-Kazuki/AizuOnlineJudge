//#include<stdio.h>
//#include <stdlib.h>
//#include<string.h>
//
//int top, S[1000];
//
//void push(int x) {
//	S[++top] = x;
//}
//
//int pop() {
//	top--;
//	return S[top + 1];
//}
//
//int main() {
//	char s[100];
//	int a, b;
//	top = 0;
//
//	while (scanf_s("%s", s, 1) != EOF) {
//		if (s[0] == '+') {
//			a = pop();
//			b = pop();
//			push(a + b);
//		}
//		else 	if (s[0] == '-') {
//			a = pop();
//			b = pop();
//			push(a - b);
//		}
//		else 	if (s[0] == '*') {
//			a = pop();
//			b = pop();
//			push(a * b);
//		}
//		else {
//			int i = stoi(s);
//			push(i);
//		}
//
//	}
//		printf("%d\n", pop());
//
//	return 0;
//}