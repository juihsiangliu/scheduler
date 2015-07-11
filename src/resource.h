#ifndef RESOURCE_H
#define RESOURCE_H

#include <vector>

using std::vector;

class Resource
{
    public:
        Resource(const char* buf);
        Resource(const Resource& src);
        Resource& operator=(const Resource& rhs);

    protected:
        void _copyFrom(const Resource& src);
        char m_pResourceName[1024];
        int m_nStart;
        int m_nEnd;
};


class ResourceMgr
{
    public:
        void add(const char* buf);
    protected:
        std::vector<Resource> m_resourceAry;
};

#endif
