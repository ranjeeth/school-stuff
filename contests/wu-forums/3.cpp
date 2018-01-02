#include<iostream>
#include<cstdlib>

struct node{ int  data; struct node * next;};


void insert( struct node ** head_ref, int key)
{
	struct node * to_insert = (struct node *) malloc( sizeof(struct node));
	to_insert->data = key;
	to_insert->next = *head_ref;
	*head_ref = to_insert;
}


void print(struct node * head)
{
	std::cout<<"<";
	while(head)
	{
		std::cout<<" "<<head->data;
		head = head->next;
	}
	std::cout<<" >"<<std::endl;
}

void clear(struct node ** head_ref)
{
	node * p = *head_ref, *to_del;
	while(p)
	{
		to_del = p; p = p->next;
		free(to_del);
	}
	*head_ref = NULL;
}

void create_loop_at(int r, struct node * head)
{
	node * end = head;
	while(r--)
	{
		end = end->next;
	}
	node * marked = end;
	while(end->next)
		end = end->next;
	end->next = marked;	
}

void break_loop(struct node * head)
{

}

int main()
{
	int n;
	
	struct node * head;
	while(std::cin>>n)
	{
		for (int i=0; i < n ; ++i)
		{
			int key = rand()%n;
			insert(&head, key);
		}
	
		print(head);
		int r = rand()%(n-1);
		create_loop_at(r, head);
		
		clear(&head);	
	}
}
