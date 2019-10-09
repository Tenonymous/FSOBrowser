#include <QtTest/QTest>

#include "../addressprocessor.h"

class AddressProcessorShould : public QObject
{
    Q_OBJECT

public:

private slots:
    void sholudRemoveSpaces();
    void shouldReturnAddressWithPrefix();

};


void AddressProcessorShould::sholudRemoveSpaces()
{
    auto process = AddressProcessor("www .blabla.pl");
    auto process2 = AddressProcessor("blabla faf .pl");
    auto process3 = AddressProcessor("blablabla.pl ");
    QVERIFY(process.removeSpaces().address() == "www.blabla.pl");
    QVERIFY(process2.removeSpaces().address() == "blablafaf.pl");
    QVERIFY(process3.removeSpaces().address() == "blablabla.pl");
}

void AddressProcessorShould::shouldReturnAddressWithPrefix()
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



QTEST_MAIN(AddressProcessorShould)

#include "AddressProcessorShould.moc"
//#include "AddressShould.moc"
//#include "EngineShould.moc"
