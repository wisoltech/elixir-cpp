#include <sstream>
#include <QEvent>
#include <msgpack.hpp>
#include "msgevent.h"
#include "qtqml.h"

QtQml::QtQml(QObject* parent) : QObject(parent)
{
}

bool QtQml::event(QEvent* e)
{
	if(e->type() == QEvent::User) {
		MsgEvent* ev = static_cast<MsgEvent*>(e);
		msgpack::unpacked result;
		msgpack::unpack(&result, ev->msg().data(), ev->msg().size());
		msgpack::object deserialized = result.get();
		std::stringstream ss;
		ss << deserialized;
		emit addText(QString::fromStdString(ss.str()));
		return true;
	}
	return false;
}
