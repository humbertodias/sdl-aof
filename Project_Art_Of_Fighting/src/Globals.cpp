#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include "Globals.h"
#include <cstdarg>

void
log (const char file[], int line, const char *format, ...)
{
	static char tmp_string[4096];
	static char tmp_string2[4096];
	static va_list ap;
#ifdef _WIN32
	va_start (ap, format);
	vsprintf_s (tmp_string, 4096, format, ap);
	va_end (ap);
	sprintf_s (tmp_string2, 4096, "\n%s(%d) : %s", file, line, tmp_string);
	OutputDebugString (tmp_string2);
#else
	va_start( ap, format );
	vprintf( format, ap );
	va_end( ap );
	printf ("\n%s(%d)", file,line);
#endif
}



int sprintf_s(char* buffer, size_t size, const char* format, ...) {
	va_list args;
	va_start(args, format);

#ifdef _WIN32
	int result = vsprintf_s(buffer, size, format, args);
#else
	int result = vsnprintf(buffer, size, format, args);
#endif

	va_end(args);
	return result;
}