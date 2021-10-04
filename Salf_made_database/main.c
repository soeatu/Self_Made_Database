#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "DataBase.h"

/*�\���̕ϐ��錾*/
static DB DataBase;

/*�O���[�o���ϐ��錾*/
unsigned char Count_database_cre;	//�e�[�u��������Ă��邩�m�F�����ϐ�
unsigned char columu_count;			//�J�����̐����J�E���g
unsigned char record_count;			//�J�����̐����J�E���g

int main(void) {

	while (1) {
		st_pointfunc();
	}

	return 0;
}

void st_pointfunc(void) {
	//�ϐ��錾
	struct command_rec *comand;
	char input_str[256];

	printf("�R�}���h����͂��Ă��������F");
	scanf_s("%s", input_str, 256);

	//�\���̔z��̐擪������͕������r
	for (comand = Command; comand->name != NULL; comand++) {
		if (strcmp(comand->name, input_str) == 0) {
			comand->func();							//�R�}���h�ɑΉ�����֐����Ăяo��
			return;									//�R�}���h������������I��
		}
	}
	printf("���̃R�}���h�͑��݂��܂���B\n");
}

/*���s�R�}���h�֐�*/
void Create_Database(void) {

	unsigned short i = 0;

	for (i = 0; i < Count_database_cre; i++) {
		//DataBase++;
	}

	puts("�e�[�u��������͂��Ă��������B");
	scanf_s("%s", DataBase.table_name, 32);

	Count_database_cre++;
}

void Create_column_name(void) {

	if (Count_database_cre < 0) {
		puts("�܂��f�[�^�x�[�X���쐬����Ă��܂���!");
		return;
	}

	puts("�J�������쐬���܂��B�J����������͂��Ă��������B");
	scanf_s("%s", DataBase.column_name[columu_count], 32);

	columu_count++;
}

void Add_CM_Data(void) {
	
	unsigned char i = 0;

	if (columu_count < 0 || Count_database_cre < 0) {
		puts("�f�[�^�x�[�X�f�[�^�x�[�X�܂��̓J�������쐬����Ă܂���!");
		return;
	}
	
	puts("���R�[�h����͂��Ă��������B");
	puts("���̏����̓J�����̌����s���܂�");
	for (i = 0; i < columu_count; i++) {
		scanf_s("%d", &DataBase.record[record_count][i]);
	}
	record_count++;
	
}

void Delete_Data(void) {

	int num = 0;
	unsigned char input_recode_num = 0;
	unsigned char i = 0;
	unsigned char j = 0;

	if (columu_count < 0 || Count_database_cre < 0 || record_count < 0) {
		puts("�f�[�^�x�[�X�f�[�^�x�[�X�܂��̓J�����A���R�[�h���쐬����Ă܂���!");
		return;
	}
	puts("�폜���郌�R�[�h�ԍ�����͂��Ă��������B");
	scanf_s("%d", &num);

	input_recode_num = num;

	for (i = 0; i < record_count; i++) {
		if (i == input_recode_num) {
			for (j = 0; j < 10; j++) {
				DataBase.record[i][j] = 0;
			}
		}
	}
}

void List_Data(void) {

	unsigned char i = 0;
	unsigned char j = 0;

	for (i = 0; i < columu_count; i++) {
		printf(" %s ", DataBase.column_name[i]);
	}

	puts("");

	for (i = 0; i < record_count; i++) {
		for (j = 0; j < columu_count; j++){
			printf("  %d  ", DataBase.record[i][j]);
		}
		puts("");
	}
}

void Help_info(void) {

	puts("Help��\�����܂�");
	puts("�f�[�^�x�[�X����...........CreDB");
	puts("�J��������.................CreCM");
	puts("���R�[�h�ǉ�...............Add");
	puts("���R�[�h�폜...............Del");
	puts("Help�\��...................Help");
	puts("�v���O�����I��.............Exit");

}

void Exit_database(void) {
	exit(0);
}
