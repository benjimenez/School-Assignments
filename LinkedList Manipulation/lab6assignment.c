/*
Benjamin Jimenez
CSCE-1040
Lab 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char   *name;
  float  balance;
  struct account *next;
};

int main()
{
	int listID;
	int i, j;
  float  balance;
  char   name[20];
  struct account *list1head = NULL;
  struct account *list1tail = NULL;

  struct account *list2head = NULL;
  struct account *list2tail = NULL;

  struct account *walk = NULL;

  while(scanf("%d%s%f", &listID, name, &balance) != EOF) {

		if(listID == 1) {
			if(list1head == NULL) {

				list1head = (struct account *) malloc(sizeof(struct account));
				list1head->next = NULL;
				list1tail = list1head;

    	}
			else {

				list1tail->next = (struct account *) malloc(sizeof(struct account));
				list1tail = list1tail->next;
				list1tail->next = NULL;

			}

				list1tail->name = (char *) malloc(sizeof(char) * strlen(name) + 1);
				strcpy(list1tail->name, name);
				list1tail->balance = balance;

		}
		else { // listID == 2
      if(list2head == NULL) {

				list2head = (struct account *) malloc(sizeof(struct account));
				list2head->next = NULL;
                            list2tail = list2head;


      }
      else {

				list2tail->next = (struct account *) malloc(sizeof(struct account));
                            list2tail = list2tail->next;
                            list2tail->next = NULL;


      }
		}

				list2tail->name = (char *) malloc(sizeof(char) * strlen(name) + 1);
				strcpy(list2tail->name, name);
				list2tail->balance = balance;

  }
	i = 0;
	walk = list1head;
	while(walk != NULL){
		i++;
              walk = walk->next;
       }
	printf("\nList1 consists of %d nodes.\n", i);

	j = 0;
	walk = list2head;
	while(walk != NULL){
		j++;
              walk = walk->next;
       }
	printf("\nList2 consists of %d nodes.\n\n", j);



	if(i > j) {


		// print list1
		walk = list1head;
		while(walk != NULL) {
    			printf("%20s %8.2f\n", walk->name, walk->balance);
    			walk = walk->next;
  		}
		
		// print list2
		walk = list2head;
  		while(walk != NULL) {
    			printf("%20s %8.2f\n", walk->name, walk->balance);
    			walk = walk->next;
  		}

	}
	else {

		// print list2
		walk = list2head;
  		while(walk != NULL) {
    			printf("%20s %8.2f\n", walk->name, walk->balance);
    			walk = walk->next;
  		}

		// print list1
		walk = list1head;
		while(walk != NULL) {
    			printf("%20s %8.2f\n", walk->name, walk->balance);
    			walk = walk->next;
  		}

	}

  return;
}
