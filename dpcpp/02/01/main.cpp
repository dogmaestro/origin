#include <iostream>
#include "decorated_text.h"

int main() {

  auto text_block1 = new Paragraph(new Text());
  text_block1->render("Hello world");
  delete text_block1;
  std::cout << std::endl;

  auto text_block2 = new Reversed(new Text());
  text_block2->render("Hello world");
  delete text_block2;
  std::cout << std::endl;

  auto text_block3 = new Link(new Text());
  text_block3->render("netology.ru", "Hello world");
  delete text_block3;
  std::cout << std::endl;

  return 0;
}
