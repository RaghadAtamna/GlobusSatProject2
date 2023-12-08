/*
 * menu_selection.c
 *
 *  Created on: Dec 1, 2023
 *      Author: tryfinally
 */

#include "menu_selection.h"

#include <stdio.h>

#include <hal/Utility/util.h>

Boolean quit_menu() { return FALSE; }

Boolean MenuSelectAndExecute(MenuAction menu[])
{
	int selection = 0;
	int index = 0;
	printf( "\n\r Select a test to perform: \n\r");
	while (menu->action) {
		printf("\t %-2d) %s\r\n", ++index, menu->menuSelection);
		++menu;
	}

	while(UTIL_DbguGetIntegerMinMax(&selection, 1, index) == 0){
		;
	}

	return menu[selection-1].action();
}

Boolean MenuDisplay(MenuAction menu[])
{
	do {
	} while(MenuSelectAndExecute(menu));

	return FALSE;
}

unsigned GetHexBuffer(unsigned int* buffer, unsigned int size)
{
	int input = 0;
	for (int i = 0; i < size; ++i) {
		if ( 0 == UTIL_DbguGetHexa32(&input) ) {
			return i;
		}
	}

	return size;
}






