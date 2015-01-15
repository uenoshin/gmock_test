#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "target.h"

using ::testing::Return;
using ::testing::_;
//using ::testing::Mock;

class mock : public Lapper {
	public:
		virtual ~mock(){}
		MOCK_METHOD1(exAPI,int(int n));

		static mock* getMock(){
			static mock mo;
			return &mo;
		}

};

//mock mo;

int get_exAPI(int a){
	mock *mo=mock::getMock();
	return mo->exAPI(a);
}

TEST(targettest, case1){
	mock *mo=mock::getMock();
	Lapper la;
	exAPI= get_exAPI;

//	::testing::GMOCK_FLAG(catch_leaked_mocks) = true;
//	::testing::Mock::AllowLeak(&mo);

	EXPECT_CALL(*mo, exAPI(_))
		.WillRepeatedly(Return(1));
	
	EXPECT_TRUE(la.Func(0));

//	Mock::VerifyAndClear(mo);

}
