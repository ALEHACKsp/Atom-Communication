/* Includes */
#include <Windows.h>
#include <iostream>
#include "Trampoline.h"

/* Atom */
class Atom {
public:
	bool Read(LPCSTR str, ATOM id);
};

bool Atom::Read(LPCSTR str, ATOM id)
{
	id = Spoofcall(jmp, GlobalFindAtomA, str);
	if (id != 0)
		return true;
	else return false;
}