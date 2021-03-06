#ifndef RESOURCE_H
#define RESOURCE_H

#include <vector>

using std::vector;
using std::pair;

class Resource
{
    public:
        Resource();
        Resource(const Resource& src);
        Resource& operator=(const Resource& rhs);

        const char* getName() const { return m_pResourceName; }
        void unionIntervalFrom(const Resource* src);
        bool isAvailable(int startTime, int endTime) const;
        void addInterval(int startTime, int endTime);

        bool parse(const char* buf);
    protected:
        void _copyFrom(const Resource& src);

        // start, end
        vector<pair<int, int> > m_availableInterval;
        char m_pResourceName[1024];
};


class ResourceMgr
{
    public:
        ~ResourceMgr();
        void add(const char* buf);
        Resource* getResourceByName(const char* name) const;
    protected:
        std::vector<Resource*> m_resourceAry;
};

#endif
