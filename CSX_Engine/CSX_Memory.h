#pragma once

#include "CSX_Engine.h"

namespace CSX
{
	namespace Memory
	{
		/* IDA Style 00 FF ?? */

		PVOID FindPattern( PCHAR pPattern , __int3264 dwStart , __int3264 dwEnd , DWORD dwOffset );
		PVOID FindPattern( PCHAR szModule , PCHAR pPattern , DWORD dwOffset );
	}
}