#include "get_next_line.h"

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*res;

	s1 = (char *)malloc(4 * sizeof(char));
	s2 = (char *)malloc(4 * sizeof(char));
	s1 = "bla";
	s2 = "blo";
	res = clean_join(s1, s2);
	printf("%s", res);
	free(res);
}