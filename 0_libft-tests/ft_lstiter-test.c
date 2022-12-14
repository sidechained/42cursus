// // TEST DOES NOT WORK!
// #include <stdio.h>
// void	content_toupper(char *content)
// {
// 	// int i;
// 	// char *str_content;

// 	// str_content = content;
// 	// i = 0;
// 	// while(str_content[i])
// 	// {
// 	// 	ft_toupper(str_content[i]);
// 	// 	i++;
// 	// }
// }

// int	main()
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = ft_lstnew("node1");
// 	node2 = ft_lstnew("node2");
// 	ft_lstadd_back(&node1, node2);
// 	node3 = ft_lstnew("node3");
// 	ft_lstadd_back(&node1, node3);
// 	ft_lstiter(node1, content_toupper);
// 	printf("%s\n", (char *)node1->content);
// 	printf("%s\n", (char *)node2->content);
// 	printf("%s\n", (char *)node3->content);		
// }