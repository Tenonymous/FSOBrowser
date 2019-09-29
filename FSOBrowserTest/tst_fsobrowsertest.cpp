#include <QtTest/QTest>

#include "../stringprocessor.h"
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
    auto process = StringProcessor("www .blabla.pl");
    auto process2 = StringProcessor("blabla.pl");
    auto process3 = StringProcessor("blabla faf .pl");
    auto process4 = StringProcessor("blablabla.pl ");
    QVERIFY(process.areSpaces() == true);
    QVERIFY(process2.areSpaces() == false);
    QVERIFY(process3.areSpaces() == true);
    QVERIFY(process4.areSpaces() == true);
}

void FSOBrowserTest::removeSpacesTest()
{
    auto process = StringProcessor("www .blabla.pl");
    auto process2 = StringProcessor("blabla faf .pl");
    auto process3 = StringProcessor("blablabla.pl ");
    QVERIFY(process.removeSpaces() == "www.blabla.pl");
    QVERIFY(process2.removeSpaces() == "blablafaf.pl");
    QVERIFY(process3.removeSpaces() == "blablabla.pl");
}

void FSOBrowserTest::checkHTTPprefixTest()
{
    auto process = StringProcessor("www .blabla.pl");
    auto process2 = StringProcessor("http://www.blabla.pl");
    auto process3 = StringProcessor("http:/www.pl");
    auto process4 = StringProcessor("http:www.pl");
    auto process5 = StringProcessor("httpwww.pl");
    auto process6 = StringProcessor("www.pl/http://");
    auto process7 = StringProcessor("whttp://www.pl");
    QVERIFY(process.HTTPprefixExist() == false);
    QVERIFY(process2.HTTPprefixExist() == true);
    QVERIFY(process3.HTTPprefixExist() == false);
    QVERIFY(process4.HTTPprefixExist() == false);
    QVERIFY(process5.HTTPprefixExist() == false);
    QVERIFY(process6.HTTPprefixExist() == false);
    QVERIFY(process7.HTTPprefixExist() == false);
}

void FSOBrowserTest::getAddressWithHTTPprefixTest()
{
    auto process = StringProcessor("www.blabla.pl");
    auto process2 = StringProcessor("http://www.blabla.pl");
    auto process3 = StringProcessor("www.pl/http://");
    auto process4 = StringProcessor("whttp://www.pl");

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
