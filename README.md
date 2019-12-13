# Dynamic-Memory-Allocation-C
  Software project for the competition at the University of Ulm

The goal ist to implement a dynamic memory allocation in C language without using malloc, calloc, realloc or free.
Given is a test environment which measure the time and wasted memory. On this base the test environment shows points. 
All members of the course Systemnahe Software mit C 1 who take part in this competition will be compared with their total Points.
Up to 1 000 000 operations by an automated test case will be done.

The exercise is to write three fuctions:
  -init_my_alloc() "If not necessary ceep this function empty in file"
  -my_alloc(size_t size)
  -my_free(void* ptr)
  
 By calling get_block_from_system() you will get a pointer void* with 8192 Bytes of free memory from the System. The given alignment is 8.
 
 Idea: (simple but slow)
 
  linked list -> maybe splitted in bucktes to increase speed of allocating
  
  
 
 
