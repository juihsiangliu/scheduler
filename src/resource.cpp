#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "resource.h"



Resource::Resource(const char* p_pBuf)
{
    memset(m_pResourceName, 0, 1024 * sizeof(char));

    char buf[1024];
    strcpy(buf, p_pBuf);

    char* pattern = strtok(buf, ",");
    strcpy(m_pResourceName, pattern);
    printf("resource %s\n", m_pResourceName);

    pair<int, int> p;
    int* period[2] = {&p.first, &p.second};
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


void Resource::addInterval(const Resource* src)
{
    if (strcmp(src->getName(), getName()) != 0) {
        assert(0);
        return;
    }

    for (int i = 0; i < src->m_availableInterval.size(); i++) {
        bool find = false;
        for (int j = 0; j < m_availableInterval.size(); j++) {
            if (m_availableInterval[j] == src->m_availableInterval[i]) {
                find = true;
                break;
            }
        }
        if (find) {
            continue;
        }

        m_availableInterval.push_back(src->m_availableInterval[i]);
    }
}


void Resource::_copyFrom(const Resource& src)
{
    strcpy(m_pResourceName, src.m_pResourceName);

    for (int i = 0; i < src.m_availableInterval.size(); i++) {
        pair<int, int> p;
        p.first = src.m_availableInterval[i].first;
        p.second = src.m_availableInterval[i].second;
        m_availableInterval.push_back(p);
    }
}




void ResourceMgr::add(const char* buf)
{
    Resource *ptr = new Resource(buf);

    for (int i = 0; i < m_resourceAry.size(); i++) {
        if (strcmp(m_resourceAry[i]->getName(), ptr->getName()) == 0) {
            m_resourceAry[i]->addInterval(ptr);
            return;
        }
    }

    m_resourceAry.push_back(ptr);
}


Resource* ResourceMgr::getResouceByName(const char* name) const
{
    for (int i = 0; i < m_resourceAry.size(); i++) {
        if (strcmp(name, m_resourceAry[i]->getName()) == 0) {
            return m_resourceAry[i];
        }
    }

    return NULL;
}


ResourceMgr::~ResourceMgr()
{
    for (int i = 0; i < m_resourceAry.size(); i++) {
        Resource* ptr = m_resourceAry[i];
        delete ptr;
    }
}
