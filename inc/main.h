#ifndef MAIN_H
#define MAIN_H

#define VERSION "1.0.1"
#define AUTHOR "Wasty McWastface"
#define AUTHOR_EMAIL "waste@digdig.org"

#define MAX_PATH_LENGTH 4096

#ifdef DEBUG
#define RED_CODE "\033[31m"
#define GREEN_CODE "\033[32m"
#define BLUE_CODE "\033[34m"
#define RESET_CODE "\033[0m"

#define debug_print(fmt, ...)                                           \
	fprintf(stderr,                                                 \
		BLUE_CODE "DEBUG" RED_CODE ":" GREEN_CODE "%s" RED_CODE \
			  ":" GREEN_CODE "%d" RED_CODE ":" GREEN_CODE   \
			  "%s()" RED_CODE ": " RED_CODE fmt RESET_CODE, \
		__FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
#define debug_print(fmt, ...) \
	do {                  \
	} while (0) // ali a voice: "Nothinggg!??"
#endif // DEBUG
#endif // MAIN_H
