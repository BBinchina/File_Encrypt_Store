#include "file_encrypt_store.h"
#include <QtGui/QApplication>
#include <QStringList>
#include <openssl/sha.h>

int main(int argc, char *argv[])
{
// 	QStringList drivers = QSqlDatabase::drivers();
// 	foreach( QString d,drivers ){
// 		qDebug() << d;
// 	}

	QApplication a(argc, argv);
	File_Encrypt_Store w;
	w.Init_Signal_Slots();
	w.display_key_list();
	w.display_cipher_list();
	w.show();
	return a.exec();
}
