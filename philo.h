#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
#include "pthread.h"

typedef enum e_error
{
	ERROR_SUCCESS = 0,
	ERROR_INVALID_ARGS = 1,
	ERROR_FILE_NOT_FOUND = 2,
	ERROR_FILE_EMPTY = 3,
	ERROR_INVALID_EXTENSION = 4,
	ERROR_MEMORY = 5,
	ERROR_INVALID_MAP = 6,
	ERROR_MAP_NOT_RECTANGULAR = 7,
	ERROR_MAP_NOT_SURROUNDED = 8,
	ERROR_INVALID_PATH = 9,
	ERROR_INVALID_XPM_FORMAT = 10,
	CONNECTION_ERROR = 11,
	WINDOW_ERROR = 12
}	t_error;

typedef struct s_fork
{
	int	id;
	pthread_mutex_t fork;
} t_fork ;

typedef struct s_philo
{
	
} t_philo;

void	print_error(t_error error);

#endif
