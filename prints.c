

void	print(t_stack *a, t_stack *b)
{
	printf("\n a-stack %p\n", a);
	if (a != NULL)
	{	
		while (a->next != NULL)
		{
			printf("a-val: %d\t a-pos: %d\t a-next: %d a-prv: %d\n", a->val, a->pos, a->next->val, a->prev->val);
			a = a->next;
		}
		printf("a-val: %d\t a-pos: %d\t a-next: %p\n ", a->val, a->pos,  a->next);
	}
	printf("\n b_stack  %p\n", b);
	if (b != NULL)
	{
		while (b->next != NULL)
		{
			printf("b-val: %d\t b-pos: %d\t b-next: %d\n ", b->val, b->pos,  b->next->val);
			b = b->next;
		}
		printf("b-val: %d\t b-pos: %d\t b-next: %p\n", b->val, b->pos, b->next);
	}
}
