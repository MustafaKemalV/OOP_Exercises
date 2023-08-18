#include "TaskList.h"

void TaskList::add_task(Task task)
{
    // TODO: For additional point try to provide the verification and
    // do not append new task to the _tasks if provided deadline refers
    // to the past date/time.
    // If done, remove these TODO comment lines.

    _tasks.push_back(task);
}

void TaskList::complete_task(size_t i)
{
    if (!_tasks[i].is_done())
        _tasks[i].toggle_done();
}

bool TaskList::task_is_due(size_t i) const
{
    return _tasks[i].is_due();
}

void TaskList::send_to(std::ostream& out, std::function<bool(const Task&)> filter) const
{
    for (auto&& task : _tasks)
        if (filter(task))
            out << (std::string)task << "\n";
}

void TaskList::remove_done_tasks()
{
    // TODO: For additional point try to provide the solution that cleans up
    // container _tasks from already finished tasks.
    // Hint: Try to apply C++20 erase_if algorithm
    // (https://en.cppreference.com/w/cpp/container/vector/erase2).
    // If done, remove these TODO comment lines.

}