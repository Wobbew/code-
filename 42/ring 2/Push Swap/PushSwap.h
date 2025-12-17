
#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>

typedef struct s_list
{
	int						num;
	int						index;
	int						moves;
	struct s_list *anchor;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;
#endif

