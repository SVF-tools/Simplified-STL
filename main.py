# Main entry point to get a whole program llvm IR using wllvm (https://github.com/travitch/whole-program-llvm)

import os

# get github project link
project = input("Enter link to project: ")
print(project)

# make a new project folder for the user's project
os.system("mkdir cpp-project")
os.chdir("cpp-project")     #change the current working directory to specified path
# download the github project as a zip file called "master.zip"
os.system("wget " + project + "/archive/master.zip")
# make a new dir for the extracted files
os.system("mkdir extracted-files")
os.system("unzip -q -j master.zip -d ./extracted-files")
os.system("mkdir build")
os.chdir("build")

# set up environment for wllvm
os.environ["LLVM_COMPILER"] = "clang"
os.system("CC=wllvm CXX=wllvm++ cmake ../extracted-files/")