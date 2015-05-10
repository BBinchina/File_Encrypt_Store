#include "file_encrypt_store.h"

/*display the cipher_key in the cipher_key_tablewidget*/
void File_Encrypt_Store::display_key_list()
{
	QList<MyKey> result;

	encrypt_key_sql.Query_Key_List(result,DATA_BASE_NAME);

	ui.cipher_key_tablewidget->setColumnCount(2);
	ui.cipher_key_tablewidget->setRowCount(result.count());

	QStringList headers;
	headers<<"encrypt key"<<"key content";
	ui.cipher_key_tablewidget->setHorizontalHeaderLabels(headers);

	int row_num = 0;
	foreach(MyKey temp,result){
		QTableWidgetItem *temp_key_name = new QTableWidgetItem(QString( temp.key_name ) );
		QTableWidgetItem *temp_key_content = new QTableWidgetItem(QString( temp.key_content) );
		ui.cipher_key_tablewidget->setItem(row_num,0,temp_key_name );
		ui.cipher_key_tablewidget->setItem(row_num,1,temp_key_content );
		row_num++;
	}
}

/*display the cipher text in the cipher_text_tablewidget*/
void File_Encrypt_Store::display_cipher_list()
{
	QList<MyCipher> result;

	encrypt_key_sql.Query_Cipher_List(result,DATA_BASE_NAME);

	ui.cipher_text_tablewidget->setColumnCount(2);
	ui.cipher_text_tablewidget->setRowCount(result.count());

	QStringList headers;
	headers<<"key name"<<"cipher text";
	ui.cipher_text_tablewidget->setHorizontalHeaderLabels(headers);

	int row_num = 0;
	foreach(MyCipher temp,result){
		QTableWidgetItem *temp_cipher_key_name = new QTableWidgetItem( temp.cipher_key_name );
		QTableWidgetItem *temp_cipher_content = new QTableWidgetItem( temp.cipher_content );

		ui.cipher_text_tablewidget->setItem(row_num,0,temp_cipher_key_name );
		ui.cipher_text_tablewidget->setItem(row_num,1,temp_cipher_content );
		row_num++;
	}
}

/*by browse file and chose the file that will be encrypted*/
void File_Encrypt_Store::new_filedialog()
{
	QString encrypted_file_path = QFileDialog::getOpenFileName(this,tr("chose file"),".",tr("Text files (*.txt);;Images (*.png *.xpm *.jpg);;XML files (*.xml)"));
	ui.file_path_lineEdit->setText(encrypted_file_path);
}

/*Dynamic Display cipher text*/
void File_Encrypt_Store::dynamic_display_ciphertext(char* key_name,char* cipher_text)
{	
	ui.cipher_text_tablewidget->setRowCount(ui.cipher_text_tablewidget->rowCount());

	QTableWidgetItem *temp_cipher_key_name = new QTableWidgetItem(QString( QLatin1String(key_name)) );
	QTableWidgetItem *temp_cipher_text_content = new QTableWidgetItem(QString( QLatin1String(cipher_text)) );

	ui.cipher_text_tablewidget->insertRow(0);
	ui.cipher_text_tablewidget->setItem(0,0,temp_cipher_key_name);
	ui.cipher_text_tablewidget->setItem(0,1,temp_cipher_text_content);
}

/*Dynamic Display cipher key*/
bool File_Encrypt_Store::dynamic_display_cipherkey(char *key_name,char *key_content)
{
	if( encrypt_key_sql.Store_Key_Content(DATA_BASE_NAME,key_name,key_content) ){
		ui.cipher_key_tablewidget->setRowCount(ui.cipher_key_tablewidget->rowCount());

		QTableWidgetItem *temp_cipher_key_name = new QTableWidgetItem(QString(QLatin1String(key_name)));
		QTableWidgetItem *temp_cipher_key_content = new QTableWidgetItem(QString(QLatin1String(key_content)));

		ui.cipher_key_tablewidget->insertRow(0);
		ui.cipher_key_tablewidget->setItem(0,0,temp_cipher_key_name);
		ui.cipher_key_tablewidget->setItem(0,1,temp_cipher_key_content);

		return true;
	}else{
	//	QMessageBox::warning(this,tr("Error"),tr("store key fault!"),QMessageBox::Cancel);
		return false;
	}
}

void File_Encrypt_Store::clear_input_lineEdit()
{
	disconnect(ui.browse_button,SIGNAL(clicked()),this,SLOT(new_filedialog()));
	ui.file_path_lineEdit->clear();
	ui.key_name_lineEdit->clear();
	connect(ui.browse_button,SIGNAL(clicked()),this,SLOT(new_filedialog()));
}