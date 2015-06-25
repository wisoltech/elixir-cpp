#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "comm.h"
#include "qtqml.h"

int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	QtQml qq;

	QQmlContext* ctx = engine.rootContext();
	ctx->setContextProperty("qtqml", &qq);

	Comm comm(&qq);
	comm.start();

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	int ret = app.exec();

	comm.quit();
	comm.wait(100);

	return ret;
}
