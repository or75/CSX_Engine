#include "CSX_Memory.h"

#define INRANGE(x,a,b)	(x >= a && x <= b) 
#define getBits( x )	(INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )	(getBits(x[0]) << 4 | getBits(x[1]))

namespace CSX
{
	namespace Memory
	{
		PVOID FindPattern( PCHAR pPattern , __int3264 dwStart , __int3264 dwEnd , DWORD dwOffset )
		{
			const char* pPat = pPattern;
			__int3264 dwFind = 0;

			for ( __int3264 dwPtr = dwStart; dwPtr < dwEnd; dwPtr++ )
			{
				if ( !*pPat )
					return (PVOID)dwFind;

				if ( *(PBYTE)pPat == '\?' || *(PBYTE)dwPtr == getByte( pPat ) )
				{
					if ( !dwFind )
						dwFind = dwPtr;

					if ( !pPat[2] )
						return (PVOID)( dwFind + dwOffset );

					if ( *(PWORD)pPat == '\?\?' || *(PBYTE)pPat != '\?' )
						pPat += 3;
					else
						pPat += 2;
				}
				else
				{
					pPat = pPattern;
					dwFind = 0;
				}
			}

			return 0;
		}

		PVOID FindPattern( PCHAR szModule , PCHAR pPattern , DWORD dwOffset )
		{
			MODULEINFO mInfo = CSX::Utils::GetModuleInfo( szModule );

			__int3264 dwStart = (__int3264)mInfo.lpBaseOfDll;
			DWORD dwSize = mInfo.SizeOfImage;

			return FindPattern( pPattern , dwStart , dwStart + dwSize , dwOffset );
		}
	}
}