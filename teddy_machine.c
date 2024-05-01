#include <stdlib.h>
#include <stdio.h>
#include "teddy_machine.h"

teddy_machine *create_machine_list(unsigned int n_machines) {
        if (n_machines == 0) {
                fprintf(stderr, "create_machine_list(): [-] Invalid n_machines input\n");

                return NULL;
        }
        
        teddy_machine *list = (teddy_machine *)malloc(sizeof(teddy_machine));

        if (!list) {
                fprintf(stderr, "[-] Allocation error in create_machine_list()\n");

                return NULL;
        }

        teddy_machine *aux = list;
        list->probability = 5;
        list->id = 0;
        list->prev = list;
        list->next = list;

        for (unsigned int i = 0; i < n_machines - 1; i++) {
                teddy_machine *new_machine = (teddy_machine *)malloc(sizeof(teddy_machine));

                if (!new_machine) {
                        fprintf(stderr, "create_machine_list(): [-] Allocation error on for loop inside create_machine()\n");
                        destroy_machine_list(list);

                        return NULL;
                }

                new_machine->probability = 5;
                new_machine->id = i + 1;
                new_machine->next = list;
                new_machine->prev = aux;
                aux->next = new_machine;
                list->prev = new_machine;
                aux = aux->next;
        }

        return list;
}

teddy_machine *select_machine(teddy_machine *list, unsigned int machine_place) {
        if (!list) {
                fprintf(stderr, "select_machine(): [-] The list doesn't exist\n");

                return NULL;
        }

        teddy_machine *aux = list;
        unsigned int i = 0;

        do {
                if (i == machine_place)
                        return aux;

                aux = aux->next;
                i++;
        } while (aux != list);

        return list;
}

unsigned int get_place(unsigned int n_machines) { return rand() % n_machines; }

unsigned int get_attempt() { return rand() % 100 + 1; }

void print_attempt(teddy_machine *machine, unsigned int attempt) {
	if (attempt <= machine->probability)
		printf("O URSO DA MAQUINA %u [FOI] OBTIDO!\n", machine->id);
	else
		printf("O URSO DA MAQUINA %u [NAO FOI] OBTIDO!\n", machine->id);
}

void print_remaining_machines(teddy_machine *list) {
	if (!list) {
		printf("NAO HA MAQUINAS DISPONIVEIS!\n");

		return;
	} else {
		teddy_machine *aux = list;

		do {
			printf("PROBABILIDADE DA MAQUINA %u: %u\n", aux->id, aux->probability);
			aux = aux->next;
		} while (aux != list);
	}
}

teddy_machine *remove_machine(teddy_machine *list, teddy_machine *rm) {
	if (!list || !rm) {
		fprintf(stderr, "remove_machine(): [-] The list or rm are NULL\n");

		return NULL;
	}

        if (list == rm) {
                if (rm->next == list) {
                        free(rm);
                        rm = NULL;

                        return NULL;
                }

                list = rm->next;
        }

        rm->prev->next = rm->next;
	rm->next->prev = rm->prev;
	free(rm);
	rm = NULL;

	return list;
}

void destroy_machine_list(teddy_machine *list) {
	if (!list) {
		fprintf(stderr, "destroy_machine_list(): [-] Can't destroy an list that's already empty\n");

		return;
	}

	teddy_machine *aux_traverse = list;
        
        do {
                teddy_machine *aux_free = list;
                list = list->next;
                free(aux_free);
                aux_free = NULL;
        } while (list != aux_traverse);

	list = NULL;
}
