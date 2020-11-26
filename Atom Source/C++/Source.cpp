/* Includes */
#include <Windows.h>
#include <iostream>
#include "Atom.h"

INT main()
{
	SetConsoleTitleA("C++");

	Atom* atom;
	atom = new Atom;

	for (;;)
	{
		ATOM ida = 0;
		if (atom->Read("memory", ida))
		{
			std::cout << "Something Read" << std::endl;
		}
		else std::cout << "Nothing read" << std::endl;
	}
}