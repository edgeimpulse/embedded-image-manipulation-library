# Name of component under test
COMPONENT_NAME = eiml

# Dynamically generate absolute paths
# From https://matheusmbar.com/bugfree-robot/2019/04/05/makefile-first-test.html
MAKEFILE_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR = $(realpath $(MAKEFILE_DIR)../..)
TEST_DIR = $(PROJECT_DIR)/tests

# Location of CppUTest (if not already set)
CPPUTEST_HOME ?= $(PROJECT_DIR)/tools/cpputest

# Include and source files for component under test
INCLUDE_DIRS = $(PROJECT_DIR)/include
SRC_DIRS = $(PROJECT_DIR)/src

# Includes CppUTest header files
INCLUDE_DIRS += $(CPPUTEST_HOME)/include

# Directories containing the unit tests
TEST_SRC_DIRS = $(TEST_DIR)/unit-tests

# Run MakefileWorker.mk with the variables set in this Makefile
include $(CPPUTEST_HOME)/build/MakefileWorker.mk