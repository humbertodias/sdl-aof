#ifndef __MEMLEAKS_H__
#define __MEMLEAKS_H__

	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	// #include <crtdbg.h>

	#ifdef _DEBUG
		#ifndef DBG_NEW
			#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
			#define new DBG_NEW
		#endif
	#endif  // _DEBUG

	#ifdef _WIN32
	// Definição para Windows (usando _CrtSetDbgFlag do Visual Studio)
	#include <crtdbg.h>
	#define ReportMemoryLeaks() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
	#elif __APPLE__
	// Definição para macOS (usando malloc stack logging)
	#include <stdlib.h>
	#define ReportMemoryLeaks() setenv("MallocStackLogging", "1", 1)
	#else
	// Para outros sistemas operacionais (ou desabilitado)
	#define ReportMemoryLeaks() ((void)0)  // Sem efeito
	#endif

#endif // __MEMLEAKS_H__