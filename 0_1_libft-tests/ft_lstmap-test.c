// #include <stdio.h>
// void	*mod_func(void *ct)
// {
// 	int 	i;
// 	void	*c;
// 	char	*pouet;

// 	c = ct;
// 	i = 0;
// 	pouet = (char *)c;
// 	while (pouet[i])
// 	{
// 		if (pouet[i] == 'o')
// 			pouet[i] = 'a';
// 		i++;
// 	}
// 	return (c);
// }

// void	del_func(void *content)
// {
// 	free(content);
// 	return;
// }

// int	main()
// {
// 	t_list	*lst;
// 	t_list 	*new1;
// 	// t_list 	*new2;
// 	// t_list 	*new3;
// 	t_list	*new_lst;		

// 	lst = ft_lstnew("captain blaubeer");
// 	new1 = ft_lstnew("captain brombeer");
// 	ft_lstadd_back(&lst, new1);
// 	// new2 = ft_lstnew("captain schlaubeer");
// 	// ft_lstadd_back(&lst, new2);
// 	// new3 = ft_lstnew("captain stachelbeer");
// 	// ft_lstadd_back(&lst, new3);
// 	printf("BEFORE:\n");
// 	printf("%s\n", (char *)lst->content);
// 	printf("%s\n", (char *)lst->next->content);
// 	// printf("%s\n", (char *)lst->next->next->content);	
// 	// printf("%s\n", (char *)lst->next->next->next->content);
// 	printf("AFTER:\n");
// 	new_lst = ft_lstmap(lst, &mod_func, &del_func);
// 	printf("%s\n", (char *)new_lst->content);
// 	printf("%s\n", (char *)new_lst->next->content);
// 	// printf("%s\n", (char *)new_lst->next->next->content);	
// 	// printf("%s\n", (char *)new_lst->next->next->next->content);
// }

// int main()
// {
// 	t_list *new;
// 	char *test;

// 	new = ft_lstnew("captain blaubeer");
// 	printf("%s\n", (char *)new->content);
// 	test = new->content;
// 	test[2] = 'c';
// 	printf("%s\n", test);

// }