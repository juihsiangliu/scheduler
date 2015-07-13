#ifndef RESOURCE_H
#define RESOURCE_H

#include <vector>

using std::vector;
using std::pair;

class Resource
{
    public:
        Resource(const char* buf);
        Resource(const Resource& src);
        Resource& operator=(const Resource& rhs);

        const char* getName() const {return m_pResourceName; }
        void addInterval(const Resource& src);


    protected:
        void _copyFrom(const Resource& src);
        char m_pResourceName[1024];

        // start, end
        vector<pair<int, int> > m_availableInterval;
};


class ResourceMgr
{
    public:
        void add(const char* buf);
    protected:
        std::vector<Resource> m_resourceAry;
};

#endif
