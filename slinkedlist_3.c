#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
	int val;
	struct sll *next;
} sll_t;

sll_t *sll_header;
sll_t header = {999, NULL};

void insert_node_atend(sll_t *sll, int val)
{
	sll_t *newnode = malloc(sizeof(sll_t));
	newnode->val = val;
	newnode->next = NULL;
	if(sll == NULL) {
		sll = newnode;
	} else {
		sll_t *tmp = sll;
		while(tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}

}

void print_sll(sll_t *sll)
{
	sll_t *tmp = sll;
	while(tmp) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	putchar('\n');
}

int main(void)
{
#if 0
	for(int i=0; i<10; i++) {
		insert_node_atend(sll_header, i);
	}
	print_sll(sll_header);
#endif
#if 1 
	for(int i=0; i<10; i++) {
		insert_node_atend(&header, i);
	}
	print_sll(&header);
#endif

}
