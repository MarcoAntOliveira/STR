#include <iostream>
#include <thread>

void thread_function()
{
 std::cout << "thread function\n";
}
int main()
{
 std::thread t(&thread_function);
 std::cout << "main thread\n";
 // t.join();
 if(t.joinable())
 t.join();
 return 0;
}


