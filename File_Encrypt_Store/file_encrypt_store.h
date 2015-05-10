#ifndef FILE_ENCRYPT_STORE_H
#define FILE_ENCRYPT_STORE_H

#include <QtGui/QMainWindow>
#include "ui_file_encrypt_store.h"
#include "Sql_Interface.h"
#include <QFileDialog>
#include <QMessageBox>

#define DATA_BASE_NAME "ENCRYPT_FILE"

class File_Encrypt_Store : public QMainWindow
{
	Q_OBJECT

private:
	Ui::File_Encrypt_StoreClass ui;
	MySql encrypt_key_sql;


public:
	File_Encrypt_Store(QWidget *parent = 0, Qt::WFlags flags = 0);
	~File_Encrypt_Store();

public:
	void Init_Signal_Slots();

	void display_key_list();
	void display_cipher_list();

	void dynamic_display_ciphertext(char* key_name,char* cipher_text);

	bool dynamic_display_cipherkey(char *key_name,char *key_content);

	void clear_input_lineEdit();

private slots:
	void new_filedialog();	//browse file
	void encrypt_program();	//start encrypt

	void query_keyname_exist();//judge the key whether be used
};

#endif // FILE_ENCRYPT_STORE_H