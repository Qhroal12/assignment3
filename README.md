# ADT

- 분수는 +, -, *, /의 연산으로 이루어지며, 두 분수의 연산 결과는 하나의 분수로 반환된다. 이때 출력은 기약분수 꼴로 출력한다.

- 또한, 위 기능을 위한 기약분수 연산이 존재하며, 해당 연산은 하나의 분수를 받아 기약분수 꼴로 반환하는 연산이다.

- 추가로 A/B 꼴의 문자열을 입력받아 분수 자료형으로 변환하는 연산, 분수 자료형을 A/B꼴로 출력하는 연산도 작성한다(A, B는 정수).

- 참고: 입력은 띄어쓰기로 구분된 "[분수] [연산자] [분수]" 형태로 입력된다.


1. 분수의 사칙연산의 공식 알아내기
2. 연산 함수 제작
3. 연산 후의 수를 기약분수로 만들어내는 함수가 필요
4. 이후 배열 출력

입력값:
분수 = '/'이 들어간 문자형 배열 2개  
연산자 = 문자형 1개

각 사칙연산 +-*/를 하는 함수를 순서대로
add,minus,mult,divid로 만들고 하나의 분수로 반환하는 MakeIrrFraction함수 제작

과제 2번에 있는 LCM과 GCD가 통분 및 사칙연산에 필요

먼저 하나의 분수로 반환하는 MakeIrrFraction함수 제작(입력값 1개, 출력 1개)

```
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
```
위 코드는 받은 분수 문자열을 '/'를 기준으로 분자 분모를 알아내는 반복문이다.

if i가 /이면 
분자값 = i - 1를 넣음  
이때 계속 +하면 1의 자리만 추가함으로  
digit * 10 한 값을 전 숫자에 넣음(아스키코드형이기 때문에 48을 넣어 숫자로 변환)

분모도 같음

만약 분자 분모가 < 0일시 다음 배열로 건너뛰고 부호 확인 수에 +1


```
char Fractionarr[20] = { 0, };
	int FractionDigit = 0;
	int ReduceAnummer = Anummer / findGCD(Anummer, Ademoni);		//분자 약분

	char Temparr[20] = { 0, };;
	int TempDigit = 0;
	int ReduceAdemoni = Ademoni / findGCD(Anummer, Ademoni);		//분모 약분

	if (negative == 1) {
		Fractionarr[FractionDigit++] = '-';
	}
```
기약분수를 위해 각 분자 분모 약분 : a / GCD(a,b)를 함

만약 분자 분모 둘 다 < 0 or > 0이라면 양수라 negative문 스킵
일종의 xor 게이트

```
	if (ReduceAnummer == 0) Temparr[TempDigit++] += 48;

	while (ReduceAnummer > 0) {
		Temparr[TempDigit++] = (ReduceAnummer % 10) + 48;
		ReduceAnummer /= 10;
	}
	while (TempDigit > 0) Fractionarr[FractionDigit++] = Temparr[--TempDigit];

	if (ReduceAdemoni == 1)
		return Fractionarr;				
```
새로운 배열에 분자 부터 넣어줌 이때도 마찬가지로 문자형으로 넣어짐으로 48을 +함
이때 배열 거꾸로 이니 --TempDigit을 하며 값에 대입

마지막으로 분자가 == 1이면 Fractionarr 바로 출력(정수)
```
	Fractionarr[FractionDigit++] = '/'; 

	// 분모를 임시 배열에 넣은 후 역순으로 배열에 입력
	TempDigit = 0;

	if (ReduceAdemoni == 0) Temparr[TempDigit++] += 48;

	while (ReduceAdemoni > 0) {
		Temparr[TempDigit++] = (ReduceAdemoni % 10) + 48;
		ReduceAdemoni /= 10;
	}
	while (TempDigit > 0) Fractionarr[FractionDigit++] = Temparr[--TempDigit];
	Fractionarr[FractionDigit] = '\0'; 

	return Fractionarr;
}
```
배열 마지막은 \n로 끝이라고 알린 후 배열 반환

여기 반목문에 각 사칙 연산에 맞는 분자 분모 연산식을 대입(입력값 2개, 출력 1개)

마지막으론 연산자 " +, -, /, *"에 따라 if문을 써 함수 호출



