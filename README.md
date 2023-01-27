# Embedded Image Manipulation Library

> WORK IN PROGRESS!

## Running unit tests locally

Install dependencies (Linux):

```bash
sudo apt install autoconf automake libtool
```

Or on macOS:

```bash
brew install autoconf automake libtool
```

Then build CppUTest from source:

```bash
mkdir tools
wget https://github.com/cpputest/cpputest/releases/download/v4.0/cpputest-4.0.tar.gz
tar xf cpputest-4.0.tar.gz
mv cpputest-latest/ tools/cpputest/
cd tools/cpputest/
autoreconf -i
./configure
make
cd ../..
```

Run unit tests:

```bash
cd tests/unit-tests/
make
```

Note: CppUTest might fail on newer macOS versions. Recommend copying the latest [MakefileWorker.mk](https://github.com/cpputest/cpputest/blob/master/build/MakefileWorker.mk) to cpputest/build/MakefileWorker.mk. You also need .c source files, as CppUTest generates .a files for all source. As such, there is a dummy .c file in *src/* that is only needed for CppUTest.

## Running Doxygen locally

Install Doxygen (Linux):

```basg
sudo apt install doxygen
```

Or on macOS:

```bash
brew install doxygen
```

Settings are found in *Doxyfile*. From the top-level directory of this project, run:

```bash
doxygen
```

