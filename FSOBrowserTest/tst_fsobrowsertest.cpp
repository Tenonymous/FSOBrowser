#include <QtTest/QTest>

#include "../addressprocessor.h"
#include ".//engine.h"
#include ".//address.h"

class FSOBrowserTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void removeSpacesTest();
    void getAddressWithHTTPprefixTest();
    void processAddressTest();
    void getPrefixTest();
    void getCleanAddresTest();

};


void FSOBrowserTest::removeSpacesTest()
{
    auto process = AddressProcessor("www .blabla.pl");
    auto process2 = AddressProcessor("blabla faf .pl");
    auto process3 = AddressProcessor("blablabla.pl ");
    QVERIFY(process.removeSpaces().address() == Address("www.blabla.pl"));
    QVERIFY(process2.removeSpaces().address() == Address("blablafaf.pl"));
    QVERIFY(process3.removeSpaces().address() == Address("blablabla.pl"));
}

void FSOBrowserTest::getAddressWithHTTPprefixTest()
{
    auto process = AddressProcessor("www.blabla.pl");
    auto process2 = AddressProcessor("http://www.blabla.pl");
    auto process3 = AddressProcessor("www.pl/http://");
    auto process4 = AddressProcessor("whttp://www.pl");
    auto process5 = AddressProcessor("com.pl");

    QVERIFY(process.getAddressWithHTTPprefix() == Address("http://www.blabla.pl"));
    QVERIFY(process2.getAddressWithHTTPprefix() == Address("http://www.blabla.pl"));
    QVERIFY(process3.getAddressWithHTTPprefix() == Address("http://www.pl/http://"));
    QVERIFY(process4.getAddressWithHTTPprefix() == Address("http://whttp://www.pl"));
    QVERIFY(process5.getAddressWithHTTPprefix() == Address("http://com.pl"));
}

void FSOBrowserTest::processAddressTest()
{
    auto engine = Engine();
    QVERIFY(engine.processAddress("www . blabla.pl") == "http://www.blabla.pl");
    QVERIFY(engine.processAddress("www . blabla.pl ") == "http://www.blabla.pl");
    QVERIFY(engine.processAddress(" blabla.pl") == "http://blabla.pl");
}

void FSOBrowserTest::getPrefixTest()
{
    auto addr = Address("http://www.pl");
    QVERIFY(addr.getPrefix() == "http://www");
    addr = Address("http://blabla.pl");
    QVERIFY(addr.getPrefix() == "http://");
    addr = Address("htt.www.pl");
    QVERIFY(addr.getPrefix() == "");
    addr = Address("compl");
    QVERIFY(addr.getPrefix() == "");

    addr = Address("https://www.pl");
    QVERIFY(addr.getPrefix() == "https://www");
    addr = Address("https://blabla.pl");
    QVERIFY(addr.getPrefix() == "https://");
    addr = Address("htt.www.pl");
    QVERIFY(addr.getPrefix() == "");
    addr = Address("compl");
    QVERIFY(addr.getPrefix() == "");

}

void FSOBrowserTest::getCleanAddresTest()
{
    auto addr = Address("http://www.onet.pl");
    QVERIFY(addr.getAddressWithoutPrefix() == "onet.pl");
    addr = Address("http://onet.pl");
    QVERIFY(addr.getAddressWithoutPrefix() == "onet.pl");
    addr = Address("https://onet.pl");
    QVERIFY(addr.getAddressWithoutPrefix() == "onet.pl");
    addr = Address("https://www.onet.pl");
    QVERIFY(addr.getAddressWithoutPrefix() == "onet.pl");

    addr = Address("https://blabla.com");
    QVERIFY(addr.getAddressWithoutPrefix() == "blabla.com");
    addr = Address("https://www.onet.net");
    QVERIFY(addr.getAddressWithoutPrefix() == "onet.net");
}


QTEST_APPLESS_MAIN(FSOBrowserTest)

#include "tst_fsobrowsertest.moc"
