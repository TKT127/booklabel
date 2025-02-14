#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include "prototype.h"

NAME* names = NULL, *name_tail;
AUTH* authors = NULL, *author_tail;
GEN* genre;
SERI* series;
NOTE* notes;
DATE* dates;
COUNT* counts;
REGIST* regist;


int main(void) {
	int mode;
	title();
	select_mode();
	return 0;
}

void title() {
	printf( "######################################################\n" );
	printf( "Application for booklabeling\n");
	printf( "made by tkt\tspecial thanks : sutsuk\n" );
	printf( "######################################################\n\n" );
}

void select_mode(){
	int i=0;
	printf("[Select mode]\n");
	printf("データ入力    ：1\n");
	printf("一覧表示      ：2\n");
	printf("データ削除    ：3\n");
	printf("データ読み出し：4\n");

	printf(">");
	i = getchar();
	switch (i) {
	case '1':
		in_data();
		break;
	case '2':
		display();
		break;
	case '3':
		del_data();
		break;
	case '4':
		read_data();
		break;
	default:
		printf("ERROR：正しい値を入力してください\n");
	}
}

void in_data() {
	printf( "[Input Title]\n>" );
	fflush(stdout);
	regist_name();

	printf("[Input Author]\n>");
	fflush(stdout);
}

void regist_name() {
	char str[128];
	NAME* esc;
	if (names == NULL) {
		names = (NAME*)malloc(sizeof(NAME));
		read(0, names->name, 128);
		names->next = NULL;
		name_tail = names->next;
	}
	else {
		read(0, str, 128);
		esc = names->next;
		while (esc) {
			if (strcmp(str, esc->name) == 0) {
				return;
			}
			esc = esc->next;
		}
		esc = (NAME*)malloc(sizeof(NAME));
		strcpy(esc->name, str);
		esc->next = NULL;
		name_tail = name_tail->next;
	}
}


void display() {

}

void del_data() {

}

void read_data() {

}