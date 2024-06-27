#include <unistd.h>
#include <stdio.h>

#include "../C01/ex00/ft_ft.c"
#include "../C01/ex01/ft_ultimate_ft.c"
#include "../C01/ex02/ft_swap.c"
#include "../C01/ex03/ft_div_mod.c"
//#include "../C01/ex04/ft_ultimate_div_mod.c"
//#include "../C01/ex05/ft_putstr.c"
//#include "../C01/ex06/ft_strlen.c"
//#include "../C01/ex07/ft_rev_int_tab.c"
//#include "../C01/ex08/ft_sort_int_tab.c"


int main()
{
	//testing ex00
	int a = 1337;
	printf("a = %d\n", a);
	ft_ft(&a);
	printf("ft_ft : %d\n\n", a);

	//testing ex01
	a = 59543;
	printf("a = %d\n", a);
	int *a1 = &a;
	int **a2 = &a1;
	int ***a3 = &a2;
	int ****a4 = &a3;
	int *****a5 = &a4;
	int ******a6 = &a5;
	int *******a7 = &a6;
	int ********a8 = &a7;
	int *********a9 = &a8;
	ft_ultimate_ft(a9);
	printf("ft_ultimate_ft: %d\n\n", a);	

	//testing ex02
	int b = 1337;
	int c = 4242;
	printf("b=%d, c=%d\n",b,c);
	ft_swap(&b, &c);
	printf("ft_swap: b=%d, c=%d", b, c);
	
	//testing ex03
	int diva =  513;
	int divb = 50;
	int div;
	int mod;
	ft_div_mod(diva, divb, &div, &mod);
	printf("ft_div_mod: %d / %d  = %d | mod = %d", diva, divb, div, mod);
	
	
	return 0;
}
