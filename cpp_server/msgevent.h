#ifndef MSGEVENT_H
#define MSGEVENT_H

#include <QEvent>

class MsgEvent : public QEvent
{
public:
	MsgEvent(uint8_t msg_type, QByteArray msg) : QEvent(QEvent::User), m_msg_type(msg_type), m_msg(msg)
	{
	}
	uint8_t msg_type() const
	{
		return m_msg_type;
	}
	QByteArray msg() const
	{
		return m_msg;
	}

private:
	uint8_t m_msg_type;
	QByteArray m_msg;
};

#endif // MSGEVENT_H
