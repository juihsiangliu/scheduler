#ifndef TASK_H
#define TASK_H

#include <vector>

using std::vector;

class ResourceMgr;
class Resource;

class Task
{
    public:
        Task(const char* buf, ResourceMgr* resourceMgr);

    protected:
        ResourceMgr* m_pResourceMgr;
        int m_nTaskId;
        char m_taskTitle[1024];
        
        vector<Task> m_preRequiredTask;
};



#endif
