#!/usr/bin/env python3
"""
Compiles and runs the EIML unit tests. Reports on unit test pass/fails.

Copyright (c) 2023 EdgeImpulse Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

import os, subprocess

# Settings
TEST_DIR = "."              # Directory with our program
CODE_FILE = "main.c"        # Unit test main
APP_FILE = "app.elf"        # Output executable
COMPILER_TIMEOUT = 10.0     # Compiler timeout (seconds)
RUN_TIMEOUT = 10.0          # Run timeout (seconds)

# Create paths
code_path = os.path.join(TEST_DIR, CODE_FILE)
app_path = os.path.join(TEST_DIR, APP_FILE)

# Compile the program
print("Building...")
try:
        ret = subprocess.run(["gcc", code_path, "-o", app_path],
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                timeout=COMPILER_TIMEOUT)
except Exception as e:
    print("ERROR: Compilation failed.", str(e))
    exit(1)
    
# Parse output
output = ret.stdout.decode('utf-8')
print(output)
output = ret.stderr.decode('utf-8')
print(output)

# Check to see if the program compiled successfully
if ret.returncode != 0:
    print("Compilation failed.")
    exit(1)
    
# Run the compiled program
print("Running...")
try:
    ret = subprocess.run([app_path],
                            stdout=subprocess.PIPE,
                            timeout=RUN_TIMEOUT)
except Exception as e:
    print("ERROR: Runtime failed.", str(e))
    exit(1)
    
# Parse output
output = ret.stdout.decode('utf-8')
print("Output:", output)

# All tests passed! Exit gracefully
print("All tests passed!")
exit(0)