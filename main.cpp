#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAndroidJniObject>
#include <QDebug>

void schedule(int time, int id)

{
    qDebug() << id;
    QAndroidJniObject::callStaticMethod<void>
                            ("org/qtproject/example/QtAndroidNotifications" // class name
                            , "scheduleNotification" // method name
                            , "(I)V" // signature
                            ,time);
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    schedule(5,1);
    schedule(10,2);







    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
