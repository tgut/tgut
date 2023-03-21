#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

class ResourceOwner {
public:
  ResourceOwner(const char res[]) {
    theResource = new string(res);
  }

  ResourceOwner(const ResourceOwner& other) {
    printf("copy %s\n", other.theResource->c_str());
    theResource = new string(other.theResource->c_str());
  }

  ResourceOwner& operator=(const ResourceOwner& other) {
    ResourceOwner tmp(other);
    swap(theResource, tmp.theResource);
    printf("assign %s\n", other.theResource->c_str());
  }

  ~ResourceOwner() {
    if (theResource) {
      printf("destructor %s\n", theResource->c_str());
      delete theResource;
    }
  }
private:
  string* theResource;
};

void testCopy() {
 // case 1
  printf("=====start testCopy()=====\n");
  ResourceOwner res1("res1");
  ResourceOwner res2 = res1;
  //copy res1
  printf("=====destructors for stack vars, ignore=====\n");
}

void testAssign() {
 // case 2
  printf("=====start testAssign()=====\n");
  ResourceOwner res1("res1");
  ResourceOwner res2("res2");
  res2 = res1;
 //copy res1, assign res1, destrctor res2
  printf("=====destructors for stack vars, ignore=====\n");
}

void testRValue() {
 // case 3
  printf("=====start testRValue()=====\n");
  ResourceOwner res2("res2");
  res2 = ResourceOwner("res1");
 //copy res1, assign res1, destructor res2, destructor res1
  printf("=====destructors for stack vars, ignore=====\n");
}

int main() {
  testCopy();
  testAssign();
  testRValue();
}