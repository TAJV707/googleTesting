#include "gtest/gtest.h"
#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;
  Date last_day;
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              
  Date ind_day(1776, 7, 4);            
  Date best_holiday(2018, 10, 31);     

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);            
  Date ind_day(1776, 7, 4);            
  Date best_holiday(2018, 10, 31);     

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestWithNewLine){
  Date y2k(1999, 12, 31);             
  Date ind_day(1776, 7, 4);            
  Date best_holiday(2018, 10, 31);     

  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); 
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestWithoutNewLine){
  Date y2k(1999, 12, 31);              
  Date ind_day(1776, 7, 4);            
  Date best_holiday(2018, 10, 31);     

  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, GetDateTests){
  Date b_day(1995, 10, 11);
  Date y2k(1999, 12, 31);
  Date ind_day(1776, 7, 4);

  EXPECT_EQ("1995-10-11", b_day.GetDate());
  EXPECT_EQ("1999-12-31", y2k.GetDate());
  EXPECT_EQ("1776-07-04", ind_day.GetDate());
  EXPECT_EQ("10-11-1995", b_day.GetUsDate());
  EXPECT_EQ("12-31-1999", y2k.GetUsDate());
  EXPECT_EQ("07-04-1776", ind_day.GetUsDate());
}

TEST_F(DateTest, EpochTesting){
  
  Date test_1(0);
  Date test_2(-1);
  Date test_3(86401);
  Date test_4(31536000);
  Date test_5(-31536000);

  std::string expected_out_1 = "1970-01-01";
  std::string expected_out_2 = "1969-12-31";
  std::string expected_out_3 = "1970-01-02";
  std::string expected_out_4 = "1971-01-01";
  std::string expected_out_5 = "1969-01-01";

  EXPECT_EQ(expected_out_1, test_1.GetDate());
  EXPECT_EQ(expected_out_2, test_2.GetDate());
  EXPECT_EQ(expected_out_3, test_3.GetDate());
  EXPECT_EQ(expected_out_4, test_4.GetDate());
  EXPECT_EQ(expected_out_5, test_5.GetDate());

}

TEST_F(DateTest, AddTesting){
  Date b_day(1995, 10, 11);
  Date y2k(1999, 12, 31);
  Date rand_day(1776, 7, 9);

  Date date_1 = b_day + 365;
  EXPECT_EQ("1996-10-10", date_1.GetDate());

  Date date_2 = b_day + 1;
  EXPECT_EQ("1995-10-12", date_2.GetDate());

  Date date_3 = y2k + 1;
  EXPECT_EQ("2000-01-01", date_3.GetDate());

  Date date_4 = rand_day + 2;
  EXPECT_EQ("1776-07-11", date_4.GetDate());

  Date date_5 = b_day + (-1);
  EXPECT_EQ("1995-10-10", date_5.GetDate());

  Date date_6 = b_day + 0;
  EXPECT_EQ("1995-10-11", date_6.GetDate());


}

TEST_F(DateTest, SubTesting){
  Date b_day(1995, 10, 11);
  Date aftery2k(2000, 01, 01);
  Date rand_day(1776, 7, 9);

  std::string expected_out_1 = "1995-10-10";
  std::string expected_out_2 = "1999-12-31";
  std::string expected_out_3 = "1776-07-04";
  std::string expected_out_4 = "1994-10-11";
  std::string expected_out_5 = "1776-07-09";

  Date date_1 = b_day - 1;
  EXPECT_EQ(expected_out_1, date_1.GetDate());

  Date date_2 = aftery2k - 1;
  EXPECT_EQ(expected_out_2, date_2.GetDate());

  Date date_3 = rand_day - 5;
  EXPECT_EQ(expected_out_3, date_3.GetDate());

  Date date_4 = b_day - 365;
  EXPECT_EQ(expected_out_4, date_4.GetDate());

  Date date_5 = rand_day - 0;
  EXPECT_EQ(expected_out_5, date_5.GetDate());
}


TEST_F(DateTest, DaysBetweenTests) {

  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";

  Date y2k(1999, 12, 31);
  Date dec_ult(2000, 12, 31);
  Date addition(0001, 01, 01);
  Date jan1st(2000, 01, 01);
  Date jan2nd(2000, 01, 02);
  Date jan_prox(2001, 01, 01);
  Date feb1st(2000, 02, 01);
  Date june5th(2000, 06, 05);
  Date june3rd(2003, 06, 05);
  

  EXPECT_EQ(jan1st.DaysBetween(jan1st), 0);
  EXPECT_EQ(jan1st.DaysBetween(jan2nd), 1);
  EXPECT_EQ(jan1st.DaysBetween(feb1st), 31);
  EXPECT_EQ(jan1st.DaysBetween(y2k), 1);
  EXPECT_EQ(jan1st.DaysBetween(june5th), 156);
  EXPECT_EQ(jan1st.DaysBetween(dec_ult), 365);
  EXPECT_EQ(jan_prox.DaysBetween(jan1st), 366);
  EXPECT_EQ(june5th.DaysBetween(june3rd), 1095);
  EXPECT_EQ(addition.DaysBetween(jan1st), 730119);
}

TEST_F(DateTest, VoidConstructorTest){
  time_t t = time(0);
  tm* today = localtime(&t);

  int year = today->tm_year + 1900;
  int month = today->tm_mon + 1;
  int day = today->tm_mday;

  Date expected_date(year, month, day);
  Date date_today;

  EXPECT_EQ(date_today.GetDate(), expected_date.GetDate());
}

