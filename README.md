# Embedded Image Manipulation Library

>> WORK IN PROGRESS!

## Running unit tests locally

Install dependencies (Linux):

```
sudo apt install autoconf automake libtool
```

Or on macOS:

```
brew install autoconf automake libtool
```

Then build CppUTest from source:

```
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

```
cd tests/unit-tests/
make
```

Note: CppUTest might fail on newer macOS versions. Recommend copying the latest [MakefileWorker.mk](https://github.com/cpputest/cpputest/blob/master/build/MakefileWorker.mk) to cpputest/build/MakefileWorker.mk.