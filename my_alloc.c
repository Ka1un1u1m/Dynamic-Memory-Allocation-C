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

node *root512;
node *node512;

node *root1024;
node *node1024;

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

void* my_alloc(size_t size){
	return get_block_from_system();

}
/*

void* my_alloc(size_t size) {
	//size = buddy_size(size+sizeof(struct node));
	size = buddy_size(size);
	if(size > 1024){
		exit(1);
	}
	switch(size){
		case 8:
			if(root8 == NULL){
				root8 = get_block_from_system();
				root8->used = 1;
				root8->size = SIZE;
				root8->size -= size;
				return root8 + sizeof(struct node);
			}

			if(root8->size < size + sizeof(struct node)){
				root8->next = get_block_from_system();
				root8 = root8->next + sizeof(struct node);
			}

			node8 = root8;
			
			
			while(node8->next != NULL){
				if(node8->next->used == 0){
					root8->size += size;
					break;
				}
				node8 = node8->next;
			}
			node8->next = node8 + size + sizeof(struct node);
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



			if(root16->size < size + sizeof(struct node)){
                                root16->next = get_block_from_system();
                                root16 = root16->next + sizeof(struct node);
                        }


                        node16 = root16;

                        while(node16->next != NULL){
				if(node16->next->used == 0){
					root16->size += size;
					break;
				}
                                node16 = node16->next;
                        }
                        node16->next = node16 + size + sizeof(struct node);
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


			if(root32->size < size + sizeof(struct node)){
                                root32->next = get_block_from_system();
                                root32 = root32->next + sizeof(struct node);
                        }


                        node32 = root32;

                        while(node32->next != NULL){
				if(node32->next->used == 0){
					root32->size += size;
					break;
				}
                                node32 = node32->next;
                        }
                        node32->next = node32 + size + sizeof(struct node);
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


			if(root64->size < size + sizeof(struct node)){
                                root64->next = get_block_from_system();
                                root64 = root64->next + sizeof(struct node);
                        }


                        node64 = root64;

                        while(node64->next != NULL){
				if(node64->next->used == 0){
					root64->size += size;
					break;
				}
                                node64 = node64->next;

                        }
                        node64->next = node64 + size + sizeof(struct node);
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

			if(root128->size < size + sizeof(struct node)){
                                root128->next = get_block_from_system();
                                root128 = root128->next + sizeof(struct node);
                        }


                        node128 = root128;

                        while(node128->next != NULL){
				if(node128->next->used == 0){
					root128->size += size;
					break;
				}
                                node128 = node128->next;
                        }
                        node128->next = node128 + size + sizeof(struct node);
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
			

			if(root256->size < size + sizeof(struct node)){
                                root256->next = get_block_from_system();
                                root256 = root256->next + sizeof(struct node);
                        }


                        node256 = root256;

                        while(node256->next != NULL){
				if(node256->next->used == 0){
					root256->size += size;
					break;
				}
                                node256 = node256->next;
                        }
                        node256->next = node256 + size + sizeof(struct node);
                        node256 = node256->next;
                        node256->used = 1;
			root256->size -= size;
                        return node256 + sizeof(struct node);
	
		break;
		case 512:
			if(root512 == NULL){
                                root512 = get_block_from_system();
                                root512->used = 1;
                                root512->size = SIZE;
                                root512->size -=size;
                                return root512 + sizeof(struct node);
                        }


                        if(root512->size < size + sizeof(node)){
                                root512->next = get_block_from_system();
                                root512 = root512->next + sizeof(struct node);
                        }


                        node512 = root512;

                        while(node512->next != NULL){
                                if(node512->next->used == 0){
                                        root512->size += size;
                                        break;
                                }
                                node512 = node512->next;
                        }
                        node512->next = node512 + size + sizeof(struct node);
                        node512 = node512->next;
                        node512->used = 1;
                        root512->size -= size;
                        return node512 + sizeof(struct node);

		break;
		case 1024:
			if(root1024 == NULL){
                                root1024 = get_block_from_system();
                                root1024->used = 1;
                                root1024->size = SIZE;
                                root1024->size -= size;
                                return root1024 + sizeof(struct node);
                        }


                        if(root1024->size < size + sizeof(struct node)){
                                root1024->next = get_block_from_system();
                                root1024 = root1024->next;
                        }


                        node1024 = root1024;

                        while(node1024->next != NULL){
                                if(node1024->next->used == 0){
                                        root1024->size += size;
                                        break;
                                }
                                node1024 = node1024->next;
                        }
                        node1024->next = node1024 + size + sizeof(struct node);
                        node1024 = node1024->next;
                        node1024->used = 1;
                        root1024->size -= (size + sizeof(struct node));
                        return node1024 + sizeof(struct node);

		break;
		default: return get_block_from_system();
		
	}
	return get_block_from_system();
	
}

*/
/*void my_free(void* ptr) {	
	node *p;
	p = ptr;
	p->used = 0;	
}
*/
void my_free(void* ptr){
	ptr = ptr - 8192;
}

