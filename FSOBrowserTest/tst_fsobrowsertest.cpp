#include <QtTest/QTest>

#include "../stringprocessor.h"

class FSOBrowserTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void areSpacesTest();
    void removeSpacesTest();

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


QTEST_APPLESS_MAIN(FSOBrowserTest)

#include "tst_fsobrowsertest.moc"
