#include "gtest/gtest.h"
#include "queue.h"

class QueueTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
    queue_1st = q.peek();
  }
  void TearDown() {
    // code here will execute just after the test ends
  }
 protected:

};

TEST_F(QueueTest, Empty) {

  EXPECT_EQ(queue_1st.empty());

}

