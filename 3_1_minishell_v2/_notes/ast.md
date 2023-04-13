AST - Abstract syntax tree
https://en.wikipedia.org/wiki/Abstract_syntax_tree
how does it work in practice in https://github.com/twagger/minishell/ ?
the binary tree is the final output of the parser (t_node *tree)
and the input of the interpreter (t_node *ast)

the interpreter navigates in post_order, collecting the right information in the right order to execute commands, pipes and redirection
https://www.javatpoint.com/postorder-traversal
- start at root
- explore left branch to bottom
- then right
- then perform an action

take the simple example: ls -l | grep .. | wc -l > file
https://github.com/twagger/minishell/raw/master/doc/img/post_order-real.png

when we get to a pipe node, we
- fork the subshell
- execute the tree from the pipe node

step by step:
traverse down to leftmost branch i.e. until left next is NULL?
collect commands until we reach a pipe node, then
fork off a subshell and set to read from pipe
execute "ls -l" to write to pipe
collect commands until we reach a pipe node, then