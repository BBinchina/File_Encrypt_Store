#ifndef SQL_INTERFACE_H
#define SQL_INTERFACE_H

#include <QObject>
#include <QString>
#include <QSqldatabase>
#include <Qt/qdebug.h>
#include <Qt/qsqlerror.h>
#include <Qt/qsqlquery.h>
#include <QtGui/QMessageBox>

class MyKey{
public:
	QString key_name;
	QString key_content;
};

class MyCipher{
public:
	QString cipher_key_name;
	QString cipher_content;
};

class MySql : public QObject{
	Q_OBJECT

private:
	QSqlDatabase* db;

public:
	MySql(QObject* parent = 0);
	virtual ~MySql();

public:
	void configure_database(QString);
	void Query_Key_List(QList<MyKey>&result,const QString db_name);
	void Query_Cipher_List(QList<MyCipher>&result,const QString db_name);

	bool Query_CipherText_Exist(const QString db_name,char *CipherText);
	bool Store_CipherText(const QString db_name,char *CipherKeyName,char *CipherText);

	bool Query_Keyname_Exist(const QString db_name,char *KeyName);
	bool Store_Key_Content(const QString db_name,char *KeyName,char *KeyContent);
};

#endif	//SQL_INTERFACE_H