//Waldner Kai

//Versuch Buddy System

#define SIZE 8192
#include <stdlib.h>

#include "my_alloc.h"
#include "my_system.h"

#define SIZE 8192

typedef struct node{
	short size;
	short used;
	struct node *next;
}node;

node *root8;
node *node8;

node *root16;
node *node16;

node *root32;
node *node32;

node *root64;
node *node64;

node *root128;
node *node128;

node *root256;
node *node256;


//Aufrunden zu nächster zweierpotenz
int buddy_size(int in){
        if(!((in-1)&in)){
               return in;
        }

        int count = 1;
        while(((in-1)&in) != 0){
                in >>= 1;
                count++;
        }
        in = in << count;
	return in;

}

void init_my_alloc() {
	
}


void* my_alloc(size_t size) {
	size = buddy_size(size+sizeof(struct node));
	
	switch(size){
		case 8:
			if(root8 == NULL){
				root8 = get_block_from_system();
				root8->used = 1;
				root8->size = SIZE;
				root8->size -= size;
				return root8 + sizeof(struct node);
			}

			if(root8->size == 0){
				root8->next = get_block_from_system();
				root8 = root8->next;
			}

			node8 = root8;
			
			while(node8->next != NULL){
				if(node8->next->used == 0){
					root8->size += size;
					break;
				}
				node8 = node8->next;
			}
			node8->next = node8 + size;
			node8 = node8->next;
			node8->used = 1;
			root8->size -= size;
			return node8 + sizeof(struct node);
			


		break;
		case 16:
			if(root16 == NULL){
                                root16 = get_block_from_system();
                                root16->used = 1;
				root16->size = SIZE;
				root16->size -= size;
                                return root16 + sizeof(struct node);
                        }

			if(root16->size == 0){
                                root16->next = get_block_from_system();
                                root16 = root16->next;
                        }


                        node16 = root16;

                        while(node16->next != NULL){
				if(node16->next->used == 0){
					root16->size += size;
					break;
				}
                                node16 = node16->next;
                        }
                        node16->next = node16 + size;
                        node16 = node16->next;
                        node16->used = 1;
			root16->size -= size;
                        return node16 + sizeof(struct node);

		break;
		case 32:
			if(root32 == NULL){
                                root32 = get_block_from_system();
                                root32->used = 1;
				root32->size = SIZE;
				root32->size -= size;
                                return root32 + sizeof(struct node);
                        }

			if(root32->size == 0){
                                root32->next = get_block_from_system();
                                root32 = root32->next;
                        }


                        node32 = root32;

                        while(node32->next != NULL){
				if(node32->next->used == 0){
					root32->size += size;
					break;
				}
                                node32 = node32->next;
                        }
                        node32->next = node32 + size;
                        node32 = node32->next;
                        node32->used = 1;
			root32->size -= size;
                        return node32 + sizeof(struct node);

		break;
		case 64:
			if(root64 == NULL){
                                root64 = get_block_from_system();
                                root64->used = 1;
				root64->size = SIZE;
				root64->size -= size;
                                return root64 + sizeof(struct node);
                        }

			if(root64->size == 0){
                                root64->next = get_block_from_system();
                                root64 = root64->next;
                        }


                        node64 = root64;

                        while(node64->next != NULL){
				if(node64->next->used == 0){
					root64->size += size;
					break;
				}
                                node64 = node64->next;

                        }
                        node64->next = node64 + size;
                        node64 = node64->next;
			root64->size -= size;
                        node64->used = 1;
                        return node64 + sizeof(struct node);

		break;
		case 128:
			if(root128 == NULL){
                                root128 = get_block_from_system();
                                root128->used = 1;
				root128->size = SIZE;
				root128->size -= size;
                                return root128 + sizeof(struct node);
                        }

			if(root128->size == 0){
                                root128->next = get_block_from_system();
                                root128 = root128->next;
                        }


                        node128 = root128;

                        while(node128->next != NULL){
				if(node128->next->used == 0){
					root128->size += size;
					break;
				}
                                node128 = node128->next;
                        }
                        node128->next = node128 + size;
                        node128 = node128->next;
                        node128->used = 1;
			root128->size -= size;
                        return node128 + sizeof(struct node);

		break;
		case 256:
			if(root256 == NULL){
                                root256 = get_block_from_system();
                                root256->used = 1;
				root256->size = SIZE;
				root256->size -= size;
                                return root256 + sizeof(struct node);
                        }

			if(root256->size == 0){
                                root256->next = get_block_from_system();
                                root256 = root256->next;
                        }


                        node256 = root256;

                        while(node256->next != NULL){
				if(node256->next->used == 0){
					root256->size += size;
					break;
				}
                                node256 = node256->next;
                        }
                        node256->next = node256 + size;
                        node256 = node256->next;
                        node256->used = 1;
			root256->size -= size;
                        return node256 + sizeof(struct node);
	
		break;
		
	}
	return get_block_from_system();
	
}


void my_free(void* ptr) {	
	node *p;
	p = ptr;
	p->used = 0;	
}

