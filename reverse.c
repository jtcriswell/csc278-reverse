/*
 * File: reverse.c
 *
 * Description:
 *  This file contains the source code for the reverse program.  This program
 *  reads a list of 32-bit numbers from a file and writes them into a new file
 *  in reverse order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int
main (int argc, char ** argv) {
  /* The value read from the file */
  uint32_t value;

  /* Pointers to the names of the input and output file names */
  char * inputPathname = NULL;
  char * outputPathname = NULL;

  /* The file descriptors for the input file and output file, respectively */
  int ifd = 0;
  int ofd = 0;

  /*
   * Determine if the user specified the correct number of arguments.  If the
   * user did so, use two pointers to locate the pathnames to make this code
   * more readable.
   */
  if (argc == 3) {
    inputPathname = argv[1];
    outputPathname = argv[2];
  } else {
    fprintf (stderr, "Incorrect number of arguments.\n");
    fprintf (stderr, "Usage: %s <input pathname> <output pathname>\n", argv[0]);
    return -1;
  }

  /*
   * Open the input file for reading and the output file for writing.
   */
  if ((ifd = open (inputPathname, O_RDONLY)) == -1) {
    fprintf (stderr, "Cannot open input file %s: ", inputPathname);
    fprintf (stderr, "%s\n", strerror(errno));
    return -2;
  }

  /*
   * Close the files.
   */
  close (ifd);
  close (ofd);

  /*
   * Terminate this process with a zero (successful) exit status.
   */
  return 0;
}
