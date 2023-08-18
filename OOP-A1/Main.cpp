#include "Task.h"     // to use Task class
#include "TaskList.h" // to use TaskList class
#include <iostream>   // to use objects std::cout and std::cin
#include <cassert>    // to use function assert()

int main()
{
    TaskList todos;

    auto test_time{ std::chrono::system_clock::now() };

    test_time += std::chrono::days(1); // tomorrow

    Task task1{ "Buy a milk", Task::PRIORITY::NORMAL, test_time };

    todos.add_task(task1);
    assert(1 == todos.get_tasks_count());

    test_time -= std::chrono::days(2); // yesterday

    todos.add_task(Task{ "Buy a bread", Task::PRIORITY::HIGH, test_time });
    assert(2 == todos.get_tasks_count());

    // Shows all tasks
    std::cout << "All tasks\n====================\n";
    todos.send_to(std::cout);

    // Shows due tasks only
    std::cout << "Due tasks\n====================\n";

    auto is_due{ [](auto&& task) { return task.is_due(); } };

    todos.send_to(std::cout, is_due);

    std::cout << "Completing 1st task ...\n\n";
    todos.complete_task(0);
    assert(!todos.task_is_due(0));

    std::cout << "Due tasks\n====================\n";
    todos.send_to(std::cout, is_due);

    // Removes done tasks (must be implemented)
    todos.remove_done_tasks();

    // Uncomment the next two lines to pause before the program exits:
    //std::cout << "Press Return/Enter key...";
    //std::cin.get(); // wait for the Enter key

    return 0;
} 