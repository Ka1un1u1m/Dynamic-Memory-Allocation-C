/*BUDDY LISTEN
 *Idee: ->Listen mit einträgen die jeweils um die Hälfte kleiner sind als die maximale Blockgröße,
 jede größe ist also nur einmal pro liste vorhanden.
 ->Wird ein zweites mal die größe verlangt so muss eine neue Liste wie im ersten Punkt gennant erstellt werden und mit der ersten verknüpft werden.
 ->Beim freigeben eines blocks wird dessen used flag auf 0 gesetzt und somit beim nächsten mal allozieren wiederverwendbar gemacht
 */

#include <stdlib.h>
#include "my_alloc.h"
#include "my_system.h"

//BLOCKSIZE = 8192 BYTES -> [4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8] -->> 8 Bytes bleiben übrig !

//Definieren einer Datenstructur für die Listen

typedef struct list{
	int used;
	struct list *next;
}list;


//Aufrunden der Angeforderten größe auf die nächst höhere Zweierpotenz
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

//Initialisiere eine erste liste mit der root Eigenschaft und einer weiteren an die angehängt wird
list *root;
list *list_node;
list *list_next;

void init_my_alloc() {
	if(root == NULL){
		root = get_block_from_system();

	}

}


void* my_alloc(size_t size) {
	//Größe des benötigten Platzes errechnet sich aus der benötigten Speicherfläche und der größe des verwaltungselements element
	int new_size  = buddy_size(size + sizeof(struct list));
	

	//position in der list structur berechnen 
	int pos_in_list1 = 0;
	
	//Hier sollen jeweils vier mögliche positionen für den wert der in size angefordert wurde berechnet werden... diese zunächst mal vier positionen werden dann auf ihr used flag im weiteren verlauf geprüft

//Die positionsfindung ist noch alles ander als gut
//Für kleine mengen funktioniert dies jedoch bleibt viel speicher übrig... über einen algorithmus zur vergabe der Positionen wäre ich sehr dankbar ;)
	int list_size = sizeof(struct list);

		switch(new_size){
		case 8:
			pos_in_list1 = 0;
		break;
		case 16:
			pos_in_list1 = list_size + new_size;
		break;
		case 32:
			pos_in_list1 = list_size + new_size;
		break;
		case 64:
			pos_in_list1 = list_size + new_size;
		break;
		case 128:
			pos_in_list1 = list_size + new_size;
		break;
		case 256:
			pos_in_list1 = list_size + new_size;
		break;
		case 512:
			pos_in_list1 = list_size + new_size;
		break;
		//Zusätzliche positionenen für kleiner bereiche sind möglich, wenn 1024 undf 2048 wegfallen
		//idee: immer zwei flächen hintereinander für die selbe größe belegen
		


	/*	
		case 1024:
			pos_in_list1 = sizeof(struct list) + new_size ;
		break;
		case 2048:
			pos_in_list1 = sizeof(struct list) + new_size ;
		break;*/
		default: exit(1);
	}


	list_next = root;
	
	//schauen ob in den schon vorhandenen Listen ob es ein used flag mit dem wert 0 gibt. Ist das der fall wird hier angehalten und die position des zeigers zurückgegeben
	while(list_next->next != NULL){
		if((list_next + pos_in_list1)->used == 0){
			break;
		
		}
		list_next = list_next->next;
	}
	
	list_node = list_next + pos_in_list1;
	
	if(list_node->used == 0){
		list_node->used = 1;
		return list_node + sizeof(struct list);
	}

	//Kann keine freie stelle in den vorhandenen Listen gefunden werden so soll eine neue Liste angefordert werden und die position der vorgesehenen Speicherfläche zurückgegeben werden
	
	list_next->next = get_block_from_system();
	list_next = list_next->next + pos_in_list1;
	list_next->used = 1;
	return list_next + pos_in_list1;
	


}

void my_free(void* ptr) {
	list *p = ptr;
	p->used = 0;
}
