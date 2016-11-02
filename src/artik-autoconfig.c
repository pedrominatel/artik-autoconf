#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

/**
 *  * Method defex_checkRootUID
 *   *
 *    * @param...
 *     */
uint8_t checkRootUID(void){

	uid_t uid = getuid(), euid = geteuid();
	
	if (uid==0 || euid==0) {
		return 0; //IS ROOT
	
	} else {
		fprintf(stderr, "Defex needs ROOT privileges to run!\n");
		fprintf(stderr, "Try sudo before run!\n");
		return 1; //NON ROOT
	}

}

/**
 *  * Main method...
 *   *
 *    * @param...
 *     */
int main(int argc, char **argv) {


	  FILE *fp;
	    char path[1035];

	      /* Open the command for reading. */
	      fp = popen("/bin/ls -la /etc/", "r");
	        if (fp == NULL) {
			    printf("Failed to run command\n" );
			        exit(1);
				  }

		  /* Read the output a line at a time - output it. */
		  while (fgets(path, sizeof(path)-1, fp) != NULL) {
			      printf("%s", path);
			        }

		    /* close */
		    pclose(fp);



	if (checkRootUID())
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
