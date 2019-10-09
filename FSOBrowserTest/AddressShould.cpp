#include <QtTest/QTest>

#include ".//address.h"

class AddressShould : public QObject
{
    Q_OBJECT

public:

private slots:
    void sholudReturnPrefix();
    void shouldReturnAddressWithoutPrefix();
    void shouldReturnHttpsMode();
};

void AddressShould::sholudReturnPrefix()
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

void AddressShould::shouldReturnAddressWithoutPrefix()
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

void AddressShould::shouldReturnHttpsMode()
{
    auto addr = Address("http://www.onet.pl");
    QVERIFY(!addr.https_mode());
    addr = "http://onet.pl";
    QVERIFY(!addr.https_mode());
    addr = "https://www.onet.pl";
    QVERIFY(addr.https_mode());
    addr = "https://onet.pl";
    QVERIFY(addr.https_mode());
    addr = Address("htt.www.pl");
    QVERIFY(!addr.https_mode());
    addr = "whttps://www.pl";
    QVERIFY(!addr.https_mode());
}

//QTEST_APPLESS_MAIN(AddressShould)

//#include "AddressShould.moc"
