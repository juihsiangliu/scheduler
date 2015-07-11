#ifndef TASK_H
#define TASK_H


class Task
{
    public:
        Task(const char* buf);

    protected:
        int taskId;
        char task_title[1024];

};



#endif
