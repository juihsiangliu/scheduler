#include "gtest/gtest.h"

#include "resource.h"

TEST(Resource, isAvailable)
{
    Resource r1("p2, 501, 1000");

    ASSERT_TRUE(r1.isAvailable(505, 600));
    ASSERT_FALSE(r1.isAvailable(505, 1001));

}


TEST(Resource, addInterval)
{
    Resource r1("p2, 501, 1000");
    r1.addInterval(400, 505);

    ASSERT_TRUE(r1.isAvailable(450, 550));
}


TEST(Resource, addInterval2)
{
    Resource r1("p2, 501, 1000");
    r1.addInterval(600, 2000);

    ASSERT_TRUE(r1.isAvailable(550, 1550));
}


TEST(Resource, addInterval3)
{
    Resource r1("p2, 501, 1000");
    r1.addInterval(400, 2000);

    ASSERT_TRUE(r1.isAvailable(450, 550));
}

TEST(Resource, addInterval4)
{
    Resource r1("p2, 501, 1000");
    r1.addInterval(550, 600);

    ASSERT_TRUE(r1.isAvailable(550, 800));
}


TEST(ResourceMgr, testName)
{
    ResourceMgr mgr;
    mgr.add("p1, 0, 1000");

    Resource* p1 = mgr.getResourceByName("p1");

    ASSERT_STREQ("p1", p1->getName());
    
    Resource* no = mgr.getResourceByName("no");
    ASSERT_EQ(NULL, no);
}




TEST(ResourceMgr, testInterval)
{
    ResourceMgr mgr;
    mgr.add("p2, 5, 500");
    mgr.add("p2, 501, 1000");
    
    Resource* p2 = mgr.getResourceByName("p2");

    ASSERT_TRUE(p2->isAvailable(20, 30));
    ASSERT_TRUE(p2->isAvailable(505, 600));
    ASSERT_FALSE(p2->isAvailable(505, 1001));
}


TEST(ResourceMgr, testInterval2)
{
    ResourceMgr mgr;
    mgr.add("p2, 5, 500");
    mgr.add("p2, 500, 1000");
    
    Resource* p2 = mgr.getResourceByName("p2");

    ASSERT_TRUE(p2->isAvailable(400, 600));
    ASSERT_FALSE(p2->isAvailable(3, 1001));
}



int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
