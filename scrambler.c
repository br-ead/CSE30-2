#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int opt;
	bool scramble = true;
	while ((opt = getopt(argc, argv, "us")) != -1) {
		switch (opt) {
		case 's':
			scramble = true;
			break;
		case 'u':
			scramble = false;
			break;
		case '?':
			fprintf(stderr, "unknown option: %c\n", opt);
			return 1;
		default:
			fprintf(stderr, "unexpcted option: %c\n", opt);
			abort();
		}
	}

	// TODO: command line error checking
	if (argc !=4) {
	fprintf(stderr, "usage: %s <-s | -u> <input-file> <key>\n", argv[0]);
	return EXIT_FAILURE;
	}	
	// This suppresses warnings; TODO remove after you use these variables


	// file is now in argv[2] and key is in argv[3]

	// TODO: FILE *fin = fopen( /* Read from input file */ );
	// TODO: Remember to handle errors!

	FILE* one = fopen(argv[2], "r");
	//FILE* two = fopen(argv[3], "r");
	if (!one) {
		fprintf(stderr, "The selected %s is not available.\n", argv[2]);
		return EXIT_FAILURE;
	}
	int count=strlen(argv[3]);
	/*int key=' ';
	int second[10000]; */
	/* while((key=fgetc(two))!=EOF) {
		count=count+1;
		second[count]=key;	
	} */
	if (scramble==true) {
		int x=fgetc(one);
		int counter=0;
		while (x!= EOF) {
			if (counter==count) {
				counter=0;
			}
			if(x<65 || x>90) {
				if (x>=123 || (x>90 && x<97) || x<65) {
				       	while ( (x!=EOF)&& ( (x>122) || ((x<97)&&(x>90)) || ((x<65)))) {
						x=fgetc(one);
					}
				}
				if (x>96 && x<123) {
					x=x-32;
				}
			}
			if (x>=65 && x<=90) {
			
	
				char value = ((x-'A')+(argv[3][counter]-'A'))%26+'A';
				//printf("%c",x);
				x=fgetc(one);
				//printf("%d",counter+1);
				//printf("%c",second[counter+1]);
				printf("%c",value);
				//printf("%d\n",value);
			}
			counter=counter+1;
		}
	}		
	else {
	int x=fgetc(one);
		int counter=0;
		while (x!= EOF) {
			if (counter==count) {
				counter=0;
			}
			if(x<65 || x>90) {
				if (x>=123 || (x>90 && x<97) || x<65) {
				       	while ( (x!=EOF)&& ( (x>122) || ((x<97)&&(x>90)) || ((x<65)))) {
						x=fgetc(one);
					}
				}
				if (x>96 && x<123) {
					x=x-32;
				}
			}
			if (x>=65 && x<=90) {
			
	
				char value = ((x-'A')+26-(argv[3][counter]-'A'))%26+'A';
				printf("%c",value);
				x=fgetc(one);
			
				//printf("%d",counter+1);
				//printf("%c",second[counter+1]);
				//printf("%c",value);
				//printf("%d\n",value);
			}
			counter=counter+1;
		}
	}
	printf("\n");
	// TODO: do your thing
	// TODO: close the file
	fclose(one);
	//fclose(two);
	return 0;
}
