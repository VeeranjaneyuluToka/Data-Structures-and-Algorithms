#include <iostream>

using namespace std;
struct node{
	int val, key;
	node *prev;
	node *next;
	
	node(node *p, node* n, int k, int v): prev(p), next(n), key(k), val(v){};
	node(int k, int v): prev(NULL), next(NULL), key(k), val(v){};
};

node *head = NULL;
void insert(int key, int val){
	node *nNode = new node(key, val);
	nNode->prev = NULL;
	nNode->next = head;
	if (head != NULL)
		head->prev = nNode;
	head = nNode;
}

void display_dl(){
	node *ptr;
	ptr = head;
	while(ptr != NULL){
		cout << ptr->key << " " << ptr->val<<endl;
		ptr = ptr->next;
	}
	cout << endl;
}

int main(){
	for (int i = 0; i < 5; i++){
		insert(i, (i+1)*2);
	}

	display_dl();

}
