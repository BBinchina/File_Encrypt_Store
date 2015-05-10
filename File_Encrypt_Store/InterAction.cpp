#include "file_encrypt_store.h"
#include <openssl/sha.h>

#include "Encrypt_Func.h"
#include "Sha1_Func.h"

/*start encrypt*/
void File_Encrypt_Store::encrypt_program()
{
	QByteArray filename  = ui.file_path_lineEdit->text().toLatin1();
	const char* current_encrypted_file = NULL;
	current_encrypted_file = filename.data();

	QByteArray keyname = ui.key_name_lineEdit->text().toLatin1();
	char* encrypt_key_name = NULL;
	encrypt_key_name = keyname.data();

	qDebug()<<current_encrypted_file;
	qDebug()<<encrypt_key_name;

	if( *current_encrypted_file != NULL && *encrypt_key_name != NULL){	//start encrypt

		char store_key[24];

		if( Encrypt_File(current_encrypted_file,encrypt_key_name,store_key) == 1 ){	//The cipherkey store in the file
			
			store_key[24] = '\0';
			char * key_content = NULL;
			key_content = store_key;
			qDebug()<<QString(QLatin1String(key_content));

 			char* Target = (char *)malloc(SHA_DIGEST_LENGTH*2 + 1);	//remeber free the memory

 			shaFile(current_encrypted_file,Target);	//The ciphertext is Target

  			if( encrypt_key_sql.Query_CipherText_Exist(DATA_BASE_NAME,Target) ){

  				QMessageBox::information(this,tr("Info"),tr("The ciphertext already exists!"),QMessageBox::Ok);
				clear_input_lineEdit();
  			}else{
 				if( encrypt_key_sql.Store_CipherText(DATA_BASE_NAME,encrypt_key_name,Target) ){
 
 					dynamic_display_ciphertext(encrypt_key_name,Target);		//insert the new item into cipher text table
 
 					dynamic_display_cipherkey(encrypt_key_name,key_content);		//insert the new item into cipher key table
 
 					QMessageBox::information(this,tr("Info"),tr("sort successfully"),QMessageBox::Ok);

					clear_input_lineEdit();
					
 				}else{
 					QMessageBox::information(this,tr("Info"),tr("sort fault"),QMessageBox::Cancel);

					clear_input_lineEdit();
 				}
 			}
			free(Target);//free the memory of Target
		}
	}else if( *current_encrypted_file != NULL ){
		QMessageBox::information(this,tr("Error"),tr("Please enter the key name!"),QMessageBox::Ok);
	}else if( *encrypt_key_name != NULL ){
		QMessageBox::information(this,tr("Error"),tr("Please select the desired file encryption!"),QMessageBox::Ok);
	}else{
		QMessageBox::information(this,tr("Error"),tr("Please select the desired file encryption and key!"),QMessageBox::Ok);
	}
	current_encrypted_file = NULL;
	encrypt_key_name = NULL;
}

void File_Encrypt_Store::query_keyname_exist()
{
	QString key_name = ui.key_name_lineEdit->text();
	QByteArray keyname = key_name.toLatin1();
	char* encrypt_key_name = NULL;
	encrypt_key_name = keyname.data();
	
	if(encrypt_key_sql.Query_Keyname_Exist(DATA_BASE_NAME,encrypt_key_name)){
		QMessageBox::information(NULL,tr("Error"),tr("key name is existed!\nPlease input again"),QMessageBox::Ok);
	}
}