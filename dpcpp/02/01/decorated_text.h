#pragma once
#include <algorithm>
#include <iostream>
#include <string>

class Text {
public:
  virtual void render(const std::string &row) const { std::cout << row; }
};

class DecoratedText : public Text {
public:
  DecoratedText(Text *text) : text_(text) {}
  Text *text_;
};

class ItalicText : public DecoratedText {
public:
  ItalicText(Text *text) : DecoratedText(text) {}
  void render(const std::string &row) const override {
    std::cout << "<i>";
    text_->render(row);
    std::cout << "</i>";
  }
};

class BoldText : public DecoratedText {
public:
  BoldText(Text *text) : DecoratedText(text) {}
  void render(const std::string &row) const override {
    std::cout << "<b>";
    text_->render(row);
    std::cout << "</b>";
  }
};

class Paragraph : public DecoratedText {
public:
  Paragraph(Text *text) : DecoratedText(text) {}
  void render(const std::string &row) const override {
    std::cout << "<p>";
    text_->render(row);
    std::cout << "</p>";
  }
};

class Reversed : public DecoratedText {
public:
  Reversed(Text *text) : DecoratedText(text) {}
  void render(const std::string &row) const override {
    std::string reversed_row = row;
    std::reverse(reversed_row.begin(), reversed_row.end());
    text_->render(reversed_row);
  }
};

class Link : public DecoratedText {
public:
  Link(Text *text) : DecoratedText(text) {}
  void render(const std::string &url, const std::string &data) const {
    std::cout << "<a href=\"" << url << "\">";
    text_->render(data);
    std::cout << "</a>";
  }
};