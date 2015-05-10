#include "file_encrypt_store.h"

File_Encrypt_Store::File_Encrypt_Store(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	MySql encrypt_key_sql(this);
	encrypt_key_sql.configure_database(DATA_BASE_NAME);
	ui.key_name_lineEdit->isModified();
}

File_Encrypt_Store::~File_Encrypt_Store()
{

}