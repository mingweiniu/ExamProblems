#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		auto front = head;
		auto end = head;
		while ((end->next) != nullptr) end = end->next;
		

		return end;

	}
	
	void Test() {
		std::vector<ListNode> test;
		test.push_back(ListNode(3));
		ListNode* pre= &test[0];
		
		for (int i = 1; i < 100;++i) {
			test.push_back(ListNode(std::rand()));
			test[i].next = pre;
			pre = &test[i];
		}
		

		sortList(pre);


	}
	

	






};