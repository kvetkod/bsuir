#include "pch.h"
#include "CppUnitTest.h"
#include"Computer.h"
#include"Desktop.h"
#include"Device.h"
#include"Keyboard.h"
#include"Laptop.h"
#include"Memory.h"
#include"Monitor.h"
#include"OperatingSystem.h"
#include"Processor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	TEST_CLASS(OperatingSystemTest) {
		TEST_METHOD(InstallTest)
		{
			OperatingSystem A;
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			stringstream input;
			input << "w" << endl;
			input << "1" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			A.Install(false);
			cin.rdbuf(oldCinBuf);
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'N');
		}
		TEST_METHOD(ShowInformationTest)
		{
			OperatingSystem A;
		
			stringstream input;
			input << "w" << endl;
			input << "1" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			A.Install(false);
			cin.rdbuf(oldCinBuf);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.ShowInformation();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'w');
		}
	};
}