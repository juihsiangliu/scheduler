#ifndef RESOURCE_H
#define RESOURCE_H

class Resource
{
    public:
        Resource(const char* buf);

    protected:
        int m_nStart;
        int m_nEnd;
};


#endif
