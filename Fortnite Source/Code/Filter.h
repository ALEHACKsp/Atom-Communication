/* A filter developed by Interpreter#1338 for the Rapid Aim communication systems */

/* Source */
#include "F_Hooks.h"

void Filter(std::string function)
{
	/* Aimbot */
	if (function == E("Aimbot"))
	{
		if (settings::aimtype = 1) // If Aimbot is enabled
		{
			/* Turn it off */
			settings::aimtype = 3;
		}
		else
		{
			/* Turn it on */
			settings::aimtype = 1;
		}
	}

	/* ESP (Box) */
	if (function == E("ESP Box"))
	{
		settings::fov = 500;
		if (settings::boxesp = true) // If Box esp is enabled
		{
			/* Turn it off */
			settings::boxesp = false;
		}
		else
		{
			/* Turn it on */
			settings::boxesp = true;
		}
	}

	/* ESP (Lines) */
	if (function == E("ESP Lines")) // If Box lines is enabled
	{
		if (settings::snaplines == true)
		{
			/* Turn it off */
			settings::snaplines = false;
		}
		else
		{
			/* Turn it off */
			settings::snaplines = true;
		}
	}

	/* Sniper TP */
	if (function == E("Sniper TP")) // If Sniper TP is enabled
	{
		if (settings::sniperbullettp == true)
		{
			/* Turn it off */
			settings::sniperbullettp = false;
		}
		else
		{
			/* Turn it off */
			settings::sniperbullettp = true;
		}
	}
}