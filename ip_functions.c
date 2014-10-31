#include <stdio.h>
typedef unsigned int uint32; 

//Stores an int IP in a string 
void conv_ip_to_str (char *str, uint32 ip)
{       
	sprintf (str, "%u.%u.%u.%u", 
        	(ip & 0xff000000) >> 24,
        	(ip & 0x00ff0000) >> 16, 
        	(ip & 0x0000ff00) >> 8, 
        	(ip & 0x000000ff)); 
}

//Prints out an IP Address in the commonly recognized form
void print_dotted_ips (uint32 *ip)
{       
        int tmp = 0; 
        tmp = (*ip & 0xff000000) >> 24; 
        printf("%d.", tmp);
        tmp = (*ip & 0x00ff0000) >> 16; 
        printf("%d.", tmp); 
        tmp = (*ip & 0x0000ff00) >> 8; 
        printf("%d.", tmp); 
        tmp = (*ip & 0x000000ff); 
        printf("%d", tmp);      
}

