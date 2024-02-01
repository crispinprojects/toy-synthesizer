/***************************************************************************
 *   Author Alan Crispin                                                   *
 *   crispinalan@gmail.com                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation.                                         *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //needed for memcpy

#include <stdint.h>
#include <termios.h>
#include <unistd.h>

//notes
#include "notes.h"

//ascii codes for keys   
#define KEY_Q 113
// lower keys
#define KEY_Z 122
#define KEY_X 120
#define KEY_C 99
#define KEY_V 118
#define KEY_B 98
#define KEY_N 110
#define KEY_M 109
void play_a(){	
	unsigned char *data = (unsigned char*)malloc(A_saw_raw_len * sizeof(unsigned char));
	memcpy(data, A_saw_raw, A_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = A_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);		
}

void play_b(){	
	unsigned char *data = (unsigned char*)malloc(B_saw_raw_len * sizeof(unsigned char));
	memcpy(data, B_saw_raw, B_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = B_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);		
}

void play_c(){	
	unsigned char *data = (unsigned char*)malloc(C_saw_raw_len * sizeof(unsigned char));
	memcpy(data, C_saw_raw, C_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = C_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);		
}

void play_d(){	
	unsigned char *data = (unsigned char*)malloc(D_saw_raw_len * sizeof(unsigned char));
	memcpy(data, D_saw_raw, D_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = D_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);			
}
void play_e(){	
	unsigned char *data = (unsigned char*)malloc(E_saw_raw_len * sizeof(unsigned char));
	memcpy(data, E_saw_raw, E_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = E_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);		
}

void play_f(){	
	unsigned char *data = (unsigned char*)malloc(F_saw_raw_len * sizeof(unsigned char));
	memcpy(data, F_saw_raw, F_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = F_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);		
}

void play_g(){	
	unsigned char *data = (unsigned char*)malloc(G_saw_raw_len * sizeof(unsigned char));
	memcpy(data, G_saw_raw, G_saw_raw_len * sizeof(unsigned char)); //copy  note into data	
	unsigned int data_len = G_saw_raw_len;	
    char *raw_file ="out.raw";
	FILE* f = fopen(raw_file, "w");
    fwrite(data, data_len, 1, f);
    fclose(f);   
	char * command_str ="aplay -c 1 -f U8 out.raw";        
    system(command_str);	
	free(data);		
}


int main(int argc, char **argv)
{	
	printf("toy piano\n");	
	
	struct termios attr;
    tcgetattr(STDIN_FILENO, &attr);
    attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &attr);
    uint8_t buf[20];
    ssize_t bytes;
    while ((bytes = read(STDIN_FILENO, buf, 20)) > 0) {
        //for (size_t i = 0; i < bytes; i++) {
            //printf("%zd: %hhu\n", i, buf[i]);
        //}
        if ( buf[0] == KEY_Z) { //z
			printf("A tone\n");
			play_a();
		}
        if ( buf[0] == KEY_X) { //x
			printf("B tone\n");
			play_b();
		}
        if ( buf[0] == KEY_C) { //c
			printf("C tone\n");
			play_c();
		}
		 if ( buf[0] == KEY_V) { //v
			printf("D tone\n");
			play_d();
		}
		 if ( buf[0] == KEY_B) { //b
			printf("E tone\n");
			play_e();
		}
		if ( buf[0] == KEY_N) { //n
			printf("F tone\n");
			play_f();
		}
		if ( buf[0] == KEY_M) { //m
			printf("G tone\n");
			play_g();
		}
		if ( buf[0] == KEY_Q) { //m
			printf("Quit\n");
			break;
		}			
		
    } //while
		
	return 0;
}

