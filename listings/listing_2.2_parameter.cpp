/*
 * Date: 
 * From: 
 * Category: 
 * Description: 
 *   std::thread transfer para by value by default
 *   use std::ref if you want to transfer non-const reference
 * Sample: 
 * Purpose: 
 * Test: 
 * Result: 
 * Comments: 
 */
#include <iostream>
#include <thread>

using namespace std;
struct widget_data {
  int x;
};

void f(int i, struct widget_data  &s) { std::cout << "executing f... " << std::endl; }

void oops(int some_para) {
  std::cout << "starting oops... " << std::endl;
  struct widget_data wd;
//   sprintf(buffer, "%i", some_para);
  std::thread t(f, 3, std::ref(wd));
  t.detach();
  std::cout << "ending oops... " << std::endl;
}

int main() { oops(123); }
