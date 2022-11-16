#include "main.h"
#include "printf.h"

/**
 * signalHandler - continues when a control c is detected
 * @control: control
 */

void signalHandler(int control)
{
	(void)control;
	_printf("\n");
	write(STDIN_FILENO, "$ ", 2);
}
