#include "swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sing;

	i = 0;
	res = 0;
	sing = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sing);
}
int	*getlist(int ac, char **av)
{
	int	i;
	int	*list;

	list = (int *)malloc(sizeof(int) * (ac - 1));
	i = 1;
	while(i < ac)
	{
		list[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (list);
}

int main(int ac, char **av)
{
	int i = 0, c = 9;
	int	*tab;
	stack	*a = NULL, *b = NULL;
	stack	*head1, *head2;
	tab = getlist(ac, av);
	a = malloc(sizeof(stack));
	a->value = tab[i++];
	head1 = a;
	head2 = b;
	while (i < ac - 1)
	{
		a->next = malloc(sizeof(stack));
		a = a->next;
		a->value = tab[i];
		i++;
	}
	a->next = NULL;
	while (c)
	{
		printf("chose (1-pb, 2-pa, 3-sa, 4-sb, 5-ra, 6-rb, 7-rra, 8-rrb, 9-aff, 0-exit):");
		scanf("%d",&c);
		if (c == 1)
			push(&head1, &head2);
		else if (c == 2)
			push(&head2, &head1);
		else if (c == 3)
			swap(head1);
		else if (c == 4)
			swap(head2);
		else if (c == 5)
			shiftup(&head1);
		else if (c == 6)
			shiftup(&head2);
		else if (c == 7)
			shiftdown(&head1);
		else if (c == 8)
			shiftdown(&head2);
		else if (c == 9)
		{
			printf("\nthe stacks: \n");
			affstack(head1, head2);
			printf("\n");
		}
		printf("\nthe stacks: \n");
		affstack(head1, head2);
		printf("\n");
		if (c < 1 || c > 9)
			return 0;
	}
	return 0;
}
