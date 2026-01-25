#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>

void	*routine()
{
	printf("this is a test\n");
}

int	main(void)
{
	pthread_t	t1;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}
