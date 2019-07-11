/*
 * hash_table.h
 *
 *  Created on: 4 nov. 2018
 *      Author: migueltoro
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_


#include "../types/iterables.h"


typedef struct {
	void * key;
	void * value;
	int next;
} entry;

typedef struct {
	type key_type;
	int size_value;
    int * blocks;
	entry * data;
	int size;
	int capacity_blocks;
	int capacity_data;
	int first_free_data;
	float load_factor_limit;
	memory_heap hp;
} hash_table;

hash_table hash_table_empty(type key_type, int size_value);
int hash_table_size(hash_table * table);
void * hash_table_put_pointer(hash_table * table, void * key, void * value);
void * hash_table_put(hash_table * table, void * key, void * value);
void * hash_table_remove(hash_table * table, void * key);
void * hash_table_get(hash_table * table, void * key);
bool hash_table_contains(hash_table * table, void * key);

void hash_table_toconsole(hash_table * table, char * (*tostring_value)(const void * e,char * mem));

iterable hash_table_items_iterable(hash_table * ht);
char * hash_table_items_tostring(hash_table * ht, char * (*value_tostring)(const void * e, char * mem), char * mem);


void hash_table_free(hash_table * table);

hash_table complete_table();
void test_hash_table();
#endif /* HASH_TABLE_H_ */