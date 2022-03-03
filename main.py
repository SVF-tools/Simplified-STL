# Main entry point to get a whole program llvm IR using wllvm (https://github.com/travitch/whole-program-llvm)
import os

# get github project link
project = input("Enter link to project: ")
simplestl_location = input("Enter the path to the SimplifiedSTL directory (if you are already in it, just press '.'): ")
if simplestl_location == ".":
    simplestl_location = os.getcwd()
print(project)
print(simplestl_location)

# make a new project folder for the user's project
os.system("mkdir cpp-project")
os.chdir("cpp-project")     #change the current working directory to specified path
# download the github project as a zip file called "master.zip"
os.system("wget " + project + "/archive/master.tar.gz")
# make a new dir for the extracted files
os.system("mkdir extracted-files")
#os.system("unzip -q -j master.zip -d ./extracted-files")
os.system("tar xf master.tar.gz -C extracted-files --strip-components 1")
# make project in this directory
os.system("mkdir build")
os.chdir("build")

# set up environment for wllvm
os.environ["LLVM_COMPILER"] = "clang"
os.system("CC=wllvm CXX=wllvm++ cmake ../extracted-files/")

# save result of make command to a txt file as a preprocessing step
os.system("make > makeOutput.txt")
# search for the built target file name in txt file. The whole program bitcode module will be made from this
target_file = open(("{}/cpp-project/build/makeOutput.txt".format(simplestl_location)))
# search for line in the file that indicates the built target file
for line in target_file:
    if "[100%] Built target" in line:
            target_line = line
target_file.close()
