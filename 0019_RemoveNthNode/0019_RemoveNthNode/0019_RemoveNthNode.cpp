// 0019_RemoveNthNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListNode.h"
#include <iostream>
#include <vector>

class Solution {
public:
	// beats first run 9%, second run 21%, 4th run 62.55%. o(n), 想不通还需要如何优化了。
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		// possibleEnd - curNode = n
		int findPostNode = n;
		ListNode* possibleEnd = head;
		while (findPostNode > 1)
		{
			possibleEnd = possibleEnd->next;
			--findPostNode;
		}

		ListNode* curNode = head;
		ListNode* preCurNode = curNode;

		// move possibleEnd to real end, now curNode is need delete		
		while (possibleEnd->next != nullptr)
		{
			preCurNode = curNode;
			curNode = curNode->next;
			possibleEnd = possibleEnd->next;
		}

		if (preCurNode==curNode)
		{
			// remove first node
			curNode = curNode->next;
			return curNode;
		}
		else
		{
			preCurNode->next = curNode->next;
			return head;
		}
	}
};

void FreeList(ListNode* head)
{
	while (head!=nullptr)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

ListNode* ConstructList(const std::vector<int>& vals)
{
	std::size_t index = 0;
	ListNode* head = new ListNode(vals[index]);
	
	ListNode* cur = head;
	++index;
	
	while (index < vals.size())
	{
		cur->next = new ListNode(vals[index]);
		cur = cur->next;
		++index;
	}

	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* head = ConstructList({ 1, 2, 3, 4, 5 });
	Solution solution;
	head = solution.removeNthFromEnd(head, 2);

	//ListNode* head = ConstructList({ 1, 2, 3, 4, 5 });
	//Solution solution;
	//head = solution.removeNthFromEnd(head, 1);

	//ListNode* head = ConstructList({ 1});
	//Solution solution;
	//head = solution.removeNthFromEnd(head, 1);

	std::cout << "Begin" << std::endl;
	ListNode* toPrint = head;
	while (toPrint != nullptr)
	{
		std::cout << toPrint->val << " ";
		toPrint = toPrint->next;
	}
	std::cout << std::endl; 
	std::cout << "End" << std::endl;

	FreeList(head);

	char ch;
	std::cin >> ch;

	return 0;
}

