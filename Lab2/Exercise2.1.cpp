#include <iostream>

using namespace std;

class ListNode{
	public:
		int val;
		ListNode * next;
		ListNode(int x): val(x), next(NULL){
		};
};
ListNode* swapPairs(ListNode* head){
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	ListNode* former = NULL;
	ListNode* later = NULL;
	
	if(!head || !head->next) return head;
	p1 = head;
	p2 = p1 -> next;
	
	later = p2 -> next;
	p2 -> next = p1;
	p1 -> next = later;
	
	head = p2;
	
	former = p1;
	p1 = former -> next;
	p2 = p1 ? p1 -> next : NULL;
	later = p2 ? p2 -> next : NULL;
	
	while(p1 && p2){
		former -> next = p2;
		p1 -> next = later;
		p2 -> next = p1;
		
		former = p1;
		p1 = former -> next;
		p2 = p1 ? p1 -> next : NULL;
		later = p2 ? p2 -> next : NULL;
	}
	return head;
}

void printfList(ListNode* head){
	while(head){
		printf("%d", head -> val);
		if(head->next){
			printf("->");
		}else{
			printf("\n");
		}
		head = head -> next;
	}
}

int main(){
	int d;
	ListNode* head = NULL;
	ListNode* tail = NULL;
	
	while(scanf("%d", &d) != EOF){

		if(head == NULL){
			head = new ListNode(d);
			tail = head;
		}else{
			tail -> next = new ListNode(d);
			tail = tail -> next;
		}
	}
	printfList(head);
	head = swapPairs(head);
	printfList(head);
}
