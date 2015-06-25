#include <QCoreApplication>
#include <cstring>
#include <nanomsg/nn.h>
#include <nanomsg/pair.h>
#include "msgevent.h"
#include "comm.h"

Comm::Comm(QObject* receiver, QObject* parent) : QThread{parent}, m_receiver{receiver}
{
}

Comm::~Comm()
{
}

void Comm::run()
{
	int s = nn_socket(AF_SP, NN_PAIR);
	nn_bind(s, "ipc:///tmp/test.ipc");
	void* buf = NULL;
	int count;
	while((count = nn_recv(s, &buf, NN_MSG, 0)) != -1) {
		QByteArray arr{(const char*)buf, count};
		uint8_t type = arr.at(0);
		arr.remove(0, 1); // remove the type
		MsgEvent* e = new MsgEvent{type, arr};
		QCoreApplication::postEvent(m_receiver, e);
		nn_freemsg(buf);
	}
	nn_close(s);
}
