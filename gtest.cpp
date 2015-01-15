#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "target.h"

using ::testing::Return;
using ::testing::_;
using ::testing::Test;

class mock {
	public:
		virtual ~mock(){}
		MOCK_METHOD1(exAPI,int(int n));

		static mock* getMock(){
			static mock mo;
			return &mo;
		}

};

int get_exAPI(int a){
	mock *mo=mock::getMock();
	return mo->exAPI(a);
}

class targettest : public ::testing::Test
{
	int (*saved)(int);

	virtual void SetUp()
	{
		saved = exAPI;
		exAPI = get_exAPI;
	}

	virtual void TearDown()
	{
		exAPI = saved;
	}
};


TEST_F(targettest, case1){
	mock *mo=mock::getMock();
	Target ta;

//	::testing::GMOCK_FLAG(catch_leaked_mocks) = true;
//	::testing::Mock::AllowLeak(&mo);

	EXPECT_CALL(*mo, exAPI(_))
		.WillRepeatedly(Return(1));
	
	EXPECT_TRUE(ta.Func(0));

//	Mock::VerifyAndClear(mo);

}

TEST_F(targettest, case2){
    mock *mo=mock::getMock();
    Target ta;

//    EXPECT_CALL(*mo, exAPI(_))
//        .WillRepeatedly(Return(0));

//  前回のActionが残っているので1がreturnされる

    EXPECT_TRUE(ta.Func(0));
}
