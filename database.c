#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH_BUCKETS 128 

struct database {
	char name [8];
	int height; 
	int weight; 
	struct database *next;
}; 

typedef struct database *DB_PTR;


void add_to_list (DB_PTR *l, DB_PTR e) 
{
	e->next = *l; 
	*l = e; 
}

/* -1 error/eof or 0 for success */
int read_entry (FILE *fp, DB_PTR entry)
{
	int n; 

	if (fp == NULL) {
		printf ("faulty pointer"); 
		exit (0); 
	}
	
	n =	fscanf (fp, "%s %d %d", entry->name, &entry->height, &entry->weight);
	if (n == EOF || n < 3) 
		return -1; 
	return 0;	
}

int hash (char name [8])
{
	int x, hash; 

	for (x = 0; x < 7; x++) {
		hash = hash + name[x]; 
	}
	return hash % MAX_HASH_BUCKETS; 
}
				
void add_to_hash_list (DB_PTR *list, DB_PTR entry) 
{
	add_to_list (list, entry); 	
}


struct database *search_hash_list (DB_PTR hashtable[MAX_HASH_BUCKETS], char *name) 
{
	int index = hash (name); 
	struct database *tmp = hashtable[index];	

	while (tmp != NULL) {
		printf("%s\n", tmp->name); 
		if (strcmp (name, tmp->name) == 0) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}


DB_PTR hashtable [MAX_HASH_BUCKETS];

main()
{
	FILE *fp; 
	int i,rc;
	DB_PTR entry;
	char name_to_search [16];

	fp = fopen ("file.in", "r");
	if (fp == NULL) {
		printf ("failed to open file.in\n");
		exit (-1);
	}

	for (i = 0; i  < MAX_HASH_BUCKETS; i++) {
		hashtable[i] = NULL;
	}

	while (1) {
		entry = malloc (sizeof (struct database));
		if (entry == NULL) {
			printf ("malloc failed\n");
			exit (-2);
		}
		rc = read_entry (fp, entry);
		if (rc == -1) {
			free (entry);
			break;
		}
		int index = hash (entry->name); 
		add_to_hash_list (&hashtable[index], entry); 
	}

	
	printf("%s\n", hashtable[0]->name); 

	while (1) {
		printf ("entry name to search: ");
		scanf ("%s", name_to_search);
		printf ("\n");
		if (strcmp (name_to_search, "exit") == 0) {
			printf ("bye\n");
			exit (0);
		}
		entry = search_hash_list (hashtable, name_to_search);
		if (entry) {
			printf ("weight = %d height = %d\n", entry->weight, entry->height);
		}
		else {
			printf ("Name not found\n"); 
		}
	}
}





