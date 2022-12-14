
// #include <stdio.h>
// int	main()
// {
// 	t_list *	lst;
// 	t_list *	new;
// 	t_list *	next;

// 	lst = ft_lstnew("captain blaubeer"); // initially points to null
// 	new = ft_lstnew("captain brombeer"); // 

// 	printf("lst BEFORE: %s\n", (char *)lst->content);
// 	if (lst->next == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("non-NULL\n");

// 	ft_lstadd_front(&lst, new);

// 	printf("lst AFTER: %s\n", (char *)lst->content);
// 	if (lst->next == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("non-NULL\n");

// 	next = lst->next;
// 	printf("nextnode: %s\n", (char *)next->content);
// 	if (next->next == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("non-NULL\n");

// }