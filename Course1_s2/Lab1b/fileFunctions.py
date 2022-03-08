import pickle

def writeFile(file, database):
    for i in range(len(database)):
        pickle.dump(database[i], file)

def readFile(file):
    database = []
    file.seek(0,2)
    file_size = file.tell()
    file.seek(0,0)
    while file.tell()<file_size:
        database.append(pickle.load(file))
    return database



