#include "Sql_Interface.h"

MySql::MySql( QObject* parent /*= 0*/)
{
}


MySql::~MySql()
{

}

void MySql::configure_database( QString db_name)
{
	db = &QSqlDatabase::addDatabase("QODBC",db_name);
	db->setHostName("127.0.0.1");
	db->setDatabaseName("DRIVER={SQL SERVER};SERVER=127.0.0.1;DATABASE=" + db_name);
	db->setUserName("sa");
	db->setPassword("123456");
}


void MySql::Query_Key_List( QList<MyKey>& result_list,const QString db_name)
{
	QSqlDatabase db_conn = QSqlDatabase::database(db_name,true);
	if( !db_conn.open() ){
		qDebug()<<db_conn.lastError().text();
	}

	QSqlQuery query = QSqlQuery::QSqlQuery(db_conn);
	query.prepare("SELECT * FROM encrypt_key ORDER BY cipher_key_name ASC");
	if(query.exec()){
		while(query.next()){
			MyKey temp;
			temp.key_name = query.value(0).toString();
			temp.key_content =query.value(1).toString();
			result_list.append(temp);
		}
		db_conn.close();
		return ;
	}else{
		db_conn.close();
		qDebug()<<QString("Failed :")<<query.lastError().text();
		return ;
	}
}

void MySql::Query_Cipher_List( QList<MyCipher>&result_list,const QString db_name )
{
	QSqlDatabase db_conn = QSqlDatabase::database(db_name,true);
	if( !db_conn.open() ){
		qDebug()<<db_conn.lastError().text();
	}

	QSqlQuery query = QSqlQuery::QSqlQuery(db_conn);
	query.prepare("SELECT * FROM encrypt_cipher ORDER BY cipher_key_name ASC");
	if(query.exec()){
		while(query.next()){
			MyCipher temp;
			temp.cipher_key_name = query.value(0).toString();
			temp.cipher_content = query.value(1).toString();
			result_list.append(temp);
		}
		db_conn.close();
		return ;
	}else{
		db_conn.close();
		qDebug()<<QString("Failed :")<<query.lastError().text();
		return ;
	}
}

bool MySql::Query_CipherText_Exist(const QString db_name,char * Target)
{
	QSqlDatabase db_conn = QSqlDatabase::database(db_name,true);
	if( !db_conn.open() ){
		qDebug()<<db_conn.lastError().text();
	}

	QSqlQuery query = QSqlQuery::QSqlQuery(db_conn);
	query.prepare("SELECT * FROM encrypt_cipher WHERE cipher_content = ? ");
	query.bindValue(0,Target);

	if(query.exec()){
		if(query.next())
		{
			db_conn.close();
			return true;
		}else{
			db_conn.close();
			return false;
		}
	}else{
		db_conn.close();
		qDebug()<<QString("Failed :")<<query.lastError().text();
		QMessageBox::information(NULL,tr("Error"),tr("Database Connect fault!"),QMessageBox::Cancel);
		return false;
	}
}

bool MySql::Store_CipherText(const QString db_name,char *CipherKeyName,char *CipherText)
{
	QSqlDatabase db_conn = QSqlDatabase::database(db_name,true);
	if( !db_conn.open() ){
		qDebug()<<db_conn.lastError().text();
	}

	QSqlQuery query = QSqlQuery::QSqlQuery(db_conn);
	query.prepare("INSERT INTO encrypt_cipher (cipher_key_name,cipher_content)VALUES(?,?)");
	query.bindValue(0,CipherKeyName);
	query.bindValue(1,CipherText);
	if(query.exec()){
		db_conn.close();
		return true;
	}else{
		db_conn.close();
		qDebug()<<QString("Failed :")<<query.lastError().text();
		return false;
	}
}

bool MySql::Query_Keyname_Exist( const QString db_name,char *keyname )
{
	QSqlDatabase db_conn = QSqlDatabase::database(db_name,true);
	if( !db_conn.open() ){
		qDebug()<<db_conn.lastError().text();
	}

	QSqlQuery query = QSqlQuery::QSqlQuery(db_conn);
	query.prepare("SELECT cipher_key_name FROM encrypt_key WHERE cipher_key_name = ?");
	query.bindValue(0,keyname);
	if(query.exec()){
		if(query.next()){
			db_conn.close();
			return true;
		}else{
			db_conn.close();
			return false;
		}
	}else{
		db_conn.close();
		qDebug()<<QString("Failed :")<<query.lastError().text();
		return false;
	}
}

bool MySql::Store_Key_Content( const QString db_name,char *KeyName,char *KeyContent )
{
	QSqlDatabase db_conn = QSqlDatabase::database(db_name,true);
	if( !db_conn.open() ){
		qDebug()<<db_conn.lastError().text();
	}

	QSqlQuery query = QSqlQuery::QSqlQuery(db_conn);

	query.prepare("INSERT INTO encrypt_key (cipher_key_name,cipher_key_content)VALUES(?,?)");
	query.bindValue(0,KeyName);
	query.bindValue(1,KeyContent);
	if(query.exec()){
		db_conn.close();
		return true;
	}else{
		db_conn.close();
		qDebug()<<QString("Failed :")<<query.lastError().text();
		return false;
	}
}
