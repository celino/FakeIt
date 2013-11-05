#include "stdafx.h"
#include "CppUnitTest.h"
#include "Mock.h"
namespace mock4cpp_tests
{

	TEST_CLASS(VerificationTests)
	{
	public:

		struct SomeInterface
		{
			virtual int func(int) = 0;
			virtual void proc(int) = 0;
		};

		class A {
			int a;
		public:
			~A(){
				a++;
			}
		};

		TEST_METHOD(VerifyZeroInvoaction)
		{
//			Mock<SomeInterface> mock;
//			mock.Stub(&SomeInterface::func);
//			mock.Stub(&SomeInterface::proc);

			
//			A();
//			SomeInterface &i = mock.get();
// 			Verify.Never(mock().func(1));
// 			Verify.Never(mock().func(2));
// 			Verify.Never(&SomeInterface::func);
// 
// 			Verify.Never(mock().proc(1));
// 			Verify.Never(mock().proc(2));
// 			Verify.Never(&SomeInterface::proc);
		}

		TEST_METHOD(VerifyAtLeastOnceIsTheDefaultBehavior)
		{
			Mock<SomeInterface> mock;
			mock.Stub(&SomeInterface::func);
			mock.Stub(&SomeInterface::proc);

			SomeInterface &i = mock.get();

			i.func(1);
			i.func(2);
			
  			Verify(mock[&SomeInterface::func]).Twice();
// 			Verify(mock[&SomeInterface::func].Using(1)).Once();
//  			Verify(mock[&SomeInterface::func].Using(2)).Once();
//  			Verify(mock[&SomeInterface::func].Using(3)).Never();
		}
	};
}

