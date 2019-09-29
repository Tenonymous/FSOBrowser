#include <QtTest/QTest>

#include "../addressprocessor.h"
#include ".//engine.h"

class FSOBrowserTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void areSpacesTest();
    void removeSpacesTest();
    void checkHTTPprefixTest();
    void getAddressWithHTTPprefixTest();
    void processAddressTest();

};


void FSOBrowserTest::areSpacesTest()
{
    auto process = AddressProcessor("www .blabla.pl");
    auto process2 = AddressProcessor("blabla.pl");
    auto process3 = AddressProcessor("blabla faf .pl");
    auto process4 = AddressProcessor("blablabla.pl ");
    QVERIFY(process.areSpaces() == true);
    QVERIFY(process2.areSpaces() == false);
    QVERIFY(process3.areSpaces() == true);
    QVERIFY(process4.areSpaces() == true);
}

void FSOBrowserTest::removeSpacesTest()
{
    auto process = AddressProcessor("www .blabla.pl");
    auto process2 = AddressProcessor("blabla faf .pl");
    auto process3 = AddressProcessor("blablabla.pl ");
    QVERIFY(process.removeSpaces() == "www.blabla.pl");
    QVERIFY(process2.removeSpaces() == "blablafaf.pl");
    QVERIFY(process3.removeSpaces() == "blablabla.pl");
}

void FSOBrowserTest::checkHTTPprefixTest()
{
    auto process = AddressProcessor("www .blabla.pl");
    auto process2 = AddressProcessor("http://www.blabla.pl");
    auto process3 = AddressProcessor("http:/www.pl");
    auto process4 = AddressProcessor("http:www.pl");
    auto process5 = AddressProcessor("httpwww.pl");
    auto process6 = AddressProcessor("www.pl/http://");
    auto process7 = AddressProcessor("whttp://www.pl");
    QVERIFY(process.isHTTPprefix() == false);
    QVERIFY(process2.isHTTPprefix() == true);
    QVERIFY(process3.isHTTPprefix() == false);
    QVERIFY(process4.isHTTPprefix() == false);
    QVERIFY(process5.isHTTPprefix() == false);
    QVERIFY(process6.isHTTPprefix() == false);
    QVERIFY(process7.isHTTPprefix() == false);
}

void FSOBrowserTest::getAddressWithHTTPprefixTest()
{
    auto process = AddressProcessor("www.blabla.pl");
    auto process2 = AddressProcessor("http://www.blabla.pl");
    auto process3 = AddressProcessor("www.pl/http://");
    auto process4 = AddressProcessor("whttp://www.pl");

    QVERIFY(process.getAddressWithHTTPprefix() == "http://www.blabla.pl");
    QVERIFY(process2.getAddressWithHTTPprefix() == "http://www.blabla.pl");
    QVERIFY(process3.getAddressWithHTTPprefix() == "http://www.pl/http://");
    QVERIFY(process4.getAddressWithHTTPprefix() == "http://whttp://www.pl");
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
