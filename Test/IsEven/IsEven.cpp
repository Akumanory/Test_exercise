#include <iostream>
#include <string>

bool isEven(int value) 
{ 
    return value % 2 == 0; 
}

bool isEvenSecond(int value)
{
    return	!(value & 1);
}


int main()
{
	int value = 2;

	if (isEven(value))
	{
		std::cout << "Even" << std::endl;
	}
	else
	{
		std::cout << "Odd" << std::endl;
	}
	

	if (isEvenSecond(value))
	{
		std::cout << "Even" << std::endl;
	}
	else
	{
		std::cout << "Odd" << std::endl;
	}
}

/*
1. �������� 

������ ����������(isEven) 
������������ ����� �������� ������� �� �������, 
���� �������� ��� �� ����� ������, ���� ������� ������������ �� ����� ��������. 

������ ����������(isEvenSecond) 
������������ ����� ��������� AND, 
��� �� �� ���� ��������� �������� �� ������ ��� �������� �� �����.

������:
���������� ����� � �������� �������������
2 = 0010
3 = 0011

0010 AND 0001 = 0000(false)
0011 AND 0001 = 0001(true)
*/

/*
2. ����� � ������
� ����� ������ ��������� ����� ������� ����������� �������� ������ ���������� ������ ��� ���������� �������� �����.
��� ���������� ����� �������� � ��������.
������������� ������� ������ ���������� �������� � ������� ������� �� ����������� ���������� ���������� ��������. 
��� ��� ���������� �������� ��������� �� ��� ������ ������������ �������������� � ��� ������ ����������� ��������� �������������.


��������� � ���� � ����� ����� ���������� ����, ��� ����� ����������� ���������� ��� ���������� �� ����� ����������,
��� ����� ����������� ��������� ����������� �����������.
���� �������������� ������������� � Visual Studio �� ����� ������� ���� �������:

6:     return value % 2 == 0;
00007FF70E7E1E5E  mov         eax,dword ptr [value]
00007FF70E7E1E64  cdq
00007FF70E7E1E65  and         eax,1
00007FF70E7E1E68  xor         eax,edx
00007FF70E7E1E6A  sub         eax,edx
00007FF70E7E1E6C  test        eax,eax
00007FF70E7E1E6E  jne         isEven+3Ch (07FF70E7E1E7Ch)
00007FF70E7E1E70  mov         dword ptr [rbp+0C0h],1
00007FF70E7E1E7A  jmp         isEven+46h (07FF70E7E1E86h)
00007FF70E7E1E7C  mov         dword ptr [rbp+0C0h],0
00007FF70E7E1E86  movzx       eax,byte ptr [rbp+0C0h]

11:     return	!(value & 1);
00007FF70E7E1F1E  mov         eax,dword ptr [value]
00007FF70E7E1F24  and         eax,1
00007FF70E7E1F27  test        eax,eax
00007FF70E7E1F29  jne         isEvenSecond+37h (07FF70E7E1F37h)
00007FF70E7E1F2B  mov         dword ptr [rbp+0C0h],1
00007FF70E7E1F35  jmp         isEvenSecond+41h (07FF70E7E1F41h)
00007FF70E7E1F37  mov         dword ptr [rbp+0C0h],0
00007FF70E7E1F41  movzx       eax,byte ptr [rbp+0C0h]

��� �������� ������� ������� ���������� �� ���������� ��������:

return value % 2 == 0;
00007FF70E7E1E64  cdq					Convert Doubleword to Quadword
00007FF70E7E1E65  and         eax,1		��������� AND
00007FF70E7E1E68  xor         eax,edx	��������� XOR
00007FF70E7E1E6A  sub         eax,edx	��������� �� �������� eax ������� edx

return	!(value & 1);
00007FF70E7E1F24  and         eax,1		��������� AND

��������� ����� ��������� ����� ������� ��� ������ ���������� ���������� �� ������ ������ ������� ������ ��� ���������� ����.
������������� ������ ��������� ���������� � ��������.


*/