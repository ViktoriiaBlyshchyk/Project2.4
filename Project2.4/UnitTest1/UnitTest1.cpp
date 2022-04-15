#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Study\ООП\Project2.4\Project2.4\Vector.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool a;
			Vector b(2);
			Vector c(2);
			a = (b == c);
			Assert::IsTrue(a);
		}
	};
}
