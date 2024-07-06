#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../C07/ex00/ft_strdup.c"
#include "../C07/ex01/ft_range.c"
#include "../C07/ex02/ft_ultimate_range.c"
#include "../C07/ex03/ft_strjoin.c"
#include "../C07/ex04/ft_convert_base.c"
#include "../C07/ex04/ft_convert_base2.c"
#include "../C07/ex05/ft_split.c"

int main()
{
	char *str = "    ++-+---++-dcrcmcmooododmrrrmorcmcrmomo";
	char *buff = ft_convert_base(str, "mrdoc", "0123456789");
	printf("ft_conver_base : \"%s\"\n\n", buff);

	strdup("");
	ft_strdup("");

	char *test[] = {"this", "is", "a", "test", "for", "ft_strjoin" , "and", "ft_split"};
	int test_size = sizeof(test) / sizeof(char*);
	char *sep = "%";
	
	char *joined_str = ft_strjoin(test_size, test, sep);
	printf("%s\n", joined_str);
#if 1
	char *charset = ",   ,     ,     ,,";
	printf("--- testing ft_split ----\n");
	char **words_list = ft_split(joined_str, charset);
	int i = 0;
	while(words_list[i])
	{
		printf("strlen(\"%s\") = %d\n", words_list[i], (int) strlen(words_list[i]));
		i++;
	}	
#endif
	return 0;
}
