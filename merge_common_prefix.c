#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "trie.h"


#define NUM_TEST_VALUES 100

int test_array[NUM_TEST_VALUES];
char test_strings[NUM_TEST_VALUES][10];

Trie *generate_trie(void)
{
	Trie *trie;
	int i;
	unsigned int entries;

	/* Create a trie and fill it with a large number of values */

	trie = trie_new();
	entries = 0;

	for(i = 0; i < NUM_TEST_VALUES; ++i) {
		test_array[i] = i;
		sprintf(test_strings[i], "%i", i);

		trie_insert(trie, test_strings[i], &test_array[i]);
		++entries;

		assert(trie_num_entries(trie) == entries);

	}

	return trie;



}

void lookup_trie(Trie * trie){

	int i;
	int *val;
	char buf[10];
	
	if (!trie) {
		printf("Error: trie is null!\n");
		return;
	}


	for(i = 0; i < NUM_TEST_VALUES; ++i) {
		sprintf(buf, "%i", i);
		val = (int *) trie_lookup(trie, buf);
		assert(*val == i);
		printf("%i \t", *val);
	}

	printf("\n");
	return ;

}


static void int_callback(TrieNode *node) {

	if(!node){
		return;
	}
	if(!node->data){
		return;
	}
	
	int * value = (int *) node->data;	
	
	printf("%i \t", *value);

	return;

}

static void str_callback(TrieNode *node) {

	if(!node){
		return;
	}
	if(!node->data){
		return;
	}
	
	char * value = (char *) node->data;	
	
	printf("%s\n", value);

	return ;
}

int main(int argc, char** argv) {

	/*
	Trie *trie = generate_trie();

	lookup_trie(trie);
	*/

	Trie * trie = trie_new();

	trie_insert(trie, "aa", "aa");
	trie_insert(trie, "ab", "ab");
	trie_insert(trie, "ac", "ac");

	trie_insert(trie, "ba", "ba");
	trie_insert(trie, "bb", "bb");
	trie_insert(trie, "bc", "bc");
	

	printf("-------------------------\n");

	trie_dfs(trie, str_callback);

	return 0;
}


