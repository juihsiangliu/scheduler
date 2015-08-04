#ifndef TASK_H
#define TASK_H

#include <vector>

using std::vector;

class ResourceMgr;
class Resource;

class Task
{
    public:
        Task(ResourceMgr* resourceMgr);
        Task(const Task& src);
        ~Task();
        Task& operator=(const Task& src);

        bool parse(const char* buf);


    protected:
        void _copyFrom(const Task& src);

        ResourceMgr* m_pResourceMgr;
        int m_nTaskId;
        char m_pTaskTitle[1024];
        int m_nNeedResourceCnt;
        int m_nStartNoEarlierThan;
        int m_nDueNoLaterThan;
        int m_nDuration;
       
        
        vector<Resource*> m_pRequiredResource;
        vector<Resource*> m_pOptionalResource;
        vector<Task*> m_pPreRequiredTask;
        vector<Task*> m_pEquivalentTask;
};



#endif
