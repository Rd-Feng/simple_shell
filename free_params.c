#include "lists.h"
#include "myShell.h"
#include <stdlib.h>
/**
 * free_params - frees our state object from memory
 * @params: - param structure to free
 */
void free_params(param_t *params)
{
	unsigned int i;

	if (params->buffer)
		free(params->buffer);
	if (params->nextCommand)
		free(params->nextCommand);
	ree_list(params->env_head);
	free_list(params->alias_head);

	for (i = 0; params->args[i]; i++)
		free(params->args[i]);
	free(params->args);
	free(params);
}
