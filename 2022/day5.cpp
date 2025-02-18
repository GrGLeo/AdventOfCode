

#include <map>
#include <stdexcept>
class Stack {
  private:
    static const int MAX = 1000;
    char arr[MAX];
    int top;


  public:
    Stack(): top(-1) {};

    void push(char x) {
      if (top >= MAX) {
        throw std::overflow_error("Stack overflow");
      }
      arr[++top] = x;
    }

    char pop() {
      if (top < 0) {
        throw std::underflow_error("Stack underflox");
      }
      return arr[top--];
    }


    char peek() const {
      if (top < 0) {
        throw std::underflow_error("Stack is empty");
      }
      return arr[top];
    }

    bool isEmpty() const {
      return top < 0;
    }
};


int main() {
  std::map<char, Stack> stackMap;
  std::map<char, std::string> initStack;
  initStack['1'] = "SMRNWJVT";
  initStack['2'] = "BWDJQPC";
  initStack['3'] = "BJFHDRP";
  initStack['4'] = "FRPBMND";
  initStack['5'] = "HVRPTB";
  initStack['6'] = "CBPT";
  initStack['7'] = "BJRPL";
  initStack['8'] = "NCSLTZBW";
  initStack['9'] = "LSG";

  for (const auto& pair : initStack) {
    for (char ch : pair.second) {
      stackMap[pair.first].push(ch);
    }


    
  }
  return 0;

}
