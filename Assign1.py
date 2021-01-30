import os

path = r'C:\random'

def directory(path,s,extra = ''):
    obj = os.scandir(path)
    
    for entry in obj : 
        if entry.is_dir():
            if extra != '':
                path = path.replace(extra,'')
            print("_" * s,end="")
            print("|--"+entry.name)
            path = os.path.join(path,entry.name)
            extra = '\\'+ entry.name
            directory(path,s+1,extra)
        else:
            print("_" * s,end="")
            print("|--"+entry.name)


directory(path,1)
    

       
    