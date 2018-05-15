#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
	int val;
	struct sll *next;
} sll_t;

int sll_insert(sll_t **sll, int val)
{
	sll_t *newnode = malloc(sizeof(sll_t));
	if(!newnode) {
		return -1;
	}
	newnode->val = val;
	newnode->next = NULL;
	if(!(*sll)) {
		*sll = newnode;	
	} else {
	//	sll_t *tmp = (*sll)->next;
	//	while(tmp) {
	//		printf("tmp-> %p, %d\n", tmp, tmp->val);
	//		tmp = tmp->next;
	//	}
	//	tmp = newnode;
		sll_t *tmp = (*sll);
		while (tmp->next){
			tmp = tmp->next;
		}
		tmp->next = newnode;
	
	}
	return 0;
}

void sll_print(sll_t *sll)
{
	sll_t *tmp = sll;
	while(tmp) {
		tmp = tmp->next;
	}
	putchar('\n');
}

int main(void)
{
	int i;
	sll_t *sll = NULL;
	for(i=0; i<20; i++) {
		sll_insert(&sll, i);
	}
	sll_print(sll);
	return 0;
}
