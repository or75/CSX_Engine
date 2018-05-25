#pragma once

#include "CSX_Engine.h"

namespace CSX
{
	namespace Utils
	{
		MODULEINFO GetModuleInfo( PCHAR szModule );

		/* Wait dwMsec Load Module */
		bool IsModuleLoad( PCHAR szModule , DWORD dwMsec = 5000 );

		// convert int to char
		PCHAR itoa( int i );
		// convert char to int
		int atoi( PCHAR pStr1 );
	}
}