# PointerNames
Give your c/c++ pointers names.
### About
This tool will offer you functions to map every pointer address to a name to give you redable and maby more important compareable output.

### Installation
##### 1.
Look in the release. There will be a PointerNames.h file. Download it and place it into your project and you are ready to include it.
If you want the latest development version look in the src directory.
##### 2.
Clone the project and use cmake for installation, see bash example below:
``` bash
git clone http://github.com/NikBenson/pointerNames.git
cd pointerNames
mkdir build
cd build
cmake ..
make
sudo make install
```

### How to use it?
Include the header, depending on your installation it will be `#include <PointerNames>` or `#include "path/to/header/PointerNames.h"`.
Than just call the setPointerToNamesList(char\[\]\[16\]) to initialise the framework with default or custom names and you are ready to use the getPointerName(void*) function.

For more information look in the wiki.
