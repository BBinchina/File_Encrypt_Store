#include "file_encrypt_store.h"

void File_Encrypt_Store::Init_Signal_Slots()
{
	connect(ui.browse_button,SIGNAL(clicked()),this,SLOT(new_filedialog()));	//chose file

	connect(ui.encrypt_button,SIGNAL(clicked()),this,SLOT(encrypt_program()));

	connect(ui.key_name_lineEdit,SIGNAL(editingFinished()),this,SLOT(query_keyname_exist()));
}