#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "task.h"

Task::Task(ResourceMgr* resourceMgr)
: m_pResourceMgr(resourceMgr), m_nTaskId(0), m_nNeedResourceCnt(0), m_nStartNoEarlierThan(0),
  m_nDueNoLaterThan(0), m_nDuration(0)
{
}
        
Task::Task(const Task& src)
{
    _copyFrom(src);
}


Task& Task::operator=(const Task& src)
{
    _copyFrom(src);
    return *this;
}

void Task::_copyFrom(const Task& src)
{
    m_pResourceMgr = src.m_pResourceMgr;
    m_nTaskId = src.m_nTaskId;
    strcpy(m_pTaskTitle, src.m_pTaskTitle);
    m_nNeedResourceCnt = src.m_nNeedResourceCnt;
    m_nStartNoEarlierThan = src.m_nStartNoEarlierThan;
    m_nDueNoLaterThan = src.m_nDueNoLaterThan;
    m_nDuration = src.m_nDuration;


    for (size_t i = 0; i < src.m_pRequiredResource.size(); i++) {
        m_pRequiredResource.push_back(src.m_pRequiredResource[i]);
    }
    
    for (size_t i = 0; i < src.m_pOptionalResource.size(); i++) {
        m_pOptionalResource.push_back(src.m_pOptionalResource[i]);
    }
    
    for (size_t i = 0; i < src.m_pPreRequiredTask.size(); i++) {
        m_pPreRequiredTask.push_back(src.m_pPreRequiredTask[i]);
    }
    
    for (size_t i = 0; i < src.m_pEquivalentTask.size(); i++) {
        m_pEquivalentTask.push_back(src.m_pEquivalentTask[i]);
    }
}
