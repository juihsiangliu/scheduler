#include "gtest/gtest.h"

#include "resource.h"


TEST(ResourceMgr, testName)
{
    ResourceMgr mgr;
    mgr.add("p1, 0, 1000");
    mgr.add("p2, 5, 500");
    mgr.add("p2, 501, 1000");

    Resource* p1 = mgr.getResourceByName("p1");
    Resource* p2 = mgr.getResourceByName("p2");

    ASSERT_STREQ("p1", p1->getName());
    ASSERT_STREQ("p2", p2->getName());
    
    Resource* no = mgr.getResourceByName("no");
    ASSERT_EQ(NULL, no);
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
