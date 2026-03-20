#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "my_fraction.h"

int main() {

	char Afraction[10];
	char Bfraction[10];
	char operater;

	printf("식을 입력하세요: ");
	scanf("%s %c %s", Afraction, &operater, Bfraction);


	if (operater == '+')
		printf("%s", add(Afraction, Bfraction));
	else if (operater == '-')
		printf("%s", minus(Afraction, Bfraction));
	else if (operater == '*')
		printf("%s", mult(Afraction, Bfraction));
	else if (operater == '/')
		printf("%s", divid(Afraction, Bfraction));
	else
		printf("잘못된 연산자 입니다.");

	return 0;
}