#include <iostream>
#include <magic_enum/magic_enum.hpp>

// >>>> THIS CAUSES CRASH <<<<
using namespace magic_enum::bitwise_operators;

// >>> NOW INCLUDE PROTOBUF <<<
#include "example.pb.h"
#include <google/protobuf/message.h>

int main() {
  std::cout << "Creating protobuf message..." << std::endl;

  example::Person person;
  person.set_name("John Doe");
  person.set_id(123);
  person.set_email("john.doe@example.com");

  std::cout << "Person created successfully!" << std::endl;
  std::cout << "Name: " << person.name() << std::endl;
  std::cout << "ID: " << person.id() << std::endl;
  std::cout << "Email: " << person.email() << std::endl;

  // Create an AddressBook with the person
  example::AddressBook address_book;
  auto *new_person = address_book.add_people();
  *new_person = person;

  std::cout << "AddressBook created with " << address_book.people_size()
            << " person(s)" << std::endl;

  return 0;
}