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
//		sll_t *tmp = (*sll)->next;
//		while (tmp){
//			tmp = tmp->next;
//		}
//		tmp = newnode;
		sll_t *tmp = *sll;
		while(tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
	return 0;
}

int sll_delete(sll_t **sll, int val)
{
	if(!(*sll)) {
		return -1;
	}
	sll_t *tmp = *sll;
	if((*sll)->val == val /*at head*/) {
		(*sll) = (*sll)->next;
		free(tmp);
	}
	sll_t *previous = NULL;
	while(tmp) {
		if(val == tmp->val) {
			break;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	if(!tmp/*no found*/) {
		return -1;
	} else if(tmp->next == NULL/*at end*/) {
		previous->next = NULL;	
	} else {
		previous->next = tmp->next;	
	}
	free(tmp);
	return 0;
}

int sll_destory(sll_t *sll)
{
	sll_t *tmp = sll;
	while(sll) {
		tmp = sll;
		sll = sll->next;
		free(tmp);
	}
	return 0;
}

sll_t *sll_find(sll_t *sll, int val)
{
	sll_t *tmp = sll;
	if(!sll) {
		return NULL;
	}
	while(tmp) {
		if(tmp->val == val) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

int sll_replace(sll_t *sll, int origin, int after)
{
	if(!sll) {
		return -1;
	}
	sll_t *node = sll_find(sll, origin); 
	if(!node) {
		return -1;
	} else {
		node->val = after;
		return 0;
	}
}

sll_t *sll_reverse(sll_t *sll)
{
	sll_t *reversed_sll = NULL;
	sll_t *current = sll, *previous = NULL, *next = NULL;
	if(!sll) {
		return NULL;
	}
	while(current) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	reversed_sll = previous;
	return reversed_sll;
}

size_t sll_length(sll_t *sll)
{
	sll_t *tmp = sll;
	size_t length = 0;
	if(!sll) {
	
	} else {
		while(tmp) {
			++length;
			tmp = tmp->next;
		}
	}
	return length;
}

void sll_print(sll_t *sll)
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
	int i;
	sll_t *sll = NULL;
	for(i=0; i<20; i++) {
		sll_insert(&sll, i);
	}
	sll_print(sll);

	printf("sll length: %d\n", sll_length(sll));

	/* sll_reverse will change origin sll */
	sll = sll_reverse(sll);
	sll_print(sll);

	sll_delete(&sll, 10);
	sll_delete(&sll, 0);
	sll_delete(&sll, 19);
	sll_print(sll);

	sll_replace(sll, 5, 500);
	sll_print(sll);

	sll_destory(sll);

	return 0;
}
