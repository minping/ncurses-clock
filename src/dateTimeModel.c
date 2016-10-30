/**
 *  dateTimeModel.c - ncurses-clock
 *
 *  This module defines functionality for updating strings with current date and time information.
 *  This is the Model portion of the MVC pattern. See clockWindow for View and main for Controller.
 *
 */

#include "dateTimeModel.h"


static const char *TIME_FORMAT_STRING = "%l:%M:%S %p";     // Format time as a string ( 2:03:56 PM)
static const char *DATE_FORMAT_STRING = "%A - %B %d, %Y";  // Format date as a string Sunday - October 30, 2016
static const size_t BUFFER_SIZE = 50;                      // Number of characters in string buffers


/**
 * Initialize a string to hold date/time information
 */
char *initBuffer() {
	char *buffer = malloc(BUFFER_SIZE);
	assert(buffer != NULL);
	return buffer;
}

/**
 * Update a string to contain a formatted sequence of characters representing the current time
 */
void updateTimeBuffer(char *timeBuffer) {
    time_t now = time(0);
    struct tm* tm_info;
    tm_info = localtime(&now);

    strftime(timeBuffer, BUFFER_SIZE, TIME_FORMAT_STRING, tm_info);
}

/**
 * Update a string to contain a formatted sequence of characters representing the current date
 */
void updateDateBuffer(char *dateBuffer) {
    time_t now = time(0);
    struct tm* tm_info;
    tm_info = localtime(&now);

    strftime(dateBuffer, BUFFER_SIZE, DATE_FORMAT_STRING, tm_info);
}

/**
 * Free memory allocated for a string holding date or time information
 */
void deleteBuffer(char **bufferRef) {
	free(*bufferRef);
	*bufferRef = NULL;
}