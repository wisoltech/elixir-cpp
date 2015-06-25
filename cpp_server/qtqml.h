#ifndef QTQML_H
#define QTQML_H

#include <QObject>

class QtQml : public QObject
{
	Q_OBJECT

public:
	explicit QtQml(QObject* parent = 0);
	bool event(QEvent* e);

signals:
	void addText(QString text);

public slots:
};

#endif // QTQML_H
