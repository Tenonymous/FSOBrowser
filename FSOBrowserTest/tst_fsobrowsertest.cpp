#include <QtTest/QTest>

#include "../addressprocessor.h"
#include ".//engine.h"

class FSOBrowserTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void removeSpacesTest();
    void getAddressWithHTTPprefixTest();
    void processAddressTest();

};


void FSOBrowserTest::removeSpacesTest()
{
    auto process = AddressProcessor("www .blabla.pl");
    auto process2 = AddressProcessor("blabla faf .pl");
    auto process3 = AddressProcessor("blablabla.pl ");
    QVERIFY(process.removeSpaces().address() == "www.blabla.pl");
    QVERIFY(process2.removeSpaces().address() == "blablafaf.pl");
    QVERIFY(process3.removeSpaces().address() == "blablabla.pl");
}

void FSOBrowserTest::getAddressWithHTTPprefixTest()
{
    auto process = AddressProcessor("www.blabla.pl");
    auto process2 = AddressProcessor("http://www.blabla.pl");
    auto process3 = AddressProcessor("www.pl/http://");
    auto process4 = AddressProcessor("whttp://www.pl");
    auto process5 = AddressProcessor("com.pl");

    QVERIFY(process.getAddressWithHTTPprefix() == "http://www.blabla.pl");
    QVERIFY(process2.getAddressWithHTTPprefix() == "http://www.blabla.pl");
    QVERIFY(process3.getAddressWithHTTPprefix() == "http://www.pl/http://");
    QVERIFY(process4.getAddressWithHTTPprefix() == "http://whttp://www.pl");
    QVERIFY(process5.getAddressWithHTTPprefix() == "http://com.pl");
}

void FSOBrowserTest::processAddressTest()
{
    auto engine = Engine();
    QVERIFY(engine.processAddress("www . blabla.pl") == "http://www.blabla.pl");
    QVERIFY(engine.processAddress("www . blabla.pl ") == "http://www.blabla.pl");
    QVERIFY(engine.processAddress(" blabla.pl") == "http://blabla.pl");
}


QTEST_APPLESS_MAIN(FSOBrowserTest)

#include "tst_fsobrowsertest.moc"
