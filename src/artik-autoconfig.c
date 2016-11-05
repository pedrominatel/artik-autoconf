#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

void runCommand(char *cmd);

char ssid[20];
char password[40];

void printWelcome(void){

	fprintf(stdout," ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	fprintf(stdout,"                              Welcome to                                \n");
	fprintf(stdout,"  █████╗ ██████╗ ████████╗██╗██╗  ██╗ ██████╗ ██████╗ ███╗   ██╗███████╗\n");
	fprintf(stdout," ██╔══██╗██╔══██╗╚══██╔══╝██║██║ ██╔╝██╔════╝██╔═══██╗████╗  ██║██╔════╝\n");
	fprintf(stdout," ███████║██████╔╝   ██║   ██║█████╔╝ ██║     ██║   ██║██╔██╗ ██║█████╗  \n");
	fprintf(stdout," ██╔══██║██╔══██╗   ██║   ██║██╔═██╗ ██║     ██║   ██║██║╚██╗██║██╔══╝  \n");
	fprintf(stdout," ██║  ██║██║  ██║   ██║   ██║██║  ██╗╚██████╗╚██████╔╝██║ ╚████║██║     \n");
	fprintf(stdout," ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝     \n");
	fprintf(stdout,"              A easy way to configure your Artik 5 board                \n");
	fprintf(stdout," ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	fprintf(stdout,"   Developed by Pedro Minatel - github.com/pedrominatel/artik-autoconf  \n\n\n");

}

void printOptions(void){

	fprintf(stdout,"Select the option:\n\n");
	fprintf(stdout,"[1] - Scan for WiFi Networks\n");
	fprintf(stdout,"[2] - Configure Manually\n");
	fprintf(stdout,"[3] - List Configured Networks\n");
	fprintf(stdout,"[4] - Test Network Connection\n");
	fprintf(stdout,"[5] - Get IP Information\n");
	fprintf(stdout,"[6] - Restart Service\n");
	fprintf(stdout,"[7] - Install Arduino Deamon\n");
	fprintf(stdout,"[0] - Quit ArtikConf\n\n");

}

uint8_t getNetworkInput(void){

	fprintf(stdout, "Enter the network SSID: ");
	scanf("%s", ssid);
	fprintf(stdout, "Enter the network password: ");
	scanf("%s", password);

	return 0;
}

void getMenuOption(void){

	int menu_opt = 0;

	printOptions();

	fprintf(stdout, "Enter the desired menu number option: ");
	scanf("%d", &menu_opt);

	switch(menu_opt){
		case 0:
			exit(0);
		break;
		case 1:
		break;
		case 2:
			getNetworkInput();
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
			runCommand("/usr/bin/ifconfig");
		break;
		case 6:
		break;
		case 7:
		break;
		default:
		break;
	}

	getMenuOption();

}

void runCommand(char *cmd) {

	FILE *cmd_fp;
	char cmd_buff[1035];
	
	cmd_fp = popen(cmd, "r");

	if(cmd_fp==NULL){

		fprintf(stdout,"Failed to run command");
		exit(-1);
	}

	while(fgets(cmd_buff, sizeof(cmd_buff)-1, cmd_fp) != NULL){
		fprintf(stdout,"%s", cmd_buff);

	}

	pclose(cmd_fp);

}


/*
 * * Method to check root privileges
 * *
 * * @param...
 *
 */
uint8_t checkRootUID(void){

	uid_t uid = getuid(), euid = geteuid();
	
	if (uid==0 || euid==0) {
		return 0; //IS ROOT
	
	} else {
		fprintf(stderr, "Artik Conf needs ROOT privileges to run!\n");
		fprintf(stderr, "Try sudo before run it!\n");
		return 1; //NON ROOT
	}

}

/*
 * * Main method
 * *
 * * @param...
 *     
 */
int main(int argc, char **argv) {
	printWelcome();
	getMenuOption();
	exit(0);
}
