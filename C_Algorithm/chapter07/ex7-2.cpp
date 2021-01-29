#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

// ���� �ʱ�ȭ
int Initialize(IntSet* s, int max) {
	s->num = 0;		// �ʱ� ������ ������ �������̹Ƿ� num�� ���� 0
	if ((s->set = (int*)calloc(max, sizeof(int))) == NULL) {	// �迭 ���� �������� ���
		s->max = 0;	
		return -1;
	}
	s->max = max;
	return 0;
}

// ���� s�� n�� ����ִ��� �˻�
int IsMember(const IntSet* s, int n) {
	int i;
	for (i = 0; i < s->num; i++)				// �����˻� �˰�����
		if (s->set[i] == n)
			return i;
	return -1;
}

// ���� s�� n�� �߰�
void Add(IntSet* s, int n) {
	if (s->num < s->max && IsMember(s, n) == -1)	// �迭�� ������ �����ְ�, ���տ� ���� ����n�� ������� ���� ���
		s->set[s->num++] = n;
}

// ���� s�� n�� ����
void Remove(IntSet* s, int n) {
	int idx;
	if ((idx = IsMember(s, n)) != -1) {	// ���տ� n�� ����ִ� ���... �����Ϸ��� ���� �ε����� idx�� ����
		s->set[idx] = s->set[--s->num];	// ������ ��Ҹ� ���� ��ġ�� �ű� 
	}	// num�� 1��ŭ ���ҽ�Ų �� set�� ������ ��Ҹ� ������ idx�ε����� ���� ����
}

//���� s�� ���� �� �ִ� �ִ��� ���� ���� ��ȯ
int Capacity(const IntSet* s) {
	return s->max;
}

// ���� s�� ���� ������ ��ȯ
int Size(const IntSet* s) {
	return s->num;
}

// ���� s2�� s1�� ����
void Assign(IntSet* s1, const IntSet* s2) {
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;
	// �����ϴ� ������ ���� -> s2�� num�� s1�� max���� ũ�ٸ� max�� ������ŭ �������ش�
	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

// ���� s1�� s2�� ������ Ȯ��
int Equal(const IntSet* s1, const IntSet* s2) {
	int i, j;
	if (Size(s1) != Size(s2))	// ���� s1�� s2�� ���� ������ �ٸ���
		return 0;
	for (i = 0; i < s1->num; i++) {
		for (j = 0; i < s2->num; j++)
			if (s1->set[i] == s2->set[j])			
				break;									// ���� ���� ������ break�ؼ� �ٽ� i�� �ݺ��� ����
		if (j == s2->num)							// j�� ������ �������� ��� �� ������ ���� �������� 0��ȯ
			return 0;
	}
	return 1;
}

// ���� s2�� s3�� �������� s1�� ����
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	int i;
	Assign(s1, s2);	// ����s2�� s1�� ����
	for (i = 0; i < s3->num; i++)	// ���� s3�� ��� ���Ҹ� s1�� �߰� (�ߺ���  ���Ҵ� �߰�x)
		Add(s1, s3->set[i]);
	return s1;
}

// ���� s2�� s3�� �������� s1�� ����
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	int i, j;
	s1->num = 0;	// ����s1�� ���������� ����
	for (i = 0; i < s2->num; i++)
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])		// ���� s2�� s3�� ���� ���Ұ� ���� ��
				Add(s1, s2->set[i]);		// ���� s2�� s3�� ���� ���Ҹ� ���� s1�� �߰�
	return s1;
}

// ���� s2���� s3�� �� �������� s1�� ����
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	int i, j;
	s1->num = 0;						// s1�� ���������� ����ϴ�.
	for (i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;
		if (j == s3->num)		// ���� s2�� s3�� �ٸ� ���Ұ� ���� ��� ���� s1�� �߰�
			Add(s1, s2->set[i]);
	}
	return s1;
}

// ���� s�� ��� ���Ҹ� ���
void Print(const IntSet* s) {
	int i;
	printf("{ ");
	for (i = 0; i < s->num; i++)
		printf("%d", s->set[i]);
	printf("}");
}

// ����s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����)
void PrintLn(const IntSet* s) {
	Print(s);
	putchar('\n');
}

// ���� ����
void Terminate(IntSet* s) {
	if (s->set != NULL) {
		free(s->set);					// �迭 ����
		s->max = s->num = 0;
	}
}