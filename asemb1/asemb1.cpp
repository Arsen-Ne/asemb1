#include <iostream>
using namespace std;
int main()
{
	int x, y, k;
	cout << "input x" << endl;
	cin >> x;
	cout << "input k" << endl;
	cin >> k;
	__asm
	{
		mov eax, x; переносим число из х в eах(для дальнейшего деления)
		mov edi, k
		xor edx, edx
		xor ecx, ecx
		xor esi, esi
		mov ebx, 10; заносим в регистр ebx число 10

	block1:; делим на цифры
		mov edx, 0
		div ebx; делим содержимое регистра eах на содержимое регистра ebx и получаем цифру числа в регистре edx
		push edx
		inc ecx
		cmp eax, 0; сравниваем регистр eах(в котором изначально находится число) с 0
		jne block1; если он равен нулю то все цифры числа перенесены в стек, иначе, переход снова на метку block1

		xor eax, eax
		xor ebx, ebx; результат

	block2:
		pop eax; достаем цифру из стека
		mov edx, 0
		mov esi, eax; сохраняем ее в esi т.к. eax после деления изменится
		div edi; делим на k
		cmp edx, 0
		je end2; пропускаем если кратно
		imul ebx, 10; умножаем результат на 10
		add ebx, esi; добавляем текущую цифру
	end2:
		loop block2

		mov y, ebx
	}

	if (y == 0)
	{
		cout << "нет таких цифр" << endl;
	}
	else { cout << y << endl; }
}