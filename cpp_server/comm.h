#ifndef COMM_H
#define COMM_H

#include <QThread>

class Comm : public QThread
{
	Q_OBJECT
	void run() Q_DECL_OVERRIDE;

public:
	Comm(QObject* receiver, QObject* parent = NULL);
	~Comm();

private:
	QObject* m_receiver;
};

#endif // COMM_H
