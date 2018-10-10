#include <iostream>

using namespace std;

class ListNode{
	public:
		int val;
		ListNode * next;
		ListNode(int x): val(x), next(NULL){
		};
};

ListNode* reverseKGroup(ListNode* head, int k){
	ListNode* fake_head = new ListNode(-9999);
	fake_head -> next = head;
	
	ListNode* i_former = fake_head;
	ListNode* i = head;
	ListNode* j_former = fake_head;
	ListNode* j = i;
	
	ListNode* p = NULL;
	
	while(i && j){
		for(int c = 0; c < k-1; c++){
			j_former = j_former -> next;
			j = j -> next;
			if(!j) return fake_head -> next;
		}
		
		while(j != i){
			j_former -> next = j -> next;
			j -> next = i_former -> next;
			i_former -> next = j;
			
			i_former = j;
			j = j_former;
			
			p = i_former;
			while(p -> next != j && i != j){
				p = p -> next;
			}
			j_former = p;
		}
		
		i_former = i;
		i = i_former -> next;
		j_former = i_former;
		j = i;
	}
	
	return fake_head -> next;
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
	int k, d;
	ListNode* head = NULL;
	ListNode* tail = NULL;
	scanf("%d", &k);
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
	head = reverseKGroup(head, k);
	printfList(head);
}
