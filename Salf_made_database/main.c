#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "DataBase.h"

/*構造体変数宣言*/
static DB DataBase;

/*グローバル変数宣言*/
unsigned char Count_database_cre;	//テーブルが作られているか確認すう変数
unsigned char columu_count;			//カラムの数をカウント
unsigned char record_count;			//カラムの数をカウント

int main(void) {

	while (1) {
		st_pointfunc();
	}

	return 0;
}

void st_pointfunc(void) {
	//変数宣言
	struct command_rec *comand;
	char input_str[256];

	printf("コマンドを入力してください：");
	scanf_s("%s", input_str, 256);

	//構造体配列の先頭から入力文字を比較
	for (comand = Command; comand->name != NULL; comand++) {
		if (strcmp(comand->name, input_str) == 0) {
			comand->func();							//コマンドに対応する関数を呼び出し
			return;									//コマンドが見つかったら終了
		}
	}
	printf("そのコマンドは存在しません。\n");
}

/*実行コマンド関数*/
void Create_Database(void) {

	unsigned short i = 0;

	for (i = 0; i < Count_database_cre; i++) {
		//DataBase++;
	}

	puts("テーブル名を入力してください。");
	scanf_s("%s", DataBase.table_name, 32);

	Count_database_cre++;
}

void Create_column_name(void) {

	if (Count_database_cre < 0) {
		puts("まだデータベースが作成されていません!");
		return;
	}

	puts("カラムを作成します。カラム名を入力してください。");
	scanf_s("%s", DataBase.column_name[columu_count], 32);

	columu_count++;
}

void Add_CM_Data(void) {
	
	unsigned char i = 0;

	if (columu_count < 0 || Count_database_cre < 0) {
		puts("データベースデータベースまたはカラムが作成されてません!");
		return;
	}
	
	puts("レコードを入力してください。");
	puts("この処理はカラムの個数分行われます");
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
		puts("データベースデータベースまたはカラム、レコードが作成されてません!");
		return;
	}
	puts("削除するレコード番号を入力してください。");
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

	puts("Helpを表示します");
	puts("データベース生成...........CreDB");
	puts("カラム生成.................CreCM");
	puts("レコード追加...............Add");
	puts("レコード削除...............Del");
	puts("Help表示...................Help");
	puts("プログラム終了.............Exit");

}

void Exit_database(void) {
	exit(0);
}
