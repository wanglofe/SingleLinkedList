#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
	int val;
	struct sll *next;
} sll_t;

sll_t *sll_header = NULL;

int insert_node(sll_t **sll, int val)
{
	sll_t *newnode = malloc(sizeof(sll_t));
	if(!newnode) {
		return -1;
	}
	newnode->val = val;
	newnode->next = NULL;
	if(*sll == NULL) {
		*sll = newnode;
	} else {
		sll_t *tmp = *sll;
		while(tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
	return 0;
}

int delete_node(sll_t **sll, int val)
{
	if(!(*sll)||!((*sll)->next)) {
		return -1;
	}
	sll_t *tmp = *sll;
	if((*sll)->val == val/* the first one */) {
		*sll = (*sll)->next;
		free(tmp);
		return 0;
	}
	sll_t *previous = NULL;
	while(tmp && tmp->val != val) {
		previous = tmp;
		tmp = tmp->next;
	}
	if(!tmp/*no found*/) {
		return -1;
	} else if (!tmp->next/* the last one */) {
		previous->next = NULL;
	} else {
		previous->next = tmp->next;
	}
	free(tmp);
	return 0;
}


sll_t *reverse_sll(sll_t *sll)
{
	sll_t *current = sll;
	sll_t *previous = NULL;
	sll_t *next = NULL;
	if(!current || !current->next) {
		return current;
	}
	while(current) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return previous;
}

#if 0
sll_t *reverse_sll_recursion(sll_t *sll)
{
	sll_t *reversed_sll;
	if(!sll || !sll->next) {
		return sll;
	}
	reversed_sll = reverse_sll_recursion(sll->next);
	sll->next->next = sll;
	sll->next = NULL;
	return reversed_sll;
}
#endif

sll_t *find_node(sll_t *sll, int val)
{
	if(!sll) {
		return NULL; 	
	}
	sll_t *tmp = sll;
	while(tmp) {
		if(tmp->val == val) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void destory_sll(sll_t **sll)
{
	sll_t *tmp;
	while(*sll) {
		tmp = *sll;
		*sll = (*sll)->next;
		free(tmp);
	}
	*sll = NULL;
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
	for(int i=0; i<10; i++) {
		insert_node(&sll_header, i);
	}
	print_sll(sll_header);

	delete_node(&sll_header, 0);
	print_sll(sll_header);
	delete_node(&sll_header, 5);
	print_sll(sll_header);
	delete_node(&sll_header, 9);
	print_sll(sll_header);

	print_sll(reverse_sll(sll_header));

	sll_t *tmp = find_node(sll_header, 8);
	if(tmp) {
		printf("find value: %d\n", tmp->val);
	}

	destory_sll(&sll_header);
	print_sll(sll_header);

	return 0;	
}
