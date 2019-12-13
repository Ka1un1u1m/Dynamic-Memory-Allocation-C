//Waldner Kai

/*Erste idee ist es eine einfach verkettete liste zu implementieren die sich ggf. durch verwenden
 * eine art Bucket-Struktur erweitern lässt um bspw. die Laufzeit zu verbessern.
 * Grundsätzlich soll es einen int used geben der angibt ob die Fläche belegt ist (1)
 * size beschreibt die größe des elements
 * next verweist auf nächstes element in der Liste
 * versucht wird auch ein zusammenfügen von nebeneinanderliegenden leeren elementen
 */

#include <stdlib.h>
#include "my_alloc.h"
#include "my_system.h"

//Struktur eines Listenelements
typedef struct memnode{
	int size;
	int used;
	struct memnode *next;
}memnode;

#define SIZE 8192

//root soll für das Bereitstellen des gesamten Speichers der von get_block_from_system() kommt verwendet werden und ggf. wenn root->size nicht mehr ausreicht mit root->next auf einen neuen behälter mit freier Fläche zeigen
memnode *root = NULL;
memnode *node = NULL;
void init_my_alloc() {
}

void* my_alloc(size_t size) {

	if(root == NULL){
		root = get_block_from_system();
		root->size = SIZE;
		root->next = NULL;
		root->used = 0;
	}

	node = root;
	memnode *newnode;

	memnode *ptr = node;

	do{
		if(ptr->size >= size + sizeof(struct memnode)){
			node = ptr;
			break;
		}
		ptr = ptr->next;
	}while(ptr->next != NULL);
	
	while(1){
		if(node->next != NULL){
			if(node->used == 0 && node->next->used == 0){
				node->next = (memnode*)((char*) node->next - node->size - sizeof(struct memnode));
				node = node->next;
			}
		}

		if(node->size >= size + sizeof(struct memnode)){
			newnode = (memnode*)((char*) node + node->size - sizeof(struct memnode) - size);
			newnode->size = size;
			newnode->used = 1;
			node->size -= (size + sizeof(struct memnode));
			break;
		}else{
			node->next = get_block_from_system();
			node = node->next;
			node->size = SIZE;
			node->next = NULL;
		}

	}

	return newnode ;
}


void my_free(void* ptr) {
	memnode *p;
	p = ptr;
	p->used = 0;
	
}

