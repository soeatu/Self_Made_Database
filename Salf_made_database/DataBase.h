#pragma once

/*�v���g�^�C�v�錾*/
void st_pointfunc(void);
void Create_Database(void);
void Create_column_name(void);
void Add_CM_Data(void);
void Delete_Data(void);
void List_Data(void);
void Help_info(void);
void Exit_database(void);

/*�\���̒�`*/
struct command_rec {
	char *name;		//�R�}���h��
	void (*func)(); //�R�}���h�ɑΉ�����֐�
};

/*�\���̔z��̐錾*/
struct command_rec Command[] = {
	{"CreDB",Create_Database},
	{"CreCM",Create_column_name},
	{"Add",Add_CM_Data},
	{"Del",Delete_Data},
	{"List",List_Data},
	{"Help",Help_info},
	{"Exit",Exit_database},
	{NULL,NULL}
};

/*�f�[�^�x�[�X�\����*/
typedef struct database_main
{
	char table_name[32];			//�e�[�u����
	char column_name[10][32];		//�J�������@�s���̖���
	int  record[100][10];			//���R�[�h���t�B�[���h

}DB;
