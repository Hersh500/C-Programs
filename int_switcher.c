#include <stdio.h>

/*
	Switches ints from network order 
	to little endian
*/

unsigned int _int_switcher(unsigned int *x)
{
    char *b1;
    char temp;

    b1 = (char *) x;
    temp = *b1;
    *b1 = *(b1+3);
    *(b1+3) = temp;

    temp = *(b1+1);
    *(b1+1) = *(b1+2);
    *(b1+2) = temp;
    return (*x);
}

int main() {
	unsigned int y = 0x12345678;
	unsigned int z = _int_switcher(&y); 
	printf("z = %08x \n", z); 
}

