#include <stdio.h>
#include <stdlib.h>

#include "my_fraction.h"

char* add(char* Afraction, char* Bfraction) {

	int Anummer = 0;	//분수 1의 분자
	int Ademoni = 0;	//분수 1의 분모
	int Bnummer = 0;	//분수 2의 분자
	int Bdemoni = 0;	//분수 2의 분모
	int digit = 1;		//자릿수 계산

	for (int i = 0; Afraction[i] != '\0'; i++) {

		//분수 1의 분자 분모값 찾기
		if (Afraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Anummer += (Afraction[i - (j + 1)] - 48) * digit;
				digit *= 10;
				// 분자 값 printf("%d", Anummer);

			}
			digit = 1;
			for (int j = 1; Afraction[i + j] != '\0'; j++) {
				Ademoni *= digit;
				Ademoni += Afraction[i + j] - 48;
				digit *= 10;
				// 분모 값 printf("%d", Ademoni);

			}
		}
	}

	digit = 1;

	for (int i = 0; Bfraction[i] != '\0'; i++) {

		//분수 2의 분자 분모값 찾기
		if (Bfraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Bnummer += (Bfraction[i - (j + 1)] - 48) * digit;
				digit *= 10;
				// 분자 값

			}
			digit = 1;
			for (int j = 1; Bfraction[i + j] != '\0'; j++) {
				Bdemoni *= digit;
				Bdemoni += Bfraction[i + j] - 48;
				digit *= 10;
				// 분모 값

			}
		}
	}
	//연산자에 따른 분모 분자 계산
	Bnummer = (Anummer * Bdemoni) + (Bnummer * Ademoni);										//덧셈
	Bdemoni = Bdemoni * Ademoni;



	//분수 정리

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;

	char Temparr[20] = { 0, };
	int TempDigit = 0;

	// 분자를 임시 배열에 넣은 후 역순으로 배열에 입력
	if (Bnummer == 0) 
		Temparr[TempDigit++] += 48;

	while (Bnummer > 0) {
		Temparr[TempDigit++] = (Bnummer % 10) + 48;
		Bnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit++] = '/'; //구분자 

	// 분모를 임시 배열에 넣은 후 역순으로 배열에 입력
	TempDigit = 0;
	if (Bdemoni == 0) Temparr[TempDigit++] += 48;

	while (Bdemoni > 0) {
		Temparr[TempDigit++] = (Bdemoni % 10) + 48;
		Bdemoni /= 10;
	}
	while (TempDigit > 0)
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0'; // 문자열 종료

	return MakeIrrFraction(Fractionarr); //기약분수 함수 호출

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* minus(char* Afraction, char* Bfraction) {

	int Anummer = 0;
	int Ademoni = 0;
	int Bnummer = 0;
	int Bdemoni = 0;

	int digit = 1;

	for (int i = 0; Afraction[i] != '\0'; i++) {


		if (Afraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Anummer += (Afraction[i - (j + 1)] - 48) * digit;
				digit *= 10;
				

			}
			digit = 1;
			for (int j = 1; Afraction[i + j] != '\0'; j++) {
				Ademoni *= digit;
				Ademoni += Afraction[i + j] - 48;
				digit *= 10;
				

			}
		}
	}

	digit = 1;

	for (int i = 0; Bfraction[i] != '\0'; i++) {


		if (Bfraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Bnummer += (Bfraction[i - (j + 1)] - 48) * digit;
				digit *= 10;
				


			}
			digit = 1;
			for (int j = 1; Bfraction[i + j] != '\0'; j++) {
				Bdemoni *= digit;
				Bdemoni += Bfraction[i + j] - 48;
				digit *= 10;
				


			}
		}
	}

	Bnummer = (Anummer * (findLCM(Ademoni, Bdemoni) / Ademoni)) - (Bnummer * (findLCM(Ademoni, Bdemoni) / Bdemoni));	//뺄셈
	Bdemoni = findLCM(Bdemoni, Ademoni); 

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;

	char Temparr[20] = { 0, };;
	int TempDigit = 0;

	if (Bnummer < 0) {
		Fractionarr[FractionDigit++] = '-';
		Bnummer = -Bnummer;
	}

	if (Bnummer == 0) 
		Temparr[TempDigit++] += 48;

	while (Bnummer > 0) {
		Temparr[TempDigit++] = (Bnummer % 10) + 48;
		Bnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit++] = '/';

	TempDigit = 0;

	if (Bdemoni == 0) 
		Temparr[TempDigit++] += 48;

	while (Bdemoni > 0) {
		Temparr[TempDigit++] = (Bdemoni % 10) + 48;
		Bdemoni /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0';

	return MakeIrrFraction(Fractionarr);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

char* mult(char* Afraction, char* Bfraction) {

	int Anummer = 0;
	int Ademoni = 0;
	int Bnummer = 0;
	int Bdemoni = 0;
	int digit = 1;

	for (int i = 0; Afraction[i] != '\0'; i++) {


		if (Afraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Anummer += (Afraction[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; Afraction[i + j] != '\0'; j++) {
				Ademoni *= digit;
				Ademoni += Afraction[i + j] - 48;
				digit *= 10;

			}
		}
	}

	digit = 1;

	for (int i = 0; Bfraction[i] != '\0'; i++) {


		if (Bfraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Bnummer += (Bfraction[i - (j + 1)] - 48) * digit;
				digit *= 10;

			}
			digit = 1;
			for (int j = 1; Bfraction[i + j] != '\0'; j++) {
				Bdemoni *= digit;
				Bdemoni += Bfraction[i + j] - 48;
				digit *= 10;

			}
		}
	}

	Bnummer = Anummer * Bnummer;																//곱셈
	Bdemoni = Bdemoni * Ademoni; 

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;

	char Temparr[20] = { 0, };;
	int TempDigit = 0;

	if (Bnummer == 0) 
		Temparr[TempDigit++] += 48;

	while (Bnummer > 0) {
		Temparr[TempDigit++] = (Bnummer % 10) + 48;
		Bnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit++] = '/'; 

	
	TempDigit = 0;

	if (Bdemoni == 0) 
		Temparr[TempDigit++] += 48;

	while (Bdemoni > 0) {
		Temparr[TempDigit++] = (Bdemoni % 10) + 48;
		Bdemoni /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0';

	return MakeIrrFraction(Fractionarr);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* divid(char* Afraction, char* Bfraction) {

	int Anummer = 0;
	int Ademoni = 0;
	int Bnummer = 0;
	int Bdemoni = 0;
	int digit = 1;

	for (int i = 0; Afraction[i] != '\0'; i++) {


		if (Afraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Anummer += (Afraction[i - (j + 1)] - 48) * digit;
				digit *= 10;
				

			}
			digit = 1;
			for (int j = 1; Afraction[i + j] != '\0'; j++) {
				Ademoni *= digit;
				Ademoni += Afraction[i + j] - 48;
				digit *= 10;
				

			}
		}
	}

	digit = 1;

	for (int i = 0; Bfraction[i] != '\0'; i++) {


		if (Bfraction[i] == '/') {
			for (int j = 0; j < i; j++) {
				Bnummer += (Bfraction[i - (j + 1)] - 48) * digit;
				digit *= 10;
				

			}
			digit = 1;
			for (int j = 1; Bfraction[i + j] != '\0'; j++) {
				Bdemoni *= digit;
				Bdemoni += Bfraction[i + j] - 48;
				digit *= 10;
				

			}
		}
	}
	int temp = 0;
	temp = Bnummer;
	Bnummer = Anummer * Bdemoni;																			//나눗셈
	Bdemoni = Ademoni * temp;

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;

	char Temparr[20] = { 0, };;
	int TempDigit = 0;

	if (Bnummer == 0) 
		Temparr[TempDigit++] += 48;

	while (Bnummer > 0) {
		Temparr[TempDigit++] = (Bnummer % 10) + 48;
		Bnummer /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit++] = '/'; 

	TempDigit = 0;

	if (Bdemoni == 0) 
		Temparr[TempDigit++] += 48;

	while (Bdemoni > 0) {
		Temparr[TempDigit++] = (Bdemoni % 10) + 48;
		Bdemoni /= 10;
	}
	while (TempDigit > 0) 
		Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0'; // 문자열 종료

	return MakeIrrFraction(Fractionarr);


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findGCD(int nummer, int GCD) {
	if (GCD == 0) {
		return nummer;
	}
	else {
		return findGCD(GCD, nummer % GCD);
	}
}

int findLCM(int nummer, int demoni) {

	return ((nummer * demoni) / findGCD(nummer, demoni));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* MakeIrrFraction(char* input) {

	int Anummer = 0;
	int Ademoni = 0;
	int digit = 1;
	int negative = 0;

	for (int i = 0; input[i] != '\0'; i++) {

		if (input[i] == '/') {
			for (int j = 0; j < i; j++) {
				if (input[i - (j + 1)] == '-') {
					negative++;
					break;
				}
				Anummer += (input[i - (j + 1)] - 48) * digit;
				digit *= 10;
				// 분자 값

			}
			digit = 1;
			for (int j = 1; input[i + j] != '\0'; j++) {
				if (input[i - j] == '-') {
					negative++;
					break;
				}
				Ademoni *= digit;
				Ademoni += input[i + j] - 48;
				digit *= 10;
				// 분모 값


			}
		}
	}

	char Fractionarr[20] = { 0, };
	int FractionDigit = 0;
	int ReduceAnummer = Anummer / findGCD(Anummer, Ademoni);		//분자 약분

	char Temparr[20] = { 0, };;
	int TempDigit = 0;
	int ReduceAdemoni = Ademoni / findGCD(Anummer, Ademoni);		//분모 약분

	if (negative == 1) {
		Fractionarr[FractionDigit++] = '-';
	}

	// 분자를 임시 배열에 넣은 후 역순으로 배열에 입력
	if (ReduceAnummer == 0) Temparr[TempDigit++] += 48;

	while (ReduceAnummer > 0) {
		Temparr[TempDigit++] = (ReduceAnummer % 10) + 48;
		ReduceAnummer /= 10;
	}
	while (TempDigit > 0) Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	if (ReduceAdemoni == 1)
		return Fractionarr;				//분모가 1일시 정수 출력

	Fractionarr[FractionDigit++] = '/'; // 구분자

	// 분모를 임시 배열에 넣은 후 역순으로 배열에 입력
	TempDigit = 0;

	if (ReduceAdemoni == 0) Temparr[TempDigit++] += 48;

	while (ReduceAdemoni > 0) {
		Temparr[TempDigit++] = (ReduceAdemoni % 10) + 48;
		ReduceAdemoni /= 10;
	}
	while (TempDigit > 0) Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	Fractionarr[FractionDigit] = '\0'; // 문자열 종료

	return Fractionarr;
}