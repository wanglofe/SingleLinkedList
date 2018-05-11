#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
	int val;
	struct sll *next;
} sll_t;

sll_t *sll_header;
sll_t header;

void insert_node_atend(sll_t *sll, int val)
{
	if(!sll) {
		printf("1");
		sll= malloc(sizeof(sll_t));
		sll->val = val;
		sll->next = NULL;
		printf("\nsll = NULL %d, sll->val %d\n", sll != NULL, sll->val);
	} else {
		printf("2");
		sll_t *tmp = sll->next;
		while(tmp) {
			tmp = tmp->next;
		}
		tmp = malloc(sizeof(sll_t));
		tmp->val = val;
		tmp->next = NULL;
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
	for(int i=0; i<10; i++) {
		insert_node_atend(&header, i);
	}
	print_sll(&header);

}
