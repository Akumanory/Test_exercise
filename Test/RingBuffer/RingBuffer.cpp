#include "ArrayRingBuffer.h"
#include "LinkedListRingBuffer.h"


int main()
{
    LinkedListRingBuffer<int> llrb = LinkedListRingBuffer<int>();

    llrb.EnQueue(25);
    llrb.EnQueue(16);
    llrb.EnQueue(20);
    llrb.EnQueue(8);
    llrb.EnQueue(12);
    llrb.DeQueue();

    llrb.OutputInfo();

    ArrayRingBuffer<int> rb = ArrayRingBuffer<int>(3);

    rb.EnQueue(12);
    rb.EnQueue(14);
    rb.EnQueue(15);
    rb.DeQueue();
    rb.EnQueue(16);

    rb.OutputInfo();
}

/*
�������� �������:

� ������ ������� ���� ������������ ��� ���� ����������� �������.
������ ������� ������������ ����� ������������� ������� �� ����������� ��������.
������ ������� ������������ ����� ������������� �������������� ������ �����.

����� ������:
������ ������ ���������� �������� �� ��� ������� � ������� �������� sizeof(T).
������� ���������� �� �������� �� ������ �������� ������������� ���������� ������� ������� ����� �������������
(���� �� ���� ��� ���������� resize �������, �������� �� ��� ����, ��� ��� ������ ������������� �� � ��� ���� � �� �� ���� �������)

������ ������ ���������� �������� ������������ �����������, ������ ���������� �� ������ ����������� �������
(��� �� � ��� dequeue �������� ����������� �������������).
������� ������ ���������� �������� ����������� ������� �������� � �������(sizeof(T) + 4 �����(��� 8 ���� � ����������� �� ����������� �������)).

*/