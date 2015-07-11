#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "resource.h"



Resource::Resource(const char* p_pBuf)
: m_nStart(0), m_nEnd(0)
{
    memset(m_pResourceName, 0, 1024 * sizeof(char));

    char buf[1024];
    strcpy(buf, p_pBuf);

    char* pattern = strtok(buf, ",");
    strcpy(m_pResourceName, pattern);
	printf("resource %s\n", m_pResourceName);

    int* period[2] = {&m_nStart, &m_nEnd};
    for (int i = 0; i < 2; i++) {
        pattern = strtok(NULL, ",");
        *period[i] = atoi(pattern);
        printf("\t %d", *period[i]);
    }
    printf("\n");
}


Resource::Resource(const Resource& src)
{
    _copyFrom(src);
}


Resource& Resource::operator=(const Resource& src)
{
    _copyFrom(src);
    return *this;
}


void Resource::_copyFrom(const Resource& src)
{
    strcpy(m_pResourceName, src.m_pResourceName);
    m_nStart = src.m_nStart;
    m_nEnd = src.m_nEnd;
}




void ResourceMgr::add(const char* buf)
{
    Resource obj(buf);
    m_resourceAry.push_back(obj);
}
