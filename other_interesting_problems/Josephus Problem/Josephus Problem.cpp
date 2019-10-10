// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

// tricky Recursive method
int JosephusProbelm(int n, int m) {
	if (n <= 0 || m <= 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}
	return (JosephusProbelm(n - 1, m) + m - 1) % n + 1;
}

// normal Linked list method
struct Node {
	int val;
	Node *next;
	Node(int v, Node *n=nullptr):val(v), next(n){}
};

int JosephusProbelm1(int n, int m) {
	if (n <= 0 || m <= 0) {
		return 0;
	}
	// build a circle
	Node *head = new Node(1);
	Node *pre = head;
	for (int i = 2; i <= n; ++i) {
		pre->next = new Node(i);
		pre = pre->next;
		if (i == n) {
			pre->next = head;
		}
	}
	int i = 1;
	while (head->next != head) {
		if (i == m) {
			pre->next = head->next;
			head = head->next;
			i = 1;
		}
		else {
			pre = head;
			head = head->next;
			i++;
		}
	}
	return head->val;
}



int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << "The Input is: " << "a = " << a << ", b = " << b << endl;
		cout << "The answer is:" << JosephusProbelm(a, b) << endl;
		cout << "The answer is:" << JosephusProbelm1(a, b) << endl;
	}

	return 0;
}
