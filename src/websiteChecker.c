/****************************************************************************
 * DESCRIPTION :
 *  This program calls a script if our website is reachable
 ****************************************************************************/

/****************************************************************************
 *                              INCLUDE FILES                               *
 ****************************************************************************/
#include "websiteChecker.h"

/****************************************************************************
 *                      PRIVATE TYPES and DEFINITIONS                       *
 ****************************************************************************/

/****************************************************************************
 *                              PRIVATE DATA                                *
 ****************************************************************************/

/****************************************************************************
 *                             EXTERNAL DATA                                *
 ****************************************************************************/

/****************************************************************************
 *                       PRIVATE METHOD DECLARATIONS                        *
 ****************************************************************************/
int checkWebsite(char* url);
void callScript(char* path);

/****************************************************************************
 *                            PRIVATE METHODS                               *
 ****************************************************************************/
/**
 * Performs a GET on a given URL to see if the website is alive.
 * Returns 0 on http status code 200, 1 otherwise.
 */
int checkWebsite(char* url) {
    return 0;
}

/**
 * Attempts to call a script.
 * Does not need to validate if script exists or if script successfully exits.
 */
void callScript(char* path) {

}

/****************************************************************************
 *                            PUBLIC METHODS                                *
 ****************************************************************************/
/**
 * Calls a script if a website is reachable.
 * Param 1: Website URL
 * Param 2: Script path
 * Returns 0 if website was up, 1 otherwise.
 */
int main(int argc, char **argv, char **envp) {
    return 0;
}
