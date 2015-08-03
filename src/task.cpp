#include "task.h"

Task::Task(ResourceMgr* resourceMgr)
: m_pResourceMgr(resourceMgr), m_nTaskId(0), m_nNeedResourceCnt(0), m_nStartNoEarlierThan(0),
  m_nDueNoLaterThan(0), m_nDuration(0)
{
}
        
Task::Task(const Task& src)
{
}
