# `arba-meta`

A C++ library providing meta programming features (policies, type traits, template helpers...).

# Install #
## Requirements ##

Binaries:

- A C++20 compiler (ex: g++-14)
- CMake 3.26 or later

Testing Libraries (optional):

- [Google Test](https://github.com/google/googletest) 1.14 or later (optional)

## Clone

```
git clone https://github.com/arapelle/arba-meta
```

## Use with `conan`

Create the conan package.
```
conan create . --build=missing -c
```
Add a requirement in your conanfile project file.
```python
    def requirements(self):
        self.requires("arba-meta/0.5.0")
```

## Quick Install ##
There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).
```
cd /path/to/arba-meta
cmake -P cmake/scripts/quick_install.cmake
```
Use the following to quickly install a different mode.
```
cmake -P cmake/scripts/quick_install.cmake -- TESTS BUILD Debug DIR /tmp/local
```

## Uninstall ##
There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.
```
cd /path/to/installed-arba-meta/
cmake -P uninstall.cmake
```

# How to use
## Example - A template function with default arguments managed thanks to `value_or_default()` and `value_or_generate()`.
```c++
#include <arba/meta/type_traits/value_or_default.hpp>
#include <arba/meta/type_traits/value_or_generate.hpp>
#include <arba/meta/version.hpp>
#include <cstdlib>
#include <iostream>

template <class ValueType, class OptionType>
std::string tfunc(const ValueType& input_value, OptionType& input_option)
{
    decltype(auto) value(meta::value_or_default(input_value, 531));
    decltype(auto) option(meta::value_or_generate(input_option, [] { return 642; }));
    std::string value_prefix = "D";
    std::string option_prefix = "D";

    if constexpr (!std::is_same_v<std::remove_cvref_t<ValueType>, meta::default_t>)
    {
        value_prefix = "V";
    }

    if constexpr (!std::is_same_v<std::remove_cvref_t<OptionType>, meta::default_t>)
    {
        option_prefix = "V";
        option += 1;
    }

    return std::format("{}{} {}{}", value_prefix, static_cast<int>(value), option_prefix, static_cast<int>(option));
}

int main()
{
    int option = 0;
    std::cout << tfunc(meta::default_v, meta::default_v) << " ; " << option << std::endl;
    std::cout << tfunc(meta::default_v, option) << " ; " << option << std::endl;
    std::cout << tfunc(42, option) << " ; " << option << std::endl;
    std::cout << "EXIT SUCCESS" << std::endl;
    return EXIT_SUCCESS;
}
```

# License

[MIT License](./LICENSE.md) © arba-meta
