/*
 * memory_heap.c
 *
 *  Created on: 5 nov. 2018
 *      Author: migueltoro
 */


#include "../types/memory_heap.h"

void grow_memory_heap(memory_heap * heap) {
	if (heap->size == heap->tam) {
		heap->tam = 2* heap->tam;
		heap->elements = (void *) realloc(heap->elements, sizeof(void *)*heap->tam);
//		assert(heap->elements != NULL && "no se ha podido reubicar la memoria");
	}
}

memory_heap memory_heap_create() {
	memory_heap r = {0, 10, malloc(10 * sizeof(void *)), 0, 0};
	return r;
}

memory_heap * memory_heap_add(memory_heap * heap, void * element) {
	grow_memory_heap(heap);
	heap->elements[heap->size] = element;
	heap->size = heap->size + 1;
	return heap;
}

void * memory_heap_copy_and_mem(memory_heap * heap, void * source, int size_element){
	check_argument(size_element >= 0,__FILE__,__LINE__,"El tama�o a copiar debe ser mayor o igual a cero");
	if(source == NULL || size_element == 0 ) return NULL;
	void * element = (void *) malloc(size_element);
	memcpy(element,source,size_element);
	memory_heap_add(heap, element);
	heap->size_memory += size_element;
	heap->num_access_memory_heap++;
//	printf("\n%d==%d=%d\n",size_element,heap->size_memory,heap->num_access_memory_heap);
	return element;
}

void * memory_heap_get_memory(memory_heap * heap,int size){
	if(size == 0) return NULL;
	void * element = (void *) malloc(size);
	memory_heap_add(heap, element);
	heap->size_memory = heap->size_memory +size;
	heap->num_access_memory_heap++;
//	printf("\n%d==%d==%d\n",size,heap->size_memory,heap->num_access_memory_heap);
	return element;
}

int memory_heap_size_memory(memory_heap * heap){
	return heap->size_memory;
}

void memory_heap_free(memory_heap * heap) {
	for (int i = 0; i < heap->size; i++) {
		free(heap->elements[i]);
	}
	free(heap->elements);
}

void memory_heap_clear(memory_heap * heap) {
	for (int i = 0; i < heap->size; i++) {
			free(heap->elements[i]);
		}
	free(heap->elements);
	heap->size=0;
	heap->tam=10;
	heap->size_memory = 0;
	heap->num_access_memory_heap = 0;
	heap->elements=malloc(10 * sizeof(void *));
}

bool memory_heap_isnull(memory_heap * heap){
	return heap->elements == NULL;
}

memory_heap memory_heap_global;
