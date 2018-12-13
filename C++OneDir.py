from shutil import copyfile
import os
import sys

def changeDir(path):
    os.chdir(path)


def checkIfExsists(path):
    if not os.path.exists(path):
        os.makedirs(path)



def getListOfAllFilesPaths():
    listOfFiles = {}
    for subdir,dirs,files in os.walk(os.getcwd()):
        for file in files:
            if file.__contains__(".cpp") or file.__contains__(".h"):
                listOfFiles[os.path.join(subdir,file)] = file

    return listOfFiles


def copyFilesToOneDir(listOfFiles):
    for key in listOfFiles:
        srcFileDir = os.path.join(os.getcwd(), listOfFiles[key])
        copyfile(key,srcFileDir)



def createCOneDirFile():
    if len(sys.argv) >= 4 or len(sys.argv) == 1:
        print("Only one argument is needed")
    else:
        srcDir = sys.argv[1]
        destDir = srcDir+"/"+sys.argv[2]
        print(sys.argv)
        changeDir(srcDir)

        listOfFiles = getListOfAllFilesPaths()

        checkIfExsists(destDir)
        changeDir(destDir)

        copyFilesToOneDir(listOfFiles)
        print("Files copied")



createCOneDirFile()

