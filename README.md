# C++ Piscine: C to C++ and OOP

This repository is an introduction to C++ after C. It focuses on the core
Object-Oriented Programming concepts covered in the C++ Piscine:

- **Classes and encapsulation**: keep state private and expose behavior through
  methods.
- **Orthodox Canonical Form**: implement a default constructor, copy
  constructor, copy assignment operator, and destructor when ownership or
  copying needs to be handled explicitly.
- **References**: pass and return aliases with `&` while avoiding pointer syntax
  and ambiguous ownership.
- **Templates**: write type-independent classes and functions.
- **Inheritance**: reuse and specialize behavior through base and derived
  classes.
- **Polymorphism**: dispatch derived behavior through virtual methods and an
  abstract interface.

## Example

[`oop_intro.cpp`](oop_intro.cpp) combines these ideas in one small program:

- `Counter` demonstrates encapsulation and Orthodox Canonical Form.
- `Pair<T>` demonstrates a template class.
- `Shape` demonstrates abstract inheritance.
- `Rectangle` and `Circle` demonstrate virtual polymorphism.

Compile and run it with a C++98-compatible compiler:

```sh
c++ -Wall -Wextra -Werror -pedantic -std=c++98 oop_intro.cpp -o oop_intro
./oop_intro
```
