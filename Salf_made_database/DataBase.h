#pragma once

/*プロトタイプ宣言*/
void st_pointfunc(void);
void Create_Database(void);
void Create_column_name(void);
void Add_CM_Data(void);
void Delete_Data(void);
void List_Data(void);
void Help_info(void);
void Exit_database(void);

/*構造体定義*/
struct command_rec {
	char *name;		//コマンド名
	void (*func)(); //コマンドに対応する関数
};

/*構造体配列の宣言*/
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

/*データベース構造体*/
typedef struct database_main
{
	char table_name[32];			//テーブル名
	char column_name[10][32];		//カラム名　行頭の名称
	int  record[100][10];			//レコード兼フィールド

}DB;
