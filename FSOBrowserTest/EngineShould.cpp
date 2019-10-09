#include <QtTest/QTest>

#include ".//engine.h"

class EngineShould : public QObject
{
    Q_OBJECT

public:

private slots:
    void shouldReturnFullAddress();
};


void EngineShould::shouldReturnFullAddress()
{
    auto engine = Engine();
    QVERIFY(engine.processAddress("www . blabla.pl") == "http://www.blabla.pl");
    QVERIFY(engine.processAddress("www . blabla.pl ") == "http://www.blabla.pl");
    QVERIFY(engine.processAddress(" blabla.pl") == "http://blabla.pl");
}

//QTEST_APPLESS_MAIN(EngineShould)

//#include "EngineShould.moc"
