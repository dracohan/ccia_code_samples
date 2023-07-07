/*
 * Date:
 * From:
 * Category:
 * Description:
 *   store thread in vector
 * Sample:
 * Purpose:
 * Test:
 * Result:
 * Comments:
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void do_work(unsigned id) {
  std::cout << "execute: " << id << std::endl;
  std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
}

void f() {
  std::vector<std::thread> threads;
  for (unsigned i = 0; i < 20; ++i) {
    threads.push_back(std::thread(do_work, i));
  }
  std::for_each(threads.begin(), threads.end(),
                std::mem_fn(&std::thread::join));

  std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
}

int main() { f(); }
