#ifndef TEDDY_MACHINE_H
#define TEDDY_MACHINE_H

typedef struct teddy_machine {
	unsigned int id;
	unsigned int probability;
	struct teddy_machine *next;
	struct teddy_machine *prev;
} teddy_machine;

// Cria uma lista de máquinas
teddy_machine *create_machine_list(unsigned int n_machines);

// Seleciona uma máquina da lista de máquinas
teddy_machine *select_machine(teddy_machine *list, unsigned int machine_place);

// Remove uma máquina da lista de máquinas
teddy_machine *remove_machine(teddy_machine *list, teddy_machine *rm);

// Libera a lista de máquinas e seus elementos
void destroy_machine_list(teddy_machine *list);

// Retorna um lugar de uma máquina
unsigned int get_place(unsigned int n_machines);

// Retorna uma tentativa de pegar um urso
unsigned int get_attempt();

// Imprime a tentativa de conseguir um urso em determinada máquina
void print_attempt(teddy_machine *list, unsigned int attempt);

// Imprime as máquinas remanescentes
void print_remaining_machines(teddy_machine *list);

#endif // TEDDY_MACHINE_H
