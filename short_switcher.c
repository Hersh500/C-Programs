#include <stdio.h>

/*
	This program switches bytes of short
	to convert from network order (Big Endian)
	to Little Endian
*/

unsigned short _short_switcher (unsigned short *x)
{
    char *p;
    char *p2;
    char temp;

    p = (char *) x;
    p2 = p + 1;
    temp = *p;
    *p = *p2;
    *p2 = temp;
    return (*x);
}

int main() {
	unsigned short y = 0x4567;
	unsigned short z = _short_switcher(&y);  
	
	printf("z is %04x", z); 
}
	
